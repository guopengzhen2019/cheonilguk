#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class Mybutton : public QPushButton
{
    Q_OBJECT
public:
    explicit Mybutton(QWidget *parent = nullptr);

signals:
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);

public slots:
};

#endif // MYBUTTON_H
