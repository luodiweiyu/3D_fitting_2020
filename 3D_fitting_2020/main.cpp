#include"IO/IO.h"
#include"Geometry/Line.h"
#include"Geometry/Zone.h"
#include"Geometry/mesh.h"
int main()
{
	CtrlStr ctrlstr("ctrl.txt");
	Mesh meshOri;//ԭʼ����
	meshOri.initMesh(ctrlstr.meshPointFilename, ctrlstr.unsMeshAddFilename, ctrlstr.strMeshAddFilename);
	vector<ZoneFit> znfit;//����ͬʱ��������������������ı�����������

	return 0;
}