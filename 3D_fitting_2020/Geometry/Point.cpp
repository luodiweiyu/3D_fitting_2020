#include"Point.h"
Point::Point(const Point& pt)
{
	coordinate = pt.coordinate;
}
Point::Point(const double x, const double y, const double z)
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

bool Point::operator==(const Point& pt)
{
	double delta = 1e-15;
	//if (abs(coordinate[0] - pt.coordinate[0]) +abs( coordinate[1] - pt.coordinate[1]) +abs( coordinate[2] - pt.coordinate[2]) < delta)
	if(coordinate==pt.coordinate)
		return true;
	else
		return false;
}

Point Point::operator+(const Point& pt)
{
	Point temp;
	for (int i = 0; i < coordinate.size(); i++)
		temp.coordinate[i] = this->coordinate[i] + pt.coordinate[i];
	return temp;
}

Point Point::operator-(const Point& pt)
{
	Point temp;
	for (int i = 0; i < coordinate.size(); i++)
		temp.coordinate[i] = this->coordinate[i] - pt.coordinate[i];
	return temp;
}

void Point::rotate(Point& rotate_pt, double theta, double phi)
{
	rotate_xy(rotate_pt, theta);
	rotate_z(rotate_pt, phi);
}

void Point::rotate_xy(Point& rotate_pt, double theta)
{
	double x = (this->x() - rotate_pt.x()) * cos(-theta) - (this->y() - rotate_pt.y()) * sin(-theta) + rotate_pt.x();
	double y = (this->y() - rotate_pt.y()) * cos(-theta) - (this->x() - rotate_pt.x()) * sin(-theta) + rotate_pt.y();
	upd(x, y, this->z());
}

void Point::rotate_z(Point& rotate_pt, double phi)
{
	//»¹Î´Íê³É
}

meshAdd::meshAdd(const int add1, const  int add2, const  int add3)
{
	add.resize(3);
	upd(add1, add2, add3);
}
meshAdd::meshAdd(const int add1, const int add2, const int add3, const int add4)
{
	add.resize(4);
	upd(add1, add2, add3, add4);
}
void meshAdd::upd(const int add1, const  int add2, const int add3)
{
	add[0] = add1;
	add[1] = add2;
	add[2] = add3;
}
void meshAdd::upd(const int add1, const int add2, const int add3, const int add4)
{
	if (add.size() == 3)
		add.resize(4);
	add[0] = add1;
	add[1] = add2;
	add[2] = add3;
	add[3] = add4;
}
