#pragma once
#include<vector>
using std::vector;
class Surface
{
public:
	Surface();
	Surface(double a, double b, double c, double d);
	void updateCof(double a, double b, double c, double d);
	void getSurface(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3);
	~Surface();
	double a() { return cof[0]; };
	double b() { return cof[1]; };
	double c() { return cof[2]; };
	double d() { return cof[3]; };
private:
	vector<double>cof;//平面方程系数 ax+by+cz+d=0
};

