#include "Mandelbrot.h"
//#include "minelabel.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mandelbrot w;
    w.show();
    return a.exec();
}
