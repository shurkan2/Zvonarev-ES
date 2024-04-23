#ifndef PAINTWIDJET_H
#define PAINTWIDJET_H
#ifndef QWidget
#include <QWidget>
#endif
class QPaintEvent;

class QPaintWidget : public QWidget
{
    Q_OBJECT
public:
    QPaintWidget(QWidget * parent = 0);
protected:
    //void paintEvent(QPaintEvent *);
};
#endif // PAINTWIDJET_H
