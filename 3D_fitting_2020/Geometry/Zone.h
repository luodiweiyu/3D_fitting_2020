#pragma once
#include<vector>
#include"Line.h"
using std::vector;
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
class Zone
{
protected:
	vector<zoneLine*> zl;
	vector<Point*> scatter;
	vector<Surface> sf;
public:
	Zone() {};
	void addLine(zoneLine& ln);
	void addLine(Point& pt1, Point& pt2);
	void addScatter(Point& sctr);
	virtual bool judInOut(Point& sctr);
};

//Zone3 �����������������
//cent:�������ĵ㣬���ڵ��Դ����Ϊ���Դ����
//chgCent�������������ĵ�����

class Zone3:public Zone
{
private:
	Point cent;
public:
	void chgCent(Point& cent_);
	bool judInOut(Point& sctr);
};

//Zone3 �����������������
//axisLine������
//addAxisLine: ��������

class Zone4 :public Zone
{
private:
	zoneLine axisline;
public:
	void updAxisLine(zoneLine& ln);
	void updAxisLine(Point& startPt, Point& endPt);
	bool judInOut(Point& sctr);
};
