#ifndef QTGRADIENTEDITOR_H
#define QTGRADIENTEDITOR_H

#include <QtGui/QWidget>

class QtGradientEditor : public QWidget
{
	Q_OBJECT
		Q_PROPERTY(QGradient gradient READ gradient WRITE setGradient)
		Q_PROPERTY(bool backgroundCheckered READ isBackgroundCheckered WRITE setBackgroundCheckered)
		Q_PROPERTY(bool detailsVisible READ detailsVisible WRITE setDetailsVisible)
		Q_PROPERTY(bool detailsButtonVisible READ isDetailsButtonVisible WRITE setDetailsButtonVisible)
public:
	QtGradientEditor(QWidget *parent = 0);
	~QtGradientEditor();

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

signals:

	void gradientChanged(const QGradient &gradient);
	void aboutToShowDetails(bool details, int extenstionWidthHint);

private:
	QScopedPointer<class QtGradientEditorPrivate> d_ptr;
	Q_DECLARE_PRIVATE(QtGradientEditor)
		Q_DISABLE_COPY(QtGradientEditor)
		Q_PRIVATE_SLOT(d_func(), void slotGradientStopsChanged(const QGradientStops &stops))
		Q_PRIVATE_SLOT(d_func(), void slotTypeChanged(int type))
		Q_PRIVATE_SLOT(d_func(), void slotSpreadChanged(int type))
		Q_PRIVATE_SLOT(d_func(), void slotStartLinearXChanged(double value))
		Q_PRIVATE_SLOT(d_func(), void slotStartLinearYChanged(double value))
		Q_PRIVATE_SLOT(d_func(), void slotEndLinearXChanged(double value))
		Q_PRIVATE_SLOT(d_func(), void slotEndLinearYChanged(double value))
		Q_PRIVATE_SLOT(d_func(), void slotCentralRadialXChanged(double value))
		Q_PRIVATE_SLOT(d_func(), void slotCentralRadialYChanged(double value))
		Q_PRIVATE_SLOT(d_func(), void slotFocalRadialXChanged(double value))
		Q_PRIVATE_SLOT(d_func(), void slotFocalRadialYChanged(double value))
		Q_PRIVATE_SLOT(d_func(), void slotRadiusRadialChanged(double value))
		Q_PRIVATE_SLOT(d_func(), void slotCentralConicalXChanged(double value))
		Q_PRIVATE_SLOT(d_func(), void slotCentralConicalYChanged(double value))
		Q_PRIVATE_SLOT(d_func(), void slotAngleConicalChanged(double value))
		Q_PRIVATE_SLOT(d_func(), void slotDetailsChanged(bool details))
		Q_PRIVATE_SLOT(d_func(), void startLinearChanged(const QPointF &))
		Q_PRIVATE_SLOT(d_func(), void endLinearChanged(const QPointF &))
		Q_PRIVATE_SLOT(d_func(), void centralRadialChanged(const QPointF &))
		Q_PRIVATE_SLOT(d_func(), void focalRadialChanged(const QPointF &))
		Q_PRIVATE_SLOT(d_func(), void radiusRadialChanged(qreal))
		Q_PRIVATE_SLOT(d_func(), void centralConicalChanged(const QPointF &))
		Q_PRIVATE_SLOT(d_func(), void angleConicalChanged(qreal))
};

#endif
