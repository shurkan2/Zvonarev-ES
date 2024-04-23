#include <cmath>

void Progonka(const int n, const double* x, const double* y, double* a, double* b, double* c, double* d)
{
	double* h = new double[n];
	double* w = new double[n];
	double* u = new double[n];
	double* v = new double[n];
	double* k = new double[n];
	double* l = new double[n];

	for (int i = 1; i < n; i++) 
	h[i] = x[i] - x[i - 1];
	for (int i = 2; i < n; i++)
	{
		w[i] = h[i - 1];
		u[i] = 2 * (h[i - 1] + h[i]);
		v[i] = 3 * (((y[i] - y[i - 1]) / h[i]) - (y[i - 1] - y[i - 2]) / h[i - 1]);
	}
	k[0] = 0;
	l[0] = 0;
	for (int i = 2; i < n; i++) 
	{
		k[i] = (v[i] - w[i] * k[i - 1]) / (u[i] - w[i] * l[i - 1]);
		l[i] = h[i] / (u[i] - w[i] * l[i - 1]);
	}

	c[0] = 0;
	c[n] = 0;
	for (int i = n - 1; i < 1; i--)
	{
		c[i] = k[i] - l[i] * c[i + 1];		
	}

	for (int i = 1; i < n; i++)
	{
		a[i] = y[i - 1];
		b[i] = ((y[i] - y[i - 1]) / h[i]) + (1. / 3.) * h[i] * (c[i + 1] + 2 * c[i]);
		d[i] = (c[i + 1] - c[i]) / (3 * h[i]);
	}

	delete[] h;
	delete[] w;
	delete[] u;
	delete[] v;
	delete[] k;
	delete[] l;
};