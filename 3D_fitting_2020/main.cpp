#include"IO/IO.h"
#include"Geometry/Line.h"
#include"Geometry/Zone.h"
#include"Geometry/mesh.h"
int main()
{
	CtrlStr ctrlstr("ctrl.txt");
	vector<Point> scatter;//散点
	Mesh mesh;
	mesh.initMesh(ctrlstr.meshPointFilename, ctrlstr.unsMeshAddFilename, ctrlstr.strMeshAddFilename);
	vector<zoneLine> zoneline;//边界线，即各单位网格点与球心或轴线的连线
	vector<Zone> zone;//区域，同时包含三角形网格区域和四边形网格区域
	zoneLine zl(scatter[0], scatter[1]);
	return 0;
}