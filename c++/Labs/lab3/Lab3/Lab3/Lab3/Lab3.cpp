#include <time.h>
#include <cmath>
#include <iostream>
#define FirstTask

#ifdef FirstTask
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    double R, H, sumy = 0, sumyy = 0, x = 0, y = 0;
    int n = 1000000;

    cout << "Ведите значение Радиуса R = ";
    cin >> R;

    cout << "Ведите значение величины H = ";
    cin >> H;
   // for (int j = 0; j < 10; j++) {
        for (int i = 0; i < n; i++)
        {
            x = rand() / (float)RAND_MAX;
            x *= 2 * R;
            x -= R;
            if ((R * R - x * x) < 0) { i--; continue; }
            y = pow((R * R - x * x), 0.5);
            sumy += y;
            sumyy += y * y;
        }
        sumy /= n;
        sumyy /= n;

        cout << "Значение интеграла: " << sumy * 2 * R * H << endl;
        cout << "Значение погрешности: " << 2 * R * H * pow((sumyy - sumy * sumy) / n, 0.5) << endl;
        cout << endl;
    //}
    system("pause");
}
#else

double f(const double x) 
{
    return sin(x) * sin(x);
}

int main() 
{
    setlocale(LC_ALL, "ru");

    double c10[10] = {0.000007640043,0.00134364,0.038743,0.240138,0.610862,0.610862,0.240138,0.038743,0.00134364,0.000007640043};
    double c5[5] = {0.0199532,0.393619,0.945308,0.393619,0.0199532};
    double x10[10] = {-3.43615,-2.53273,-1.75668,-1.03661,-0.34290,0.34290,1.03661,1.75668,2.53273,3.43615};
    double x5[5] = {-2.02018,-0.95857,0,2.02018,0.95857};
    double sum5 = 0, sum10 = 0;
    for (int i = 0; i < 5; i++)
        sum5 += c5[i] * f(x5[i]);
    
    for (int i = 0; i < 10; i++)
        sum10 += c10[i] * f(x10[i]);
    using namespace std;

    cout << "Значение интеграла для 5 узлов: " << sum5 << endl;
    cout << "Значение интеграла для 10 узлов: " << sum10 << endl;
    cout << "Значение погрешности определения: " << abs(sum10 - sum5) / (-1 + pow(2, 5));
}

#endif // FirstTask

