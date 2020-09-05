#include"Surface.h"
Surface::Surface()
{
	cof.resize(4);
}
Surface::Surface(double a, double b, double c, double d)
{
	cof.resize(4);
	updateCof(a, b, c, d);
}
void Surface::updateCof(double a, double b, double c, double d)
{
	cof[0] = a;
	cof[1] = b;
	cof[2] = c;
	cof[3] = d;
}
Surface::~Surface()
{
}