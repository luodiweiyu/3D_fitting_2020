#pragma once
#include<vector>
using namespace std;
class Point
{
private:
	vector<double> coordinate;
public:
	Point(const Point& pt);
	Point(double x,double y,double z);
	Point() { coordinate.resize(3); };
	void upd(double x, double y, double z);
	double x() { return coordinate[0]; };
	double y() { return coordinate[1]; };
	double z() { return coordinate[2]; };
};
class meshAdd
{
private:
	vector<int>add;
public:
	meshAdd() { add.resize(3); };
	meshAdd(int add1, int add2, int add3);
	meshAdd(int add1, int add2, int add3, int add4);
	void upd(int add1, int add2, int add3);
	void upd(int add1, int add2, int add3, int add4);
};