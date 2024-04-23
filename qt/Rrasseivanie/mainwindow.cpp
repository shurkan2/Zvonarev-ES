#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QThread>
#include <iostream>

Particle* particlesToDraw;
QPolygon polgn;
int count = 2;
int tmax = 500;
bool hi = false, can=false;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //pwdgt = new QPaintWidget(this);
    //ui->verticalLayout->addWidget(pwdgt);

    connect(ui->pushButton, &QPushButton::clicked,this,&MainWindow::risovat);
    connect(ui->pushButton_2, &QPushButton::clicked,this,&MainWindow::temp);
}

void MainWindow::temp()
{
    ui->textEdit_2->setText("Я (кнопка temp) был вызван");
    hi = true;
    repaint();
}

void MainWindow::risovat()
{
    count = 2;
    tmax = 10000;
    Particle *mass = new Particle[count];
    for(int i=0; i< count;i++){
        mass[i] = Particle();
    }
    mass[0] = Particle(350,227,10,0,0.01,1);
    //mass[1] = Particle(450,227,-10,0,0.01,0);
    mass[1] = Particle(285,376,0,0,0.01,-2);
    mass[3] = Particle(515,158,0,0,0.01,1);
    mass[4] = Particle(400,265,0,0,10,-1.6);

    ParticleProcessor m(mass,count);
    for(int t=0;t<tmax;t++) {
        m.process();

        for(int i=0;i<count;i++) {
            //Блок для отражения от стенок
            {
             if ((m.Pset[i].x>=800) or (m.Pset[i].x<=0)) m.Pset[i].set_vx(-m.Pset[i].get_vx());
             if ((m.Pset[i].y>=500) or (m.Pset[i].y<=0)) m.Pset[i].set_vy(-m.Pset[i].get_vy());
            }
            particlesToDraw = m.Pset;
            polgn << QPoint(m.Pset[i].x,m.Pset[i].y);
            can = true;
            repaint();
            //pwdgt->update();
        }
    }
    ui->textEdit_3->setText("Я всё cделяль");
}

MainWindow::~MainWindow()
{
    delete [] SetOfParticles;
    //delete[] ScreenData;
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    if (can)
    {
        can = false;
        QPainter qp(this);
        //qp.begin(ui->widget);
        QPen pen(Qt::black, 10, Qt::SolidLine);
        qp.setPen(pen);
        ui->textEdit->setText("");

        for(int i=0; i< count;i++) {
            qp.drawPoint(particlesToDraw[i].x,particlesToDraw[i].y);
            ui->textEdit->append('\n'+QString::number(particlesToDraw[i].v_x)+","+QString::number(particlesToDraw[i].v_y));
        }

        pen = QPen(Qt::green, 2, Qt::SolidLine);
        qp.setPen(pen);
        qp.drawLine(0,0,800,0);
        qp.drawLine(0,500,800,500);
        qp.drawLine(0,0,0,500);
        qp.drawLine(800,0,800,500);
        pen = QPen(Qt::gray, 2, Qt::SolidLine);
        qp.setPen(pen);
        qp.drawPoints(polgn);
    }
    else if (hi){
        hi = false;
        QPainter qp(this);
        QPen pen(Qt::gray, 2, Qt::SolidLine);
        qp.setPen(pen);
        qp.drawPoints(polgn);
    }
}
