#pragma once
#include"Point.h"
#include"Surface.h"
//��άʱ��ֱ��������ƽ��Ľ���
class Line
{
public:
	Line(Surface& s1_, Surface& s2_);
	Line(Point& pt1, Point& pt2);
	Line() {};
private:
	Surface s1;//������ȥ��ʾֱ�߷���
	Surface s2;
};
class zoneLine :public Line//�����ߵķ��̣���������ֱ�߶���Щ����
{
private:
	Point basePt;//���㣬����Դ�㣬�������ı�
	Point meshPt;//����㣬��ʼʱ�ǵ�λ����㣬���ʱΪ��ϵ�
public:
	zoneLine(Point& basept, Point& meshpt);
};