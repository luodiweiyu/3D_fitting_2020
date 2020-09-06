#pragma once
#include<vector>
#include"string"
#include"Point.h"
using std::vector;
using std::string;
class Mesh
{
private:
	vector<Point> mpt;
	vector<meshAdd> mad;
public:
	Mesh() {};
	void initMesh(string meshPtFile, string meshAdd3File, string meshAdd4File);//从网格里初始化网格
	void chgMeshPt(string meshPtFile);//修改网格点
	void chgMeshAdd3(string meshAdd3File);//修改三角形网格编号
	void chgMeshAdd4(string meshAdd4File);//修改四边形网格编号
	int ptNum() { return mpt.size(); };
	int elementNum() { return mad.size(); };
	Point& pt(int i) { return mpt[i]; };
	meshAdd& maddr(int i) { return mad[i]; };
};