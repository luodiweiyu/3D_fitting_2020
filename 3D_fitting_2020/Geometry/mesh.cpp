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
		if (meshpoint.empty())
			meshpoint.reserve(10);
		else if (meshpoint.size() == meshpoint.capacity())
			meshpoint.reserve(meshpoint.size() * 3 / 2);
		meshpoint.push_back(temp);
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
		temp.upd(add1 - 1, add2 - 1, add3 - 1);
		if (meshaddr.empty())
			meshaddr.reserve(10);
		else if (meshaddr.size() == meshaddr.capacity())
			meshaddr.reserve(meshaddr.size() * 3 / 2);
		meshaddr.push_back(temp);
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
		temp.upd(add1 - 1, add2 - 1, add3 - 1, add4 - 1);
		if (meshaddr.empty())
			meshaddr.reserve(10);
		else if (meshaddr.size() == meshaddr.capacity())
			meshaddr.reserve(meshaddr.size() * 3 / 2);
		meshaddr.push_back(temp);
	}
	fin.close();

}

void Mesh::output(string filename)
{
	ofstream fout(filename);
	fout << "variables = x, y, z" << endl;
	int elemenNum = 0;
	for (int i = 0; i < meshaddr.size(); i++)
	{
		if (meshaddr[i].pt_num() == 3)
			elemenNum++;
		else if (meshaddr[i].pt_num() == 4)
			elemenNum = elemenNum + 2;
	}
	fout << "zone N = " << meshpoint.size() << ", E = " << elemenNum << " F = FEPOINT, ET = TRIANGLE" << endl;
	for (int i = 0; i < meshpoint.size(); i++)
	{
		fout << meshpoint[i].x() << "   " << meshpoint[i].y() << "   " << meshpoint[i].z() << endl;
	}
	for (int i = 0; i < meshaddr.size(); i++)
	{
		if (meshaddr[i].pt_num() == 3)
			fout << meshaddr[i].pt_addr(0) + 1 << "   " << meshaddr[i].pt_addr(1) + 1 << "   " << meshaddr[i].pt_addr(2) + 1 << endl;
		else if (meshaddr[i].pt_num() == 4)
		{
			fout << meshaddr[i].pt_addr(0) + 1 << "   " << meshaddr[i].pt_addr(1) + 1 << "   " << meshaddr[i].pt_addr(2) + 1 << endl;
			fout << meshaddr[i].pt_addr(0) + 1 << "   " << meshaddr[i].pt_addr(3) + 1 << "   " << meshaddr[i].pt_addr(2) + 1 << endl;
		}
		else
			fout << "error" << endl;
	}
	fout.close();
}

int Mesh::addMeshPoint(Point& pt)
{
	int id = searchMehsPoint(pt);
	if (id < 0)//如果该点不在网格内，在meshpoint中添加该点，返回其编号
	{
		meshpoint.push_back(pt);
		return meshpoint.size() - 1;
	}
	else//如果在网格内，直接返回其编号
		return id;
}

int Mesh::addMeshAddr(meshAdd& addr)//未添加搜索功能，暂时不需要，可添加，防止重合网格
{
	meshaddr.push_back(addr);
	return meshaddr.size() - 1;
}

//在所有网格点搜索pt
//return -1  pt不在mesh内
//return >1  pt在mesh内，返回值为其序号
int Mesh::searchMehsPoint(Point& pt)
{
	int i;
	for (i = 0; i < meshpoint.size(); i++)
	{
		if (meshpoint[i] == pt)
			return i;
	}
	return -1;
}
