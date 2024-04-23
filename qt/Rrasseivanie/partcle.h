#ifndef PARTCLE_H
#define PARTCLE_H
class Particle
{
public:
 double x=0, y=0, v_x=0, v_y=0;
public:
 double mass=0.01, chrg=1;
 double get_x();
 double get_y();
 void set_x(double);
 void set_y(double);
 double get_vx();
 double get_vy();
 void set_vx(double);
 void set_vy(double);
 Particle(double x, double y,double vx, double vy, double mass, double chardge);
 Particle();
 Particle& operator = (const Particle &ptcl)
 {
     this->chrg = ptcl.chrg;
     this->mass = ptcl.mass;
     this->x = ptcl.x;
     this->y = ptcl.y;
     this->v_x = ptcl.v_x;
     this->v_y = ptcl.v_y;
     return *this;
 }
 Particle(const Particle &ptcl)
 {
     this->chrg = ptcl.chrg;
     this->mass = ptcl.mass;
     this->x = ptcl.x;
     this->y = ptcl.y;
     this->v_x = ptcl.v_x;
     this->v_y = ptcl.v_y;
 }
};

class ParticleProcessor
{
  public:
    Particle* Pset = nullptr;
    int nn=0;
    void process();
    Particle calculations(int);
    double f_x(double, int);
    double f_y(double, int);
    ParticleProcessor(Particle*,int);
};

class DataStorage
{
    double *x, *y;
    int *t, length;
   public:
    DataStorage(int a) {
        this->x = new double[a]+1;
        this->y = new double[a+1];
        this->t = new int [a+1];
        this->length = a;
    }
    DataStorage(){
        this->x = nullptr;
        this->y = nullptr;
        this->t = nullptr;
        this->length = -1;
    }
    void AddValue(double x0, double y0, int t0 ){
        if (this->length>=t0)
        {
            this->x[t0] = x0;
            this->y[t0] = y0;
        }
    }
    bool GiveValue(int t0, double &x0, double &y0){
        if ((t0<= this->length) && (t0>0))
        {
            x0 = this->x[t0];
            y0 = this->y[t0];
            return true;
        }
        else return false;
    }
    ~DataStorage(){
        delete[] x;
        delete[] y;
        delete[] t;
    }
};
#endif // PARTCLE_H
