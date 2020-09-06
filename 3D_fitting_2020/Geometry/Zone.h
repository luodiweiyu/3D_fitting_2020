#pragma once
#include<vector>
#include<string>
#include"Line.h"
#include"mesh.h"
using std::vector;
using std::string;
//Zone_base 区域基类
//ln：区域线
//scatter：区域内包含的散点
//sf:区域边界线构成的边界面;
//addLine: 往zone中添加区域边界线，对于点光源应该有三条线
//addScatter:往zone中添加散点
//chgCent：更改区域中心点坐标
//judInOut:判断点是否在区域内部
//			若在内部则返回true
//			若在外部则返回false
class ZoneBase
{
protected:
	vector<zoneLine*> zl;
	vector<Point*> scatter;
	vector<Surface> sf;
public:
	ZoneBase() {};
	void addLine(zoneLine& ln);
	void addLine(Point& pt1, Point& pt2);
	void addScatter(Point& sctr);
	virtual void updSf() {};
	virtual void chgCent(Point& cent_) {};
	virtual void chgCent(double x,double y,double z) {};
	virtual void updAxisLine(zoneLine& ln) {};
	virtual void updAxisLine(Point& startPt, Point& endPt) {};
	virtual bool judInOut(Point& sctr);
	virtual void updSurface() {};
};

//Zone3 三角形网格区域基类
//cent:区域中心点，对于点光源，即为点光源坐标
//chgCent：更改区域中心点坐标

class Zone3pt :public ZoneBase
{
private:
	Point cent;
public:
	void chgCent(Point& cent_);
	void chgCent(double x, double y, double z) ;
	void updSurface() ;
	bool judInOut(Point& sctr);
};

//Zone4pt 四边形网格区域基类
//axisLine：轴线
//addAxisLine: 更新轴线

class Zone4pt :public ZoneBase
{
private:
	zoneLine axisline;
public:
	void updAxisLine(zoneLine& ln);
	void updAxisLine(Point& startPt, Point& endPt);
	void updSurface();

	bool judInOut(Point& sctr);
};

class ZoneFit
{
	vector<Point> scatter;
	vector<zoneLine> znline;
	vector<ZoneBase*> zone;
	Point lightStart;
	Point lightEnd;
public:
	ZoneFit() {};
	ZoneFit(string scatfile);
	void updLightStart(Point& pt) { lightStart = pt; };
	void updLightEnd(Point& pt) { lightEnd = pt; };
	void init(Mesh& mesh);
};