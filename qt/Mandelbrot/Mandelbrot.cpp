#include "Mandelbrot.h"
#include "minelabel.h"
#include <qpixmap.h>
#include <qimage.h>
#include <qfiledialog.h>
#include <cmath>
#include <omp.h>


Mandelbrot::Mandelbrot(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->ui.pushButton->setText("Hellow");
    connect(ui.pushButton, &QPushButton::clicked, this, &Mandelbrot::ckickmepzl);
    ui.pushButton->setText("Return to 100% size");
    connect(ui.pushButton_2, &QPushButton::clicked, this, &Mandelbrot::drawFunction);
    connect(ui.horizontalSlider, &QSlider::valueChanged, this, &Mandelbrot::polzunok);

    list << new QLabel("",this); list << new QLabel("", this); list << new QLabel("", this); // add labels
    list[0]->setFrameShape(QFrame::Box);
    list[0]->setVisible(false);
    QFont tfont("MS Gothic",8);
    list[1]->setFont(tfont);
    list[2]->setFont(tfont);

    ui.label->setFrameShape(QFrame::Box);
    connect(ui.label, SIGNAL(Mouse_Pressed()), this, SLOT(Mouse_Pressed()));
    connect(ui.label, SIGNAL(Mouse_Move()), this, SLOT(Mouse_Move()));
    connect(ui.label, SIGNAL(Mouse_Up()), this, SLOT(Mouse_Up()));

}
void Mandelbrot::ckickmepzl()
{
    this->xmin = -2.0, this->lx = 2.5, this->ymax = 1.5, this->ly = 3;
    drawFunction();
}
void Mandelbrot::HSVintoRGB(int H, const int S, const int V, int& R, int& G, int& B, const int DrawIndex)
{
    if (DrawIndex != 0) { H = 360 - H; }
    int Hi = (int)(H / 60);
    Hi = (int)fmod(Hi, 6);
    double Vmin = ((100 - S) * V) / (100);
    double a = (V - Vmin) * (fmod(H, 60)) / 60;
    double Vinc = Vmin + a;
    double Vdec = V - a;

    if (Hi == 0) { R = (int)(255 * V / 100); G = (int)(255 * Vinc / 100); B = (int)(255 * Vmin / 100); }
    else if (Hi == 1) { R = (int)(255 * Vdec / 100); G = (int)(255 * V / 100); B = (int)(255 * Vmin / 100); }
    else if (Hi == 2) { R = (int)(255 * Vmin / 100); G = (int)(255 * V / 100); B = (int)(255 * Vinc /    100); }
    else if (Hi == 3) { R = (int)(255 * Vmin / 100); G = (int)(255 * Vdec / 100); B = (int)(255 * V / 100); }
    else if (Hi == 4) { R = (int)(255 * Vinc / 100); G = (int)(255 * Vmin / 100); B = (int)(255 * V / 100); }
    else if (Hi == 5) { R = (int)(255 * V / 100); G = (int)(255 * Vmin / 100); B = (int)(255 * Vdec / 100); }
}
void Mandelbrot::drawFunction()
{
    int n = ui.label->width(), m = ui.label->height();
    QImage image = QImage(n, m, QImage::Format_RGB32);
    const int abbs = 32; //Модуль числа
    int MaxIter = 360; // Количество итераций
    int clrRed, clrGreen, clrBlue, Iter = 0;
#pragma omp parallel for default(none) private(Iter) shared(image)  
    for (int i=0; i<n; i++)
    {
        double x = xmin + (double(i) / n) * lx;
        for (int j=0; j<m;j++)
        {
            double y = ymax - (double(j)/m)*ly,a = x, b = y;
            double a1, b1;
            Iter = 0;
            do
            {
                Iter++;
                a1 = a * a - b * b + x;
                b1 = 2 * a * b + y;
                if (((a1 - x) * (a1 - x) + (b1 - y) * (b1 - y)) > abbs) break;
                Iter++;
                a = a1 * a1 - b1 * b1 + x;
                b = 2 * a1 * b1 + y;
                if (((a - x) * (a - x) + (b - y) * (b - y)) > abbs) break;
            } while (Iter < MaxIter);
            HSVintoRGB(240*(1-erf(2.0*double((double(Iter)/MaxIter)))),85, 25*(4.0 - double(double(Iter) / MaxIter)), clrRed, clrGreen, clrBlue, 0);
            image.setPixel(i,j, qRgb(clrRed, clrGreen, clrBlue));
        }
    }
    ui.pushButton_2->setText("Ready");
    QPixmap pmap = QPixmap::fromImage(image);
    QPainter painter(&pmap);
    ui.label->setPixmap(pmap);

    list[0]->setVisible(false);
    list[1]->setText(""); list[2]->setText("");
}
void Mandelbrot::Mouse_Pressed()
{
    list[0]->setVisible(true);
    list[0]->setGeometry(0, 0, 0, 0);
}
void Mandelbrot::Mouse_Move()
{
    double koeff_k = double(ui.label->width()) / ui.label->height();
    double xmin = ui.label->x(), xmax = xmin + ui.label->width(), ymin = ui.label->y(), ymax = ymin + ui.label->height();
    double x0 = ui.label->posx + xmin, y0 = ui.label->posy+ymin;
    double x = ui.label->nposx + xmin;
    x < xmin ? x = xmin : x>xmax ? x = xmax: x=x;
    double dx = x-x0, dy = qAbs(dx) / koeff_k;
    ui.label->posy > ui.label->nposy ? dy = -dy : dy = dy;
    double y = y0 + dy;

    if (y < ymin) 
    {
        y = ymin;
        dx = (y-y0) * dx / dy;
        dy =  y-y0;
    }
    else if (y > ymax) 
    {
        y = ymax;
        dx = (y-y0) * dx / dy;
        dy = y-y0;
    }
    list[0]->setGeometry(qRound(x0 + dx * (dx < 0)), qRound(y0 + dy * (dy < 0)),qAbs(dx),qAbs(dy));
    
    if ((dx < 0) && (dy < 0)) 
    {
        list[0]->setStyleSheet("background-color: rgba(195, 30, 20, 0.35);");
        this->zoom = false;
    }
    else 
    {
        list[0]->setStyleSheet("background-color: rgba(255, 255, 255, 0.28);");
        this->zoom = true;
    }

}
void Mandelbrot::Mouse_Up()
{
    if (this->zoom) 
    {
        this->xmin += (list[0]->x() - ui.label->x()) * this->lx / ui.label->width();
        this->lx = (list[0]->width()) * this->lx / ui.label->width();
        this->ymax -= (list[0]->y() - ui.label->y()) * this->ly / ui.label->height();
        this->ly = (list[0]->height()) * this->ly / ui.label->height();
    }
    else 
    {
        this->xmin -= (list[0]->x() - ui.label->x()) * this->lx / (list[0]->width());
        this->lx *= double(ui.label->width()) / (list[0]->width());
        this->ymax += (list[0]->y() - ui.label->y()) * this->ly / (list[0]->height());
        this->ly *= double(ui.label->height()) /(list[0]->height());   
    }
   drawFunction();
}
void Mandelbrot::polzunok(){
    double a = double(ui.horizontalSlider->value()) / 100.0;
    QString str = QString("background-color: rgba(255, 255, 255, %1);").arg(a);
    list[0]->setStyleSheet(str);
}
Mandelbrot::~Mandelbrot() {
    for (int i = 0; i < 3; i++) delete list[i];
}   

