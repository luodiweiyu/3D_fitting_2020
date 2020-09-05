#include"Zone.h"
void Zone::addLine(zoneLine& ln)
{
	zl.push_back(&ln);
}
void Zone::addLine(Point& pt1, Point& pt2)
{
	zoneLine zoneline(pt1, pt2);
	addLine(zoneline);
}
void Zone::addScatter(Point& sctr)
{
	scatter.push_back(&sctr);
}
bool Zone::judInOut(Point& sctr)
{
	return 0;
}
void Zone3::chgCent(Point& cent_)
{
	cent = cent_;
}
void Zone4::updAxisLine(zoneLine& ln)
{
	axisline = ln;
}
void Zone4::updAxisLine(Point& startPt, Point& endPt)
{
	zoneLine zoneline(startPt, endPt);
	updAxisLine(zoneline);
}
