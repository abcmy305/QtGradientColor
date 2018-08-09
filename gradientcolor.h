#ifndef GRADIENTCOLOR_H
#define GRADIENTCOLOR_H

#include <QWidget>
#include "ui_gradientcolor.h"
#include "qtgradientview.h"

class GradientColor : public QWidget
{
	Q_OBJECT

public:
	GradientColor(QWidget *parent = 0);
	~GradientColor();

public slots:
	void slotEditColor(void);
	void slotAboutThis(void);
	void slotAboutQt(void);

private:
	Ui::GradientColor ui;

	QtGradientView gradientview;
};

#endif // GRADIENTCOLOR_H
