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


void Surface::getSurface(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3)
{

	double vx1, vy1, vz1;
	double vx2, vy2, vz2;
	vx1 = x2 - x1, vy1 = y2 - y1, vz1 = z2 - z1;
	vx2 = x3 - x1, vy2 = y3 - y1, vz2 = z3 - z1;
	double nx = vy1 * vz2 - vy2 * vz1;
	double ny = vx2 * vz1 - vx1 * vz2;
	double nz = vx1 * vy2 - vx2 * vy1;

	if (abs(vx1) <= 1e-20 && abs(vx2) <= 1e-20)
	{
		cof[0] = 1;
		cof[1] = 0;
		cof[2] = 0;
		cof[3] = -x1;
	}
	else if (abs(vy1) <= 1e-20 && abs(vy2) <= 1e-20)
	{
		cof[0] = 0;
		cof[1] = 1;
		cof[2] = 0;
		cof[3] = -y1;
	}
	else if (abs(vz1) <= 1e-20 && abs(vz2) <= 1e-20)
	{
		cof[0] = 0;
		cof[1] = 0;
		cof[2] = 1;
		cof[3] = -z1;
	}
	else
	{
		cof[0] = nx;
		cof[1] = ny;
		cof[2] = nz;
		cof[3] = -(nx * x1 + ny * y1 + nz * z1);
	}
}