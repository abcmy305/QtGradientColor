
#ifndef QTCOLORBUTTON_H
#define QTCOLORBUTTON_H

#include <QtGui/QToolButton>

class QtColorButton : public QToolButton
{
    Q_OBJECT
    Q_PROPERTY(bool backgroundCheckered READ isBackgroundCheckered WRITE setBackgroundCheckered)
public:
    QtColorButton(QWidget *parent = 0);
    ~QtColorButton();

    bool isBackgroundCheckered() const;
    void setBackgroundCheckered(bool checkered);

    QColor color() const;

public slots:

    void setColor(const QColor &color);

signals:
    void colorChanged(const QColor &color);
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
#ifndef QT_NO_DRAGANDDROP
    void dragEnterEvent(QDragEnterEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dropEvent(QDropEvent *event);
#endif
private:
    QScopedPointer<class QtColorButtonPrivate> d_ptr;
    Q_DECLARE_PRIVATE(QtColorButton)
    Q_DISABLE_COPY(QtColorButton)
    Q_PRIVATE_SLOT(d_func(), void slotEditColor())
};

#endif
