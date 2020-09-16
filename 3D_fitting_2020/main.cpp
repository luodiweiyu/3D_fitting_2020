#include"IO/IO.h"
#include"Geometry/Line.h"
#include"Geometry/Zone.h"
#include"Geometry/mesh.h"
int main()
{
	CtrlStr ctrlstr("ctrl.txt");
	Mesh meshOri;//ԭʼ����
	meshOri.initMesh(ctrlstr.meshPointFilename, ctrlstr.unsMeshAddFilename, ctrlstr.strMeshAddFilename);
	meshOri.output("meshOri.dat");
	ZoneFit znfit(ctrlstr.scatterFilename);//����ͬʱ��������������������ı�����������
	znfit.init(meshOri, ctrlstr.sphereCenter, ctrlstr.axisEnd);
	Mesh meshFit;
	znfit.genFitMesh(meshFit);
	meshFit.output("meshfit.dat");
	return 0;
}