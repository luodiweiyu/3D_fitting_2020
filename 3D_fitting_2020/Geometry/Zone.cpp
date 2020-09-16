#include"Zone.h"
#include"../Utility/Math.h"
#include"../eigen-3.3.7/Eigen/Dense";
#include<fstream>
#include<iostream>
void ZoneBase::addLine(zoneLine& ln)
{
	zl.push_back(&ln);
}
void ZoneBase::addLine(Point& pt1, Point& pt2)
{
	zoneLine zoneline(pt1, pt2);
	addLine(zoneline);
}
void ZoneBase::addScatter(Point* sctr)
{
	if (scatter.empty())
		scatter.reserve(10);
	else if (scatter.size() == scatter.capacity())
		scatter.reserve(scatter.size() * 3 / 2);
	scatter.push_back(sctr);
}
bool ZoneBase::inZone(Point& sctr)
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
	sf.resize(zl.size());
	sf[0].getSurface(cent, zl[0]->end_pt(), zl[1]->end_pt());
	sf[1].getSurface(cent, zl[1]->end_pt(), zl[2]->end_pt());
	sf[2].getSurface(cent, zl[2]->end_pt(), zl[0]->end_pt());
}
bool Zone3pt::inZone(Point& sctr)
{
	double judge1, judge2, judge3;
	judge1 = judgeside(sf[0], sctr) * judgeside(sf[0], zl[2]->end_pt());
	judge2 = judgeside(sf[1], sctr) * judgeside(sf[1], zl[0]->end_pt());
	judge3 = judgeside(sf[2], sctr) * judgeside(sf[2], zl[1]->end_pt());
	if (judge1 >= 0 && judge2 >= 0 && judge3 >= 0)
		return true;
	else
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
void Zone4pt::updSurface()
{
	sf.resize(zl.size());
	sf[0].getSurface(zl[0]->start_pt(), zl[0]->end_pt(), zl[1]->end_pt());
	sf[1].getSurface(zl[1]->start_pt(), zl[1]->end_pt(), zl[2]->end_pt());
	sf[2].getSurface(zl[2]->start_pt(), zl[2]->end_pt(), zl[3]->end_pt());
	sf[3].getSurface(zl[3]->start_pt(), zl[3]->end_pt(), zl[0]->end_pt());
}
bool Zone4pt::inZone(Point& sctr)
{

	double judge1, judge2, judge3, judge4;
	judge1 = judgeside(sf[0], sctr) * judgeside(sf[0], zl[2]->end_pt());
	judge2 = judgeside(sf[1], sctr) * judgeside(sf[1], zl[3]->end_pt());
	judge3 = judgeside(sf[2], sctr) * judgeside(sf[2], zl[0]->end_pt());
	judge4 = judgeside(sf[3], sctr) * judgeside(sf[3], zl[1]->end_pt());

	if (judge1 >= 0 && judge2 >= 0 && judge3 >= 0 && judge4 >= 0)
		return true;
	else
		return false;
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

void ZoneFit::init(Mesh& mesh_, Point light_start, Point light_end)
{
	mesh = &mesh_;
	lightStart = light_start;
	lightEnd = light_end;
	znline.resize(mesh->ptNum());
	zone.resize(mesh->elementNum());
	double axisLenth = distance(lightStart, lightEnd);
	Point temp;
	int i, j, k;
	for (i = 0; i < mesh->ptNum(); i++)
	{
		//�Ƚ����е����ƽ�ƣ�ʹ�õ�λ�����ģ�0,0,0�����趨�������غ�(lightStart)
		mesh->pt(i)->upd(mesh->pt(i)->x() + lightStart.x(), mesh->pt(i)->y() + lightStart.y(), mesh->pt(i)->z() + lightStart.z());
		if (mesh->pt(i)->x() <= lightStart.x())//��λ����
		{
			znline[i].upd(lightStart, *mesh->pt(i));
		}
		else//��λԲ��
		{
			//Բ���ϵĵ㣬��Ҫ�����趨��������ʼ���������
			double x = (mesh->pt(i)->x() - lightStart.x()) * axisLenth + lightStart.x();
			mesh->pt(i)->upd(x, mesh->pt(i)->y(), mesh->pt(i)->z());
			temp.upd(x, 0, 0);
			znline[i].upd(temp, *mesh->pt(i));
		}
	}

	for (i = 0; i < mesh->elementNum(); i++)
	{
		if (mesh->maddr(i).pt_num() == 3)//�����Ӧ��������ַ����Ϊ3��������������
		{
			zone[i] = new Zone3pt;
			zone[i]->addLine(znline[mesh->maddr(i).pt_addr(0)]);
			zone[i]->addLine(znline[mesh->maddr(i).pt_addr(1)]);
			zone[i]->addLine(znline[mesh->maddr(i).pt_addr(2)]);
			zone[i]->chgCent(lightStart);
			zone[i]->updSurface();
		}
		else if (mesh->maddr(i).pt_num() == 4)//�����Ӧ��������ַ����Ϊ4�����ı�������
		{
			zone[i] = new Zone4pt;
			zone[i]->addLine(znline[mesh->maddr(i).pt_addr(0)]);
			zone[i]->addLine(znline[mesh->maddr(i).pt_addr(1)]);
			zone[i]->addLine(znline[mesh->maddr(i).pt_addr(2)]);
			zone[i]->addLine(znline[mesh->maddr(i).pt_addr(3)]);

			/*
			----------------�����ı������������---------------------
			vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
			1.�ҵ����ߵ������㣺pt1,pt2
			2.�ж������յ㣺���pt1->pt2���ܵ����������н�<90�ȣ���pt1Ϊ��㣬pt2Ϊ�յ�
			����pt2Ϊ��㣬pt1Ϊ�յ�
			*/
			Point pt1, pt2;
			pt1 = znline[mesh->maddr(i).pt_addr(0)].end_pt();
			pt2 = znline[mesh->maddr(i).pt_addr(1)].end_pt();
			if (pt1 == pt2)
				pt2 = znline[mesh->maddr(i).pt_addr(2)].end_pt();
			double vect1[3], vect2[3];
			vect1[0] = pt2.x() - pt1.x();
			vect1[1] = pt2.y() - pt1.y();
			vect1[2] = pt2.z() - pt1.z();
			vect2[0] = lightEnd.x() - lightStart.x();
			vect2[1] = lightEnd.y() - lightStart.y();
			vect2[2] = lightEnd.z() - lightStart.z();
			if (vect1[0] * vect2[0] + vect1[1] * vect2[1] + vect1[2] * vect2[2] > 0)

				zone[i]->updAxisLine(pt1, pt2);
			else
				zone[i]->updAxisLine(pt2, pt1);
			/*
			^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
			----------------�����ı������������---------------------
			*/

			zone[i]->updSurface();
		}
		else
			throw "���������λ��ı�������";
	}
	//��ɢ�㰴������з���
	//
	for (i = 0; i < scatter.size(); i++)
	{
		//���ĳһ�㣬����ÿ�����򣬿��õ��Ƿ��ڸ�������
		for (j = 0; j < zone.size(); j++)
		{
			//�����ĳһ�����ڣ�����ɢ�����������ڣ��������һ��ɢ����б���
			if (zone[j]->inZone(scatter[i]))
			{
				zone[j]->addScatter(&scatter[i]);
				if (i % 1000 == 0)
					std::cout << "i = " << i << "   j = " << j << " scattersize = " << scatter.size() << std::endl;
				break;
			}
		}
	}
	//��ÿ�������ڵı߽��ߣ��ҳ������������������ɢ��
	for (i = 0; i < zone.size(); i++)
	{
		for (j = 0; j < zone[i]->scatter_size(); j++)
		{
			for (k = 0; k < zone[i]->zoneline_size(); k++)
				zone[i]->zoneline(k)->chgFittingPoint(*zone[i]->sctr(j));
		}
	}

	for (i = 0; i < znline.size(); i++)
	{
		znline[i].output_fittingpt("fittingpt.dat");
	}
}

void ZoneFit::genFitMesh(Mesh& fitmesh)
{
	int i, j;
	vector<int>id;
	meshAdd meshAddTemp;
	Point cent;
	double x, y, z;
	for (i = 0; i < zone.size(); i++)
	{
		//���������ĳ����������û����ϵ㣬�����������µ�����
		for (j = 0; j < zone[i]->zoneline_size(); j++)
			if (zone[i]->zoneline(j)->fit_pt() == Point(0, 0, 0))
				break;
		if (j < zone[i]->zoneline_size() - 1)
			continue;

		if (zone[i]->zoneline_size() == 3)
		{
			id.resize(zone[i]->zoneline_size());
			id[0] = fitmesh.addMeshPoint(zone[i]->zoneline(0)->fit_pt());
			id[1] = fitmesh.addMeshPoint(zone[i]->zoneline(1)->fit_pt());
			id[2] = fitmesh.addMeshPoint(zone[i]->zoneline(2)->fit_pt());
			meshAddTemp.upd(id[0], id[1], id[2]);
			fitmesh.addMeshAddr(meshAddTemp);
		}
		else if (zone[i]->zoneline_size() == 4)
		{
			id.resize(zone[i]->zoneline_size() + 1);
			id[0] = fitmesh.addMeshPoint(zone[i]->zoneline(0)->fit_pt());
			id[1] = fitmesh.addMeshPoint(zone[i]->zoneline(1)->fit_pt());
			id[2] = fitmesh.addMeshPoint(zone[i]->zoneline(2)->fit_pt());
			id[3] = fitmesh.addMeshPoint(zone[i]->zoneline(3)->fit_pt());
			x = zone[i]->zoneline(0)->fit_pt().x() + zone[i]->zoneline(1)->fit_pt().x() + zone[i]->zoneline(2)->fit_pt().x() + zone[i]->zoneline(3)->fit_pt().x();
			y = zone[i]->zoneline(0)->fit_pt().y() + zone[i]->zoneline(1)->fit_pt().y() + zone[i]->zoneline(2)->fit_pt().y() + zone[i]->zoneline(3)->fit_pt().y();
			z = zone[i]->zoneline(0)->fit_pt().z() + zone[i]->zoneline(1)->fit_pt().z() + zone[i]->zoneline(2)->fit_pt().z() + zone[i]->zoneline(3)->fit_pt().z();
			x /= 4;
			y /= 4;
			z /= 4;
			cent.upd(x, y, z);
			id[4] = fitmesh.addMeshPoint(cent);
			meshAddTemp.upd(id[0], id[4], id[1]);
			fitmesh.addMeshAddr(meshAddTemp);
			meshAddTemp.upd(id[1], id[4], id[2]);
			fitmesh.addMeshAddr(meshAddTemp);
			meshAddTemp.upd(id[2], id[4], id[3]);
			fitmesh.addMeshAddr(meshAddTemp);
			meshAddTemp.upd(id[3], id[4], id[0]);
			fitmesh.addMeshAddr(meshAddTemp);
		}
		else
			throw "��������������Ҳ�����ĵ�����";
	}
}
