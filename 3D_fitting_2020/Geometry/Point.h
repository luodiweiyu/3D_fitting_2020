#pragma once
#include<vector>
using namespace std;
class Point
{
private:
	vector<double> coordinate;
public:
	Point(const Point& pt);
	Point(const double x, const double y, const double z);
	Point() { coordinate.resize(3); upd(0, 0, 0); };
	void upd(const double x, const double y, const double z);
	bool operator==(const Point& pt);
	Point operator+(const Point& pt);
	Point operator-(const Point& pt);
	//绕rotate_pt旋转,xoy平面theta（-pi~pi）,z方向phi(-pi/2~pi/2),逆时针为正，顺时针为负
	void rotate(Point& rotate_pt, double theta, double phi);
	void rotate_xy(Point& rotate_pt, double theta);
	void rotate_z(Point& rotate_pt, double phi);
	double x()const { return coordinate[0]; };
	double y()const { return coordinate[1]; };
	double z()const { return coordinate[2]; };
};
class meshAdd
{
private:
	vector<int>add;
public:
	meshAdd() { add.resize(3); };
	meshAdd(const int add1, const int add2, const  int add3);
	meshAdd(const int add1, const int add2, const int add3, const int add4);
	void upd(const int add1, const int add2, const int add3);
	void upd(const int add1, const int add2, const int add3, const int add4);
	int pt_addr(int i) { return add[i]; };
	int pt_num() { return add.size(); };
};