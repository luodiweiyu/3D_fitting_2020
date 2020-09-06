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
	void initMesh(string meshPtFile, string meshAdd3File, string meshAdd4File);//���������ʼ������
	void chgMeshPt(string meshPtFile);//�޸������
	void chgMeshAdd3(string meshAdd3File);//�޸�������������
	void chgMeshAdd4(string meshAdd4File);//�޸��ı���������
	int ptNum() { return mpt.size(); };
	int elementNum() { return mad.size(); };
	Point& pt(int i) { return mpt[i]; };
	meshAdd& maddr(int i) { return mad[i]; };
};