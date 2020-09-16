#pragma once
#include"../Geometry/Surface.h"
#include "../Geometry/Line.h"
double judgeside(Surface& sf, Point& pt);
double distance(Surface& sf, Point& pt);
double distance(Point& pt1, Point& pt2);
double distance(Point& pt, zoneLine& ln);