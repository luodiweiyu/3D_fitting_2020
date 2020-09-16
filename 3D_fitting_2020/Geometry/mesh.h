#pragma once
#include<vector>
#include"string"
#include"Point.h"
using std::vector;
using std::string;
//������
//�������е������ meshpoint
//��������Ԫ��Ӧ����meshpoint �еı�� meshaddr
class Mesh
{
private:
	vector<Point> meshpoint;
	vector<meshAdd> meshaddr;
public:
	Mesh() =default;
	void initMesh(string meshPtFile, string meshAdd3File, string meshAdd4File);//���ļ����ʼ������
	void chgMeshPt(string meshPtFile);//�޸������
	void chgMeshAdd3(string meshAdd3File);//�޸�������������
	void chgMeshAdd4(string meshAdd4File);//�޸��ı���������
	int ptNum() { return meshpoint.size(); };
	int elementNum() { return meshaddr.size(); };
	Point* pt(int i) { return &meshpoint[i]; };
	meshAdd maddr(int i) { return meshaddr[i]; };
	void output(string filename);
	int addMeshPoint(Point& pt);//��������
	int addMeshAddr(meshAdd& addr);//���������Ϣ
	int searchMehsPoint(Point& pt);//���������
};