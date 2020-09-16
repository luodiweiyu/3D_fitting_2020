#include"IO/IO.h"
#include"Geometry/Line.h"
#include"Geometry/Zone.h"
#include"Geometry/mesh.h"
int main()
{
	CtrlStr ctrlstr("ctrl.txt");
	Mesh meshOri;//原始网格
	meshOri.initMesh(ctrlstr.meshPointFilename, ctrlstr.unsMeshAddFilename, ctrlstr.strMeshAddFilename);
	meshOri.output("meshOri.dat");
	ZoneFit znfit(ctrlstr.scatterFilename);//区域，同时包含三角形网格区域和四边形网格区域
	znfit.init(meshOri, ctrlstr.sphereCenter, ctrlstr.axisEnd);
	Mesh meshFit;
	znfit.genFitMesh(meshFit);
	meshFit.output("meshfit.dat");
	return 0;
}