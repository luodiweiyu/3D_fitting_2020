#include"IO/IO.h"
#include"Geometry/Line.h"
#include"Geometry/Zone.h"
#include"Geometry/mesh.h"
int main()
{
	CtrlStr ctrlstr("ctrl.txt");
	vector<Point> scatter;//ɢ��
	Mesh mesh;
	mesh.initMesh(ctrlstr.meshPointFilename, ctrlstr.unsMeshAddFilename, ctrlstr.strMeshAddFilename);
	vector<zoneLine> zoneline;//�߽��ߣ�������λ����������Ļ����ߵ�����
	vector<Zone> zone;//����ͬʱ��������������������ı�����������
	zoneLine zl(scatter[0], scatter[1]);
	return 0;
}