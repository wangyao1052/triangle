#include <iostream>
#include <fstream>
#include <iomanip>

#include "triangle.h"
#include "TriangleUtils.h"

#include "clipperTest.h"
#include "triangleTest.h"

int main()
{
	//
	TriangleTest::hole1();
	//TriangleTest::mayCrash_duplicatedPoints();

	//
	ClipperTest::unionA();
	ClipperTest::intersectionA();
	ClipperTest::differenceA();

	return 0;

	//
	triangulateio in;
	//
	in.numberofpoints = 8;
	in.pointlist = (REAL*)malloc(size_t(in.numberofpoints) * 2 * sizeof(REAL));
	in.pointlist[0] = 0.0;
	in.pointlist[1] = 0.0;
	in.pointlist[2] = 10.0;
	in.pointlist[3] = 0.0;
	in.pointlist[4] = 10.0;
	in.pointlist[5] = 10.0;
	in.pointlist[6] = 0.0;
	in.pointlist[7] = 10.0;
	in.pointlist[8] = 4.0;
	in.pointlist[9] = 2.0;
	in.pointlist[10] = 6.0;
	in.pointlist[11] = 2.0;
	in.pointlist[12] = 6.0;
	in.pointlist[13] = 4.0;
	in.pointlist[14] = 4.0;
	in.pointlist[15] = 4.0;
	//
	in.numberofsegments = 8;
	in.segmentlist = (int*)malloc(size_t(in.numberofsegments) * 2 * sizeof(int));
	in.segmentlist[0] = 0;
	in.segmentlist[1] = 1;
	in.segmentlist[2] = 1;
	in.segmentlist[3] = 2;
	in.segmentlist[4] = 2;
	in.segmentlist[5] = 3;
	in.segmentlist[6] = 3;
	in.segmentlist[7] = 0;
	in.segmentlist[8] = 4;
	in.segmentlist[9] = 5;
	in.segmentlist[10] = 5;
	in.segmentlist[11] = 6;
	in.segmentlist[12] = 6;
	in.segmentlist[13] = 7;
	in.segmentlist[14] = 7;
	in.segmentlist[15] = 4;
	//
	in.numberofholes = 1;
	in.holelist = (REAL*)malloc(size_t(in.numberofholes) * 2 * sizeof(REAL));
	in.holelist[0] = 5.0;
	in.holelist[1] = 3.0;

	//
	triangulateio out;

	//
	char szOption[100] = "pzQqa0.5";
	triangulate(szOption, &in, &out, nullptr);

	// 输出.off文件
	std::ofstream file("wangyao.off", std::ios::out);
	file << std::setprecision(15);
	file << "OFF\n";
	file << out.numberofpoints << " " << out.numberoftriangles << " " << out.numberofedges << "\n";
	for (int i = 0; i < out.numberofpoints; ++i)
	{
		file << out.pointlist[2 * i] << " " << out.pointlist[2 * i + 1] << " " << 0.0 << "\n";
	}
	for (int i = 0; i < out.numberoftriangles; ++i)
	{
		file << 3 << " " << out.trianglelist[3 * i] << " " << out.trianglelist[3 * i + 1] << " " << out.trianglelist[3 * i + 2] << "\n";
	}
	file.close();

	//
	free(in.pointlist);
	free(in.segmentlist);
	free(in.holelist);
	free(out.pointlist);
	free(out.pointmarkerlist);
	free(out.segmentlist);
	free(out.segmentmarkerlist);
	free(out.trianglelist);

	return 0;
}