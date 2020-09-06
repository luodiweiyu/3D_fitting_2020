#include"Zone.h"
#include<fstream>
void ZoneBase::addLine(zoneLine& ln)
{
	zl.push_back(&ln);
}
void ZoneBase::addLine(Point& pt1, Point& pt2)
{
	zoneLine zoneline(pt1, pt2);
	addLine(zoneline);
}
void ZoneBase::addScatter(Point& sctr)
{
	scatter.push_back(&sctr);
}
bool ZoneBase::judInOut(Point& sctr)
{
	return 0;
}
void Zone3pt::chgCent(Point& cent_)
{
	cent = cent_;
}
void Zone3pt::chgCent(double x, double y, double z)
{
	cent.upd(x, y, z);
}
void Zone3pt::updSurface()
{
	sf.resize(zl.size() - 1);
	int i;
	for (i = 0; i < zl.size()-1; i++)
	{
		sf[i].getSurface(cent.x(), cent.y(), cent.z(),
			zl[i]->endpt().x(), zl[i]->endpt().y(), zl[i]->endpt().z(),
			zl[i + 1]->endpt().x(), zl[i + 1]->endpt().y(), zl[i + 1]->endpt().z());
	}
	sf[zl.size()-1].getSurface(cent.x(), cent.y(), cent.z(),
		zl[0]->endpt().x(), zl[0]->endpt().y(), zl[0]->endpt().z(),
		zl[zl.size() - 1]->endpt().x(), zl[zl.size() - 1]->endpt().y(), zl[zl.size() - 1]->endpt().z());

}
bool Zone3pt::judInOut(Point& sctr)
{
	return false;
}
void Zone4pt::updAxisLine(zoneLine& ln)
{
	axisline = ln;
}
void Zone4pt::updAxisLine(Point& startPt, Point& endPt)
{
	zoneLine zoneline(startPt, endPt);
	updAxisLine(zoneline);
}

ZoneFit::ZoneFit(string scatfile)
{
	using std::ifstream;
	double x, y, z;
	Point temp;
	ifstream fin(scatfile);
	while (!fin.eof())
	{
		fin >> x;
		fin >> y;
		fin >> z;
		temp.upd(x, y, z);
		if (scatter.size() == 0)
			scatter.reserve(10);
		else if (scatter.size() == scatter.capacity())
			scatter.reserve(scatter.size() * 3 / 2);
		scatter.push_back(temp);
	}
	fin.close();

}

void ZoneFit::init(Mesh& mesh)
{
	znline.resize(mesh.ptNum());
	zone.resize(mesh.elementNum());
	Point temp;
	int i;
	for (i = 0; i < mesh.ptNum(); i++)
	{
		if (mesh.pt(i).x() <= 1)//单位半球
		{
			znline[i].upd(lightStart, mesh.pt(i));
		}
		else//单位圆柱
		{
			temp.upd(mesh.pt(i).x(), 0, 0);
			znline[i].upd(temp, mesh.pt(i));
		}
	}
	for (i = 0; i < mesh.elementNum(); i++)
	{
		if (mesh.maddr(i).size() == 3)
		{  
			zone[i] = new Zone3pt;
			zone[i]->addLine(znline[mesh.maddr(i).addr(0) - 1]);
			zone[i]->addLine(znline[mesh.maddr(i).addr(1) - 1]);
			zone[i]->addLine(znline[mesh.maddr(i).addr(2) - 1]);
			zone[i]->chgCent(0, 0, 0);
			zone[i]->updSurface();
		}
	}


}
