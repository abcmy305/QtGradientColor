#include "gradientcolor.h"
#include "qtgradientviewdialog.h"
#include "qtgradientutils.h"
#include <QtGui/QGradient>
#include <QtCore/QFile>
#include <QtGui/QMessageBox>

GradientColor::GradientColor(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QFile defaultGradients(QLatin1String(":/trolltech/qtgradienteditor/Resources/defaultgradients.xml"));
	if (defaultGradients.open(QIODevice::ReadOnly)) 
	{
		QtGradientUtils::restoreState(gradientview.gradientManager(), QString::fromAscii(defaultGradients.readAll()));
		defaultGradients.close();
	}

	connect(ui.pbtn_colorPanel, SIGNAL(clicked()), this, SLOT(slotEditColor()));
	connect(ui.AboutQt, SIGNAL(clicked()), this, SLOT(slotAboutQt()));
	connect(ui.AboutThis, SIGNAL(clicked()), this, SLOT(slotAboutThis()));
}

GradientColor::~GradientColor()
{

}

void GradientColor::slotEditColor()
{
	QString gradientcode;
	bool ok;
	const QGradient grad = QtGradientViewDialog::getGradient(&ok, gradientview.gradientManager(), NULL);
	if (ok)
	{
		gradientcode = QtGradientUtils::styleSheetCode(grad);
		ui.textEdit_colorCode->append(gradientcode);
	}
}

void GradientColor::slotAboutQt()
{
	QMessageBox::aboutQt(this, QString("About QT"));
}
 
void GradientColor::slotAboutThis()
{
	QMessageBox::about(this, QString("About GradientColor"), QString("\n\nEdit color for QSS!\n\n"));
}
