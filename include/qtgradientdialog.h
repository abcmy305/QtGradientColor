#ifndef QTGRADIENTDIALOG_H
#define QTGRADIENTDIALOG_H

#include <QtGui/QDialog>

class QtGradientDialog : public QDialog
{
	Q_OBJECT
		Q_PROPERTY(QGradient gradient READ gradient WRITE setGradient)
		Q_PROPERTY(bool backgroundCheckered READ isBackgroundCheckered WRITE setBackgroundCheckered)
		Q_PROPERTY(bool detailsVisible READ detailsVisible WRITE setDetailsVisible)
		Q_PROPERTY(bool detailsButtonVisible READ isDetailsButtonVisible WRITE setDetailsButtonVisible)
public:
	QtGradientDialog(QWidget *parent = 0);
	~QtGradientDialog();

	void setGradient(const QGradient &gradient);
	QGradient gradient() const;

	bool isBackgroundCheckered() const;
	void setBackgroundCheckered(bool checkered);

	bool detailsVisible() const;
	void setDetailsVisible(bool visible);

	bool isDetailsButtonVisible() const;
	void setDetailsButtonVisible(bool visible);

	QColor::Spec spec() const;
	void setSpec(QColor::Spec spec);

	static QGradient getGradient(bool *ok, const QGradient &initial, QWidget *parent = 0, const QString &caption = QString());
	static QGradient getGradient(bool *ok, QWidget *parent = 0, const QString &caption = QString());

private:
	QScopedPointer<class QtGradientDialogPrivate> d_ptr;
	Q_DECLARE_PRIVATE(QtGradientDialog)
		Q_DISABLE_COPY(QtGradientDialog)
		Q_PRIVATE_SLOT(d_func(), void slotAboutToShowDetails(bool details, int extensionWidthHint))
};

#endif
