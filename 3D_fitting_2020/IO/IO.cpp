#include"IO.h"
#include<fstream>
CtrlStr::CtrlStr()
{
	scatterFilename = "scatter.dat";
	meshPointFilename = "meshPoint.dat";
	unsMeshAddFilename = "meshAdd3.dat";
	strMeshAddFilename = "meshAdd4.dat";
	sphereCenter.upd(0, 0, 0);
	axisEnd.upd(0, 0, 0);
}
CtrlStr::CtrlStr(string ctrlFileName)
{
	using std::ifstream;
	using std::getline;
	double x, y, z;
	ifstream fin(ctrlFileName);
	string annotation;
	getline(fin, annotation);
	fin >> scatterFilename;
	getline(fin, annotation);
	getline(fin, annotation);
	fin >> meshPointFilename;
	getline(fin, annotation);
	getline(fin, annotation);
	fin >> unsMeshAddFilename;
	getline(fin, annotation);
	getline(fin, annotation);
	fin >> strMeshAddFilename;
	getline(fin, annotation);
	getline(fin, annotation);
	fin >> x;
	fin >> y;
	fin >> z;
	sphereCenter.upd(x, y, z);
	getline(fin, annotation);
	getline(fin, annotation);
	fin >> x;
	fin >> y;
	fin >> z;
	axisEnd.upd(x, y, z);
	fin.close();
}
void inputScatter(vector<Point>& scatter, string filename)
{
	using std::ifstream;
	double x, y, z;
	Point temp;
	ifstream fin(filename);
	while (!fin.eof())
	{
		fin >> x;
		fin >> y;
		fin >> z;
		temp.upd(x,y,z);
		if (scatter.size() == 0)
			scatter.reserve(10);
		else if (scatter.size() == scatter.capacity())
			scatter.reserve(scatter.size()*3 / 2);
		scatter.push_back(temp);
	}
	fin.close();
}
void inputMeshPoint(vector<Point>& meshPoint, string filename)
{
	using std::ifstream;
	double x, y, z;
	Point temp;
	ifstream fin(filename);
	while (!fin.eof())
	{
		fin >> x;
		fin >> y;
		fin >> z;
		temp.upd(x, y, z);
		if (meshPoint.size() == 0)
			meshPoint.reserve(10);
		else if (meshPoint.size() == meshPoint.capacity())
			meshPoint.reserve(meshPoint.size() * 3 / 2);
		meshPoint.push_back(temp);
	}
	fin.close();

}