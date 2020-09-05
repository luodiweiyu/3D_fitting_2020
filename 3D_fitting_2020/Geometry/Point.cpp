#include"Point.h"
Point::Point(const Point& pt)
{
	coordinate = pt.coordinate;
}
Point::Point(double x, double y, double z)
{
	coordinate.resize(3);
	upd(x, y, z);
}
void Point::upd(double x, double y, double z)
{
	coordinate[0] = x;
	coordinate[1] = y;
	coordinate[2] = z;
}

meshAdd::meshAdd(int add1, int add2, int add3)
{
	add.resize(3);
	upd(add1, add2, add3);
}
meshAdd::meshAdd(int add1, int add2, int add3,int add4)
{
	add.resize(4);
	upd(add1, add2, add3,add4);
}
void meshAdd::upd(int add1, int add2, int add3)
{
	add[0] = add1;
	add[1] = add2;
	add[2] = add3;
}
void meshAdd::upd(int add1, int add2, int add3, int add4)
{
	if (add.size() == 3)
		add.resize(4);
	add[0] = add1;
	add[1] = add2;
	add[2] = add3;
	add[3] = add4;
}
