#pragma once
#include<string>
#include"../Geometry/Point.h"
using std::string;

//读取控制文件
//scatterFilename 散点文件名
//meshPointFilename 网格节点坐标文件名
//unsMeshAddFilename 三角形网格节点信息文件名
//strMeshAddFilename 四边形网格节点信息文件名
//sphereCenter 头部点光源信息
//axisEnd      线光源结束处信息

class CtrlStr
{
public:
	string scatterFilename;
	string meshPointFilename;
	string unsMeshAddFilename;
	string strMeshAddFilename;
	Point sphereCenter;
	Point axisEnd;
	CtrlStr();
	CtrlStr(string ctrlFileName);
};
void inputScatter(vector<Point>& scatter, string filename);
void inputMeshPoint(vector<Point>& meshPoint, string filename);
//void inputMeshAdd(vector<Point>& meshPoint, string filename);
