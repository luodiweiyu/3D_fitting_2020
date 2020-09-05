#pragma once
#include<string>
#include"../Geometry/Point.h"
using std::string;

//��ȡ�����ļ�
//scatterFilename ɢ���ļ���
//meshPointFilename ����ڵ������ļ���
//unsMeshAddFilename ����������ڵ���Ϣ�ļ���
//strMeshAddFilename �ı�������ڵ���Ϣ�ļ���
//sphereCenter ͷ�����Դ��Ϣ
//axisEnd      �߹�Դ��������Ϣ

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
