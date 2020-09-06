#pragma once
#include<vector>
#include<string>
#include"Line.h"
#include"mesh.h"
using std::vector;
using std::string;
//Zone_base �������
//ln��������
//scatter�������ڰ�����ɢ��
//sf:����߽��߹��ɵı߽���;
//addLine: ��zone���������߽��ߣ����ڵ��ԴӦ����������
//addScatter:��zone�����ɢ��
//chgCent�������������ĵ�����
//judInOut:�жϵ��Ƿ��������ڲ�
//			�����ڲ��򷵻�true
//			�����ⲿ�򷵻�false
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

//Zone3 �����������������
//cent:�������ĵ㣬���ڵ��Դ����Ϊ���Դ����
//chgCent�������������ĵ�����

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

//Zone4pt �ı��������������
//axisLine������
//addAxisLine: ��������

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