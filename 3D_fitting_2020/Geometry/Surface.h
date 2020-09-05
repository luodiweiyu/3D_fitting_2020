#pragma once
#include<vector>
using std::vector;
class Surface
{
public:
	Surface();
	Surface(double a, double b, double c, double d);
	void updateCof(double a, double b, double c, double d);
	~Surface();
	double a() { return cof[0]; };
	double b() { return cof[1]; };
	double c() { return cof[2]; };
	double d() { return cof[3]; };
private:
	vector<double>cof;//平面方程系数 ax+by+cz+d=0
};

