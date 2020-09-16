#pragma once
#include<vector>
#include"string"
#include"Point.h"
using std::vector;
using std::string;
//网格类
//储存所有的网格点 meshpoint
//各个网格单元对应的在meshpoint 中的编号 meshaddr
class Mesh
{
private:
	vector<Point> meshpoint;
	vector<meshAdd> meshaddr;
public:
	Mesh() =default;
	void initMesh(string meshPtFile, string meshAdd3File, string meshAdd4File);//从文件里初始化网格
	void chgMeshPt(string meshPtFile);//修改网格点
	void chgMeshAdd3(string meshAdd3File);//修改三角形网格编号
	void chgMeshAdd4(string meshAdd4File);//修改四边形网格编号
	int ptNum() { return meshpoint.size(); };
	int elementNum() { return meshaddr.size(); };
	Point* pt(int i) { return &meshpoint[i]; };
	meshAdd maddr(int i) { return meshaddr[i]; };
	void output(string filename);
	int addMeshPoint(Point& pt);//添加网格点
	int addMeshAddr(meshAdd& addr);//添加网格信息
	int searchMehsPoint(Point& pt);//搜索网格点
};