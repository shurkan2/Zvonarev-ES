#include <partcle.h>
#include <cmath>

double Particle::get_x()
{
    return this->x;
}
double Particle::get_y()
{
   return this->y;
}
void Particle::set_x(double a)
{
    this->x = a;
}
void Particle::set_y(double a)

{
    this->y = a ;
}

double Particle::get_vx()
{
    return this->v_x;
}
double Particle::get_vy()
{
    return this->v_y;
}
void Particle::set_vx(double a)
{
    this->v_x = a;
}
void Particle::set_vy(double a)
{
    this->v_y = a;
}
Particle::Particle(double x, double y,double vx, double vy, double mass, double chardge ):x{x},y{y},v_x{vx},v_y{vy},mass{mass},chrg{chardge}{}
Particle::Particle(){}
Particle ParticleProcessor::calculations(int number)
{
    Particle res;
    res = Pset[number];
    double v_x0=this->Pset[number].v_x, v_y0=this->Pset[number].v_y, x0=this->Pset[number].x,y0=this->Pset[number].y;
    double k1, k2, k4, k3, h=0.05;
    double q1, q2, q4, q3;
    k1 = h * f_x(x0,number);
    q1 = h * v_x0;

    k2 = h * f_x(x0 + q1/2.0,number);
    q2 = h * v_x0;

    k3 = h * f_x(x0 + q2/2.0,number);
    q3 = h * v_x0;

    k4 = h * f_x(x0 + q3,number);
    q4 = h * v_x0;
    res.set_x(x0 + (q1 + 2.0*q2 + 2.0*q3 + q4)/6.0);
    res.set_vx (v_x0 + (k1 + 2.0*k2 + 2.0*k3 + k4)/6.0);
    //Порисуем для другого


    k1 = h * f_y(y0,number);
    q1 = h * v_y0;

    k2 = h * f_y(y0 + q1/2.0,number);
    q2 = h * v_y0;

    k3 = h * f_y(y0 + q2/2.0,number);
    q3 = h * v_y0;

    k4 = h * f_y(y0 + q3,number);
    q4 = h * v_y0;
    res.set_y(y0 + (q1 + 2.0*q2 + 2.0*q3 + q4)/6.0);
    res.set_vy(v_y0+(k1 + 2.0*k2 + 2.0*k3 + k4)/6.0);
    return res;
}

double ParticleProcessor::f_x(double x,int number) //Для проектирования без угла
{
    double sum=0;
    for(int i=0;i< nn ;i++)
    {
        if (i != number) {
        sum += Pset[number].chrg*Pset[i].chrg*(x-Pset[i].get_x()) / pow(pow(Pset[i].get_x() - x,2)+pow(Pset[i].get_y() - Pset[number].get_y(),2),(3/2));
        }
    }
    return sum/Pset[number].mass;
}

double ParticleProcessor::f_y(double y,int number) //Для проектирования без угла
{
    double sum=0;
    for(int i=0;i< nn ;i++)
    {
        if (i == number) continue;
        sum += Pset[number].chrg*Pset[i].chrg*(-Pset[i].get_y() + y) / pow(pow(Pset[i].get_x() - Pset[number].get_x(),2)+pow(Pset[i].get_y() - y,2),(3/2));
    }

    return sum/Pset[number].mass;
}

void ParticleProcessor::process()
{
    Particle *temp = new Particle[nn];
    for(int i=0;i<nn;i++){
        temp[i] = calculations(i);
        Pset[i] = temp[i];
    }
    delete[] temp;
}
ParticleProcessor::ParticleProcessor(Particle* a,int count)
{
    this->nn = count;
    this-> Pset = new Particle[nn];
    for(int i=0; i<nn;i++) this->Pset[i] = a[i];

};
