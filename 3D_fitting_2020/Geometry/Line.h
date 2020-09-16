#pragma once
#include"Point.h"
#include"Surface.h"
#include<string>
//三维时，直线是两个平面的交线
class Line
{
public:
	Line(Surface& s1_, Surface& s2_);
	Line(Point& pt1, Point& pt2);
	Line() = default;
	virtual void upd(Surface& s1_, Surface& s2_);
	virtual void upd(Point& pt1, Point& pt2);
protected:
	Surface s1;//两个面去表示直线方程
	Surface s2;
};
class zoneLine :public Line//区域线的方程，比正常的直线多记录起始点
{
private:
	Point startpt;//基点，即光源点，不发生改变
	Point endpt;//网格点，初始时是单位网格点，输出时为拟合点
	Point fittingpt;//拟合点
public:
	zoneLine() = default;
	zoneLine(Point& start, Point& end);
	void upd(Point& basept, Point& meshpt);
	Point& start_pt() { return startpt; };
	Point& end_pt() { return endpt; };
	Point& fit_pt() { return fittingpt; };
	void chgFittingPoint(Point& pt);//更改拟合点
	void output_fittingpt(string filename);
};