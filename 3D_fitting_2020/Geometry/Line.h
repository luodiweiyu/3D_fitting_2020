#pragma once
#include"Point.h"
#include"Surface.h"
#include<string>
//��άʱ��ֱ��������ƽ��Ľ���
class Line
{
public:
	Line(Surface& s1_, Surface& s2_);
	Line(Point& pt1, Point& pt2);
	Line() = default;
	virtual void upd(Surface& s1_, Surface& s2_);
	virtual void upd(Point& pt1, Point& pt2);
protected:
	Surface s1;//������ȥ��ʾֱ�߷���
	Surface s2;
};
class zoneLine :public Line//�����ߵķ��̣���������ֱ�߶��¼��ʼ��
{
private:
	Point startpt;//���㣬����Դ�㣬�������ı�
	Point endpt;//����㣬��ʼʱ�ǵ�λ����㣬���ʱΪ��ϵ�
	Point fittingpt;//��ϵ�
public:
	zoneLine() = default;
	zoneLine(Point& start, Point& end);
	void upd(Point& basept, Point& meshpt);
	Point& start_pt() { return startpt; };
	Point& end_pt() { return endpt; };
	Point& fit_pt() { return fittingpt; };
	void chgFittingPoint(Point& pt);//������ϵ�
	void output_fittingpt(string filename);
};