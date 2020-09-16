#include"Math.h"
//求点在面的哪侧 ==0即在面上
double judgeside(Surface& sf, Point& pt)
{
	return sf.a() * pt.x() + sf.b() * pt.y() + sf.c() * pt.z() + sf.d();
}
//求点到面的距离
double distance(Surface& sf, Point& pt)
{
	double dist = abs(sf.a() * pt.x() + sf.b() * pt.y() + sf.c() * pt.z() + sf.d());
	dist /= sqrt(sf.a() * sf.a() + sf.b() * sf.b() + sf.c() * sf.c());
	return dist;
}
//求点到点的距离
double distance(Point& pt1, Point& pt2)
{
	return sqrt((pt1.x() - pt2.x()) * (pt1.x() - pt2.x()) + (pt1.y() - pt2.y()) * (pt1.y() - pt2.y()) + (pt1.z() - pt2.z()) * (pt1.z() - pt2.z()));
}

//点到直线距离，解析几何，丘维声，p71,4.1
double distance(Point& pt, zoneLine& ln)
{
	double x1, y1, z1;
	double x2, y2, z2;
	x1 = pt.x() - ln.start_pt().x();
	y1 = pt.y() - ln.start_pt().y();
	z1 = pt.z() - ln.start_pt().z();
	x2 = ln.end_pt().x() - ln.start_pt().x();
	y2 = ln.end_pt().y() - ln.start_pt().y();
	z2 = ln.end_pt().z() - ln.start_pt().z();
	double cross_x = y1 * z2 - y2 * z1;
	double cross_y = -x1 * z2 + x2 * z1;
	double cross_z = x1 * y2 - x2 * y1;
	double dis = (cross_x * cross_x + cross_y * cross_y + cross_z * cross_z) / (x2 * x2 + y2 * y2 + z2 * z2);
	dis = sqrt(dis);
	return dis;
}

