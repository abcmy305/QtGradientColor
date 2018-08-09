#ifndef GRADIENTUTILS_H
#define GRADIENTUTILS_H

#include <QtGui/QGradient>
#include <QtGui/QPainter>

class QtGradientManager;

class QtGradientUtils
{
public:
	static QString styleSheetCode(const QGradient &gradient);
	// utils methods, they could be outside of this class
	static QString saveState(const QtGradientManager *manager);
	static void restoreState(QtGradientManager *manager, const QString &state);

	static QPixmap gradientPixmap(const QGradient &gradient, const QSize &size = QSize(64, 64), bool checkeredBackground = false);

};

#endif
