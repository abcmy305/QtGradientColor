#ifndef GRADIENTVIEWDIALOG_H
#define GRADIENTVIEWDIALOG_H

#include <QtGui/QWidget>
#include <QtCore/QMap>
#include "ui_qtgradientviewdialog.h"

class QtGradientManager;

class QtGradientViewDialog : public QDialog
{
	Q_OBJECT
public:
	QtGradientViewDialog(QWidget *parent = 0);

	void setGradientManager(QtGradientManager *manager);
	QtGradientManager *gradientManager() const;

	static QGradient getGradient(bool *ok, QtGradientManager *manager, QWidget *parent = 0, const QString &caption = tr("Select Gradient", 0));

	private slots:
		void slotGradientSelected(const QString &id);
		void slotGradientActivated(const QString &id);

private:
	Ui::QtGradientViewDialog m_ui;
};

#endif

