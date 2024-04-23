#pragma once

#include <QWidget>

class Lines : public QWidget {

  public:
    Lines(QWidget *parent = 0);

  protected:
    void paintEvent(QPaintEvent *event);
    void drawLines(QPainter *qp);
};
