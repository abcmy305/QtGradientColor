#ifndef QTGRADIENTSTOPSWIDGET_H
#define QTGRADIENTSTOPSWIDGET_H

#include <QtGui/QAbstractScrollArea>

class QtGradientStopsModel;
class QtGradientStopsWidgetPrivate;

class QtGradientStopsWidget : public QAbstractScrollArea
{
    Q_OBJECT
    Q_PROPERTY(bool backgroundCheckered READ isBackgroundCheckered WRITE setBackgroundCheckered)
public:
    QtGradientStopsWidget(QWidget *parent = 0);
    ~QtGradientStopsWidget();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    bool isBackgroundCheckered() const;
    void setBackgroundCheckered(bool checkered);

    void setGradientStopsModel(QtGradientStopsModel *model);

    void setZoom(double zoom);
    double zoom() const;

signals:

    void zoomChanged(double zoom);

protected:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void focusInEvent(QFocusEvent *e);
    void focusOutEvent(QFocusEvent *e);
    void contextMenuEvent(QContextMenuEvent *e);
    void wheelEvent(QWheelEvent *e);
#ifndef QT_NO_DRAGANDDROP
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dropEvent(QDropEvent *event);
#endif

private:
    QScopedPointer<QtGradientStopsWidgetPrivate> d_ptr;
    Q_DECLARE_PRIVATE(QtGradientStopsWidget)
    Q_DISABLE_COPY(QtGradientStopsWidget)
    Q_PRIVATE_SLOT(d_func(), void slotStopAdded(QtGradientStop *stop))
    Q_PRIVATE_SLOT(d_func(), void slotStopRemoved(QtGradientStop *stop))
    Q_PRIVATE_SLOT(d_func(), void slotStopMoved(QtGradientStop *stop, qreal newPos))
    Q_PRIVATE_SLOT(d_func(), void slotStopsSwapped(QtGradientStop *stop1, QtGradientStop *stop2))
    Q_PRIVATE_SLOT(d_func(), void slotStopChanged(QtGradientStop *stop, const QColor &newColor))
    Q_PRIVATE_SLOT(d_func(), void slotStopSelected(QtGradientStop *stop, bool selected))
    Q_PRIVATE_SLOT(d_func(), void slotCurrentStopChanged(QtGradientStop *stop))
    Q_PRIVATE_SLOT(d_func(), void slotNewStop())
    Q_PRIVATE_SLOT(d_func(), void slotDelete())
    Q_PRIVATE_SLOT(d_func(), void slotFlipAll())
    Q_PRIVATE_SLOT(d_func(), void slotSelectAll())
    Q_PRIVATE_SLOT(d_func(), void slotZoomIn())
    Q_PRIVATE_SLOT(d_func(), void slotZoomOut())
    Q_PRIVATE_SLOT(d_func(), void slotResetZoom())
};

#endif
