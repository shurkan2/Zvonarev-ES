#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Mandelbrot.h"
#include <qpainter.h>


class Mandelbrot : public QMainWindow
{
    Q_OBJECT

public:
    double xmin = -2.0, lx = 2.5, ymax = 1.5, ly = 3;
    bool zoom = true;
    bool I_can_draw = false;
    Mandelbrot(QWidget *parent = Q_NULLPTR);

    void HSVintoRGB(int H, const int S, const int V, int& R, int& G, int& B, const int DrawIndex);
    ~Mandelbrot();
private slots:
    void ckickmepzl();
    void drawFunction();

    void Mouse_Pressed();
    void Mouse_Move();
    void Mouse_Up();

    void polzunok();
signals:
protected:
private:
    Ui::MandelbrotClass ui;
    QList<QLabel*> list;
};
