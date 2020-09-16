#pragma once
#include<vector>
using std::vector;
#include"Point.h"
class Surface
{
public:
	Surface();
	Surface(const double a, const double b,const double c,const double d);
	Surface(const Point& pt1, const Point& pt2, const Point& pt3);
	Surface(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2, const double x3, const double y3, const double z3);
	void updateCof(double a, double b, double c, double d);
	void getSurface(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3);
	void getSurface(const Point& pt1, const Point& pt2, const Point& pt3);
	~Surface();
	vector<double> coefficient() { return cof; };
	double a() { return cof[0]; };
	double b() { return cof[1]; };
	double c() { return cof[2]; };
	double d() { return cof[3]; };
private:
	vector<double>cof;//平面方程系数 ax+by+cz+d=0
};

