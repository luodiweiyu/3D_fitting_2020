#pragma once
#include"Point.h"
#include"Surface.h"
//三维时，直线是两个平面的交线
class Line
{
public:
	Line(Surface& s1_, Surface& s2_);
	Line(Point& pt1, Point& pt2);
	Line() {};
private:
	Surface s1;//两个面去表示直线方程
	Surface s2;
};
class zoneLine :public Line//区域线的方程，比正常的直线多了些东西
{
private:
	Point basePt;//基点，即光源点，不发生改变
	Point meshPt;//网格点，初始时是单位网格点，输出时为拟合点
public:
	zoneLine(Point& basept, Point& meshpt);
};