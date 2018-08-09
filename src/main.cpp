#include "gradientcolor.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	GradientColor w;
	w.show(); 
	a.exec();
}
