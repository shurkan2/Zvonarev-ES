#include <cmath>

#define DEBUG

class SLAU	
{
	
	int n = 0;
	double f[100] = {0};
	double A[100][100] = {0};
	public:
		SLAU(const int n) 
		{
			this->n = n+1;
			for (int j = 0; j < n + 1; j++)
			{
		
				for (int k = 0; k < n + 1; k++)
					A[j][k] = j*k;
			}
			for (int k = 0; k < n + 1; k++)
				f[k] = k;
		}
	  
		double Get(const int i, const int j)
		{
			return A[i][j];
		};
	 double Get(const int i)
	 {
		 return f[i];
	 };
	 void Set(const int j, const int i, const double value)
	 {
		 this->A[i][j] = value;
	 };
	 void Set(const int i, const double value)
	 {
		 this->f[i] = value;
	 };
	 void Set(const double value)
	 {
		 this->n = value+1;
	 };

private:	 void ChangeInLine(const int currStr) 
	 {
		 double max = 0;
		 int k = 0;
		 for (int i = currStr; i < this->n; i++)
		 {
			 if (abs(this->A[currStr][i]) > abs(max)) { max = A[i][currStr]; k = i; }
		 }
		 this->ChangeStr(currStr, k);
		 
		 if (max != 0) 
		 {
			 for (int i = currStr; i < this->n; i++)
			 {
				 A[currStr][i] = A[currStr][i] / A[currStr][currStr];
			 }
			 f[currStr] = f[currStr] / A[currStr][currStr];
			 for (int i = currStr + 1; i < this->n; i++)
			 {
				 for (int j = currStr; j < this->n; j++)
				 {
					 A[i][j] -= A[i][currStr] * A[currStr][j];
				 }
				 f[i] -= A[i][currStr] * f[currStr];
			 }
		 }
	 }

	 void ChangeStr(const int which, const int Onwich) 
	 {
		 double a=0;
		 for (int i = 1; i < this->n; i++)
		 {
			 a = A[i][which];
			 A[which][i] = A[Onwich][i];
			 A[Onwich][i] = a;
		 }
		 double b = f[which];
		 f[which] = f[Onwich];
		 f[Onwich] = b;
	 }
public: void privod() 
{
	for (int i = 1; i < n; i++) this->ChangeInLine(i);
}
};