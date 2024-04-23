#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <partcle.h>
#include <PaintWidjet.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Particle *SetOfParticles = new Particle[1];


    int x0,y0,x1,y1;
    bool can=false;

public slots:
    void risovat();
    //void closing();
    void paintEvent(QPaintEvent *e);
    void temp();

private:
    Ui::MainWindow *ui;
    QPaintWidget *pwdgt;
};
#endif // MAINWINDOW_H
