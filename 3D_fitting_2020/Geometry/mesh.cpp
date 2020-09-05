#include"mesh.h"
#include<fstream>
void Mesh::initMesh(string meshPtFile, string meshAdd3File, string meshAdd4File)
{
	chgMeshPt(meshPtFile);
	chgMeshAdd3(meshAdd3File);
	chgMeshAdd4(meshAdd4File);
}
void Mesh::chgMeshPt(string meshPtFile)
{
	using std::ifstream;
	double x, y, z;
	Point temp;
	ifstream fin(meshPtFile);
	while (!fin.eof())
	{
		fin >> x;
		fin >> y;
		fin >> z;
		temp.upd(x, y, z);
		if (mpt.size() == 0)
			mpt.resize(10);
		else if (mpt.size() == mpt.capacity())
			mpt.resize(mpt.size() * 3 / 2);
		mpt.push_back(temp);
	}
	fin.close();

}
void Mesh::chgMeshAdd3(string meshAdd3File)
{
	using std::ifstream;
	int add1, add2, add3;
	meshAdd temp;
	ifstream fin(meshAdd3File);
	while (!fin.eof())
	{
		fin >> add1;
		fin >> add2;
		fin >> add3;
		temp.upd(add1, add2, add3);
		if (mad.size() == 0)
			mad.resize(10);
		else if (mad.size() == mad.capacity())
			mad.resize(mad.size() * 3 / 2);
		mad.push_back(temp);
	}
	fin.close();

}
void Mesh::chgMeshAdd4(string meshAdd4File)
{
	using std::ifstream;
	int add1, add2, add3, add4;
	meshAdd temp;
	ifstream fin(meshAdd4File);
	while (!fin.eof())
	{
		fin >> add1;
		fin >> add2;
		fin >> add3;
		fin >> add4;
		temp.upd(add1, add2, add3,add4);
		if (mad.size() == 0)
			mad.resize(10);
		else if (mad.size() == mad.capacity())
			mad.resize(mad.size() * 3 / 2);
		mad.push_back(temp);
	}
	fin.close();

}