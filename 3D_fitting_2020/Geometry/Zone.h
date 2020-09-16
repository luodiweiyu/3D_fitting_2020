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
	ZoneBase()=default;
	void addLine(zoneLine& ln);
	void addLine(Point& pt1, Point& pt2);
	void addScatter(Point *sctr);
	int scatter_size() { return scatter.size(); };
	int zoneline_size() { return zl.size(); };
	zoneLine* zoneline(int i) { return zl[i]; };
	Point* sctr(int i) { return scatter[i]; };
	virtual void updSf() {};
	virtual void chgCent(Point& cent_) {};
	virtual void chgCent(double x,double y,double z) {};
	virtual void updAxisLine(zoneLine& ln) {};
	virtual void updAxisLine(Point& startPt, Point& endPt) {};
	virtual bool inZone(Point& sctr);
	virtual void updSurface() {};

};

//Zone3 ����������������
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
	bool inZone(Point& sctr);
};

//Zone4pt �ı�������������
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
	bool inZone(Point& sctr);
};

class ZoneFit
{
	//scatter ���е�ɢ��
	//znline ���е�������
	//���е�����
	//mesh ��λ����
	//lightstart ��Դ��ʼ��
	//lightend ��Դ�յ�
	vector<Point> scatter;
	vector<zoneLine> znline;
	vector<ZoneBase*> zone;

	Mesh* mesh;
	Point lightStart;
	Point lightEnd;
public:
	ZoneFit(string scatfile);
	void updLightStart(Point& pt) { lightStart = pt; };
	void updLightEnd(Point& pt) { lightEnd = pt; };
	void init(Mesh& mesh_,Point light_start,Point light_end);
	void genFitMesh(Mesh &fitmesh);//������ϵ�����
};