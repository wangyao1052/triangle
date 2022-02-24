#include <iostream>
#include <vector>

#include "clipper/clipper.hpp"
#include "triangle.h"

#include "clipperTest.h"
#include "ClipperUtils.h"
#include "TriangleUtils.h"

bool ClipperTest::unionA()
{
	//
	std::vector<std::vector<osg::Vec2d>> polys1;
	polys1.resize(1);
	polys1[0].push_back(osg::Vec2d(0.0, 0.0));
	polys1[0].push_back(osg::Vec2d(100.0, 0.0));
	polys1[0].push_back(osg::Vec2d(100.0, 100.0));
	polys1[0].push_back(osg::Vec2d(0.0, 100.0));
	if (!TriangleUtils::triMesh(polys1, "unionA-1.off"))
	{
		std::cout << "error: ClipperTest::unionA triMesh polys1 failed!" << std::endl;
		return false;
	}
	//
	std::vector<std::vector<osg::Vec2d>> polys2;
	polys2.resize(1);
	polys2[0].push_back(osg::Vec2d(60.0, 20.0));
	polys2[0].push_back(osg::Vec2d(140.0, 20.0));
	polys2[0].push_back(osg::Vec2d(140.0, 50.0));
	polys2[0].push_back(osg::Vec2d(60.0, 50.0));
	if (!TriangleUtils::triMesh(polys2, "unionA-2.off"))
	{
		std::cout << "error: ClipperTest::unionA triMesh polys2 failed!" << std::endl;
		return false;
	}
	//
	std::vector<std::vector<osg::Vec2d>> polysOut;
	bool ret = ClipperUtils::unions(polys1, polys2, polysOut);
	if (!ret)
	{
		std::cout << "error: ClipperTest::unionA unions failed!" << std::endl;
		return false;
	}
	if (!TriangleUtils::triMesh(polysOut, "unionA-3.off"))
	{
		std::cout << "error: ClipperTest::unionA triMesh polysOut failed!" << std::endl;
		return false;
	}

	return true;
}

bool ClipperTest::intersectionA()
{
	//
	std::vector<std::vector<osg::Vec2d>> polys1;
	polys1.resize(1);
	polys1[0].push_back(osg::Vec2d(0.0, 0.0));
	polys1[0].push_back(osg::Vec2d(100.0, 0.0));
	polys1[0].push_back(osg::Vec2d(100.0, 100.0));
	polys1[0].push_back(osg::Vec2d(0.0, 100.0));
	if (!TriangleUtils::triMesh(polys1, "intersectionA-1.off"))
	{
		std::cout << "error: ClipperTest::intersectionA triMesh polys1 failed!" << std::endl;
		return false;
	}
	//
	std::vector<std::vector<osg::Vec2d>> polys2;
	polys2.resize(1);
	polys2[0].push_back(osg::Vec2d(60.0, 20.0));
	polys2[0].push_back(osg::Vec2d(140.0, 20.0));
	polys2[0].push_back(osg::Vec2d(140.0, 50.0));
	polys2[0].push_back(osg::Vec2d(60.0, 50.0));
	if (!TriangleUtils::triMesh(polys2, "intersectionA-2.off"))
	{
		std::cout << "error: ClipperTest::intersectionA triMesh polys2 failed!" << std::endl;
		return false;
	}
	//
	std::vector<std::vector<osg::Vec2d>> polysOut;
	bool ret = ClipperUtils::intersections(polys1, polys2, polysOut);
	if (!ret)
	{
		std::cout << "error: ClipperTest::intersectionA intersections failed!" << std::endl;
		return false;
	}
	if (!TriangleUtils::triMesh(polysOut, "intersectionA-3.off"))
	{
		std::cout << "error: ClipperTest::intersectionA triMesh polysOut failed!" << std::endl;
		return false;
	}

	return true;
}

bool ClipperTest::differenceA()
{
	//
	std::vector<std::vector<osg::Vec2d>> polys1;
	polys1.resize(1);
	polys1[0].push_back(osg::Vec2d(0.0, 0.0));
	polys1[0].push_back(osg::Vec2d(100.0, 0.0));
	polys1[0].push_back(osg::Vec2d(100.0, 100.0));
	polys1[0].push_back(osg::Vec2d(0.0, 100.0));
	if (!TriangleUtils::triMesh(polys1, "differenceA-1.off"))
	{
		std::cout << "error: ClipperTest::differenceA triMesh polys1 failed!" << std::endl;
		return false;
	}
	//
	std::vector<std::vector<osg::Vec2d>> polys2;
	polys2.resize(1);
	polys2[0].push_back(osg::Vec2d(60.0, 20.0));
	polys2[0].push_back(osg::Vec2d(140.0, 20.0));
	polys2[0].push_back(osg::Vec2d(140.0, 50.0));
	polys2[0].push_back(osg::Vec2d(60.0, 50.0));
	if (!TriangleUtils::triMesh(polys2, "differenceA-2.off"))
	{
		std::cout << "error: ClipperTest::differenceA triMesh polys2 failed!" << std::endl;
		return false;
	}
	//
	std::vector<std::vector<osg::Vec2d>> polysOut;
	bool ret = ClipperUtils::differences(polys1, polys2, polysOut);
	if (!ret)
	{
		std::cout << "error: ClipperTest::differenceA differences failed!" << std::endl;
		return false;
	}
	if (!TriangleUtils::triMesh(polysOut, "differenceA-3.off"))
	{
		std::cout << "error: ClipperTest::differenceA triMesh polysOut failed!" << std::endl;
		return false;
	}

	return true;
}

bool ClipperTest::unionHole()
{
	//
	std::vector<std::vector<osg::Vec2d>> polys1;
	polys1.resize(2);
	{
		polys1[0].push_back(osg::Vec2d(0.0, 0.0));
		polys1[0].push_back(osg::Vec2d(100.0, 0.0));
		polys1[0].push_back(osg::Vec2d(100.0, 100.0));
		polys1[0].push_back(osg::Vec2d(0.0, 100.0));
	}
	{
		polys1[1].push_back(osg::Vec2d(20.0, 60.0));
		polys1[1].push_back(osg::Vec2d(20.0, 80.0));
		polys1[1].push_back(osg::Vec2d(50.0, 80.0));
		polys1[1].push_back(osg::Vec2d(50.0, 60.0));
	}
	
	if (!TriangleUtils::triMesh(polys1, "unionHole-1.off"))
	{
		std::cout << "error: ClipperTest::unionHole triMesh polys1 failed!" << std::endl;
		return false;
	}
	//
	std::vector<std::vector<osg::Vec2d>> polys2;
	polys2.resize(1);
	{
		polys2[0].push_back(osg::Vec2d(40.0, 40.0));
		polys2[0].push_back(osg::Vec2d(70.0, 40.0));
		polys2[0].push_back(osg::Vec2d(70.0, 72.0));
		polys2[0].push_back(osg::Vec2d(40.0, 72.0));
	}
	if (!TriangleUtils::triMesh(polys2, "unionHole-2.off"))
	{
		std::cout << "error: ClipperTest::unionHole triMesh polys2 failed!" << std::endl;
		return false;
	}
	//
	std::vector<std::vector<osg::Vec2d>> polysOut;
	bool ret = ClipperUtils::unions(polys1, polys2, polysOut);
	if (!ret)
	{
		std::cout << "error: ClipperTest::unionHole unions failed!" << std::endl;
		return false;
	}
	if (!TriangleUtils::triMesh(polysOut, "unionHole-3.off"))
	{
		std::cout << "error: ClipperTest::unionHole triMesh polysOut failed!" << std::endl;
		return false;
	}

	return true;
}

bool ClipperTest::intersectionHole()
{
	//
	std::vector<std::vector<osg::Vec2d>> polys1;
	polys1.resize(2);
	{
		polys1[0].push_back(osg::Vec2d(0.0, 0.0));
		polys1[0].push_back(osg::Vec2d(100.0, 0.0));
		polys1[0].push_back(osg::Vec2d(100.0, 100.0));
		polys1[0].push_back(osg::Vec2d(0.0, 100.0));
	}
	{
		polys1[1].push_back(osg::Vec2d(20.0, 60.0));
		polys1[1].push_back(osg::Vec2d(20.0, 80.0));
		polys1[1].push_back(osg::Vec2d(50.0, 80.0));
		polys1[1].push_back(osg::Vec2d(50.0, 60.0));
	}

	if (!TriangleUtils::triMesh(polys1, "intersectionHole-1.off"))
	{
		std::cout << "error: ClipperTest::intersectionHole triMesh polys1 failed!" << std::endl;
		return false;
	}
	//
	std::vector<std::vector<osg::Vec2d>> polys2;
	polys2.resize(1);
	{
		polys2[0].push_back(osg::Vec2d(40.0, 40.0));
		polys2[0].push_back(osg::Vec2d(70.0, 40.0));
		polys2[0].push_back(osg::Vec2d(70.0, 72.0));
		polys2[0].push_back(osg::Vec2d(40.0, 72.0));
	}
	if (!TriangleUtils::triMesh(polys2, "intersectionHole-2.off"))
	{
		std::cout << "error: ClipperTest::intersectionHole triMesh polys2 failed!" << std::endl;
		return false;
	}
	//
	std::vector<std::vector<osg::Vec2d>> polysOut;
	bool ret = ClipperUtils::intersections(polys1, polys2, polysOut);
	if (!ret)
	{
		std::cout << "error: ClipperTest::intersectionHole intersections failed!" << std::endl;
		return false;
	}
	if (!TriangleUtils::triMesh(polysOut, "intersectionHole-3.off"))
	{
		std::cout << "error: ClipperTest::intersectionHole triMesh polysOut failed!" << std::endl;
		return false;
	}

	return true;
}

bool ClipperTest::differenceHole()
{
	//
	std::vector<std::vector<osg::Vec2d>> polys1;
	polys1.resize(2);
	{
		polys1[0].push_back(osg::Vec2d(0.0, 0.0));
		polys1[0].push_back(osg::Vec2d(100.0, 0.0));
		polys1[0].push_back(osg::Vec2d(100.0, 100.0));
		polys1[0].push_back(osg::Vec2d(0.0, 100.0));
	}
	{
		polys1[1].push_back(osg::Vec2d(20.0, 60.0));
		polys1[1].push_back(osg::Vec2d(20.0, 80.0));
		polys1[1].push_back(osg::Vec2d(50.0, 80.0));
		polys1[1].push_back(osg::Vec2d(50.0, 60.0));
	}
	if (!TriangleUtils::triMesh(polys1, "differenceHole-1.off"))
	{
		std::cout << "error: ClipperTest::differenceHole triMesh polys1 failed!" << std::endl;
		return false;
	}

	//
	std::vector<std::vector<osg::Vec2d>> polys2;
	polys2.resize(1);
	{
		polys2[0].push_back(osg::Vec2d(40.0, 40.0));
		polys2[0].push_back(osg::Vec2d(70.0, 40.0));
		polys2[0].push_back(osg::Vec2d(70.0, 72.0));
		polys2[0].push_back(osg::Vec2d(40.0, 72.0));
	}
	if (!TriangleUtils::triMesh(polys2, "differenceHole-2.off"))
	{
		std::cout << "error: ClipperTest::differenceHole triMesh polys2 failed!" << std::endl;
		return false;
	}

	//
	std::vector<std::vector<osg::Vec2d>> polysOut;
	bool ret = ClipperUtils::differences(polys1, polys2, polysOut);
	if (!ret)
	{
		std::cout << "error: ClipperTest::differenceHole differences failed!" << std::endl;
		return false;
	}
	if (!TriangleUtils::triMesh(polysOut, "differenceHole-3.off"))
	{
		std::cout << "error: ClipperTest::differenceHole triMesh polysOut failed!" << std::endl;
		return false;
	}

	return true;
}

bool ClipperTest::unionHui()
{
	//
	std::vector<std::vector<osg::Vec2d>> polys1;
	polys1.resize(1);
	{
		polys1[0].push_back(osg::Vec2d(0.0, 50.0));
		polys1[0].push_back(osg::Vec2d(30.0, 50.0));
		polys1[0].push_back(osg::Vec2d(30.0, 70.0));
		polys1[0].push_back(osg::Vec2d(70.0, 70.0));
		polys1[0].push_back(osg::Vec2d(70.0, 50.0));
		polys1[0].push_back(osg::Vec2d(100.0, 50.0));
		polys1[0].push_back(osg::Vec2d(100.0, 100.0));
		polys1[0].push_back(osg::Vec2d(0.0, 100.0));
	}
	if (!TriangleUtils::triMesh(polys1, "unionHui-1.off"))
	{
		std::cout << "error: ClipperTest::unionHui triMesh polys1 failed!" << std::endl;
		return false;
	}

	//
	std::vector<std::vector<osg::Vec2d>> polys2;
	polys2.resize(1);
	{
		polys2[0].push_back(osg::Vec2d(0.0, 0.0));
		polys2[0].push_back(osg::Vec2d(100.0, 0.0));
		polys2[0].push_back(osg::Vec2d(100.0, 50.0));
		polys2[0].push_back(osg::Vec2d(70.0, 50.0));
		polys2[0].push_back(osg::Vec2d(70.0, 30.0));
		polys2[0].push_back(osg::Vec2d(30.0, 30.0));
		polys2[0].push_back(osg::Vec2d(30.0, 50.0));
		polys2[0].push_back(osg::Vec2d(0.0, 50.0));
	}
	if (!TriangleUtils::triMesh(polys2, "unionHui-2.off"))
	{
		std::cout << "error: ClipperTest::unionHui triMesh polys2 failed!" << std::endl;
		return false;
	}

	//
	//
	std::vector<std::vector<osg::Vec2d>> polysOut;
	bool ret = ClipperUtils::unions(polys1, polys2, polysOut);
	// 存在的问题:TODO...
	// 返回的polysOut中,孔为polysOut[0],外边界为polysOut[1];这个顺序显然是反的,该如何解决?
	// 有时间研究下ClipperLib的源码.
	if (!ret)
	{
		std::cout << "error: ClipperTest::unionHui unions failed!" << std::endl;
		return false;
	}
	if (!TriangleUtils::triMesh(polysOut, "unionHui-3.off"))
	{
		std::cout << "error: ClipperTest::unionHui triMesh polysOut failed!" << std::endl;
		return false;
	}

	return true;
}

bool ClipperTest::test()
{
	//
	std::vector<std::vector<osg::Vec2d>> polys1;
	polys1.resize(2);
	{
		polys1[0].push_back(osg::Vec2d(0.0, 0.0));
		polys1[0].push_back(osg::Vec2d(10.0, 0.0));
		polys1[0].push_back(osg::Vec2d(10.0, 10.0));
		polys1[0].push_back(osg::Vec2d(0.0, 10.0));
	}
	{
		polys1[1].push_back(osg::Vec2d(20.0, 0.0));
		polys1[1].push_back(osg::Vec2d(30.0, 0.0));
		polys1[1].push_back(osg::Vec2d(30.0, 10.0));
		polys1[1].push_back(osg::Vec2d(20.0, 10.0));
	}

	//
	std::vector<std::vector<osg::Vec2d>> polys2;
	polys2.resize(1);
	{
		polys2[0].push_back(osg::Vec2d(40.0, 0.0));
		polys2[0].push_back(osg::Vec2d(50.0, 0.0));
		polys2[0].push_back(osg::Vec2d(50.0, 10.0));
		polys2[0].push_back(osg::Vec2d(40.0, 10.0));
	}

	//
	std::vector<std::vector<osg::Vec2d>> polysOut;
	bool ret = ClipperUtils::unions(polys1, polys2, polysOut);

	return true;
}

void ClipperTest::testBoolLine()
{
	/*
	//
	std::vector<osg::Vec2d> polygon;
	{
		//polygon.push_back(Vec2(0.0, 0.0));
		//polygon.push_back(Vec2(100.0, 0.0));
		//polygon.push_back(Vec2(100.0, 100.0));
		//polygon.push_back(Vec2(0.0, 100.0));
	}
	{
		polygon.push_back(osg::Vec2d(0.0, 0.0));
		polygon.push_back(osg::Vec2d(100.0, 0.0));
		polygon.push_back(osg::Vec2d(100.0, 100.0));
		polygon.push_back(osg::Vec2d(80.0, 100.0));
		polygon.push_back(osg::Vec2d(80.0, 40.0));
		polygon.push_back(osg::Vec2d(30.0, 40.0));
		polygon.push_back(osg::Vec2d(30.0, 100.0));
		polygon.push_back(osg::Vec2d(0.0, 100.0));
	}
	
	//
	ClipperLib::Paths paths1(1);
	for (const osg::Vec2d& pnt : polygon)
	{
		paths1[0].push_back(ClipperUtils::vecToIntPnt(pnt));
	}

	//
	std::vector<osg::Vec2d> lineSegment;
	{
		//lineSegment.push_back(osg::Vec2d(-200.0, 0.0));
		//lineSegment.push_back(osg::Vec2d(10.0, 0.0));
	}
	{
		//lineSegment.push_back(osg::Vec2d(-200.0, 50.0));
		//lineSegment.push_back(osg::Vec2d(200.0, 50.0));
	}
	{
		//lineSegment.push_back(osg::Vec2d(-200.0, -10.0));
		//lineSegment.push_back(osg::Vec2d(200.0, -10.0));
	}
	{
		//lineSegment.push_back(osg::Vec2d(-200.0, 0.0));
		//lineSegment.push_back(osg::Vec2d(200.0, 0.0));
	}
	{
		//lineSegment.push_back(osg::Vec2d(-200.0, 100.0));
		//lineSegment.push_back(osg::Vec2d(200.0, 100.0));
	}
	{
		lineSegment.push_back(osg::Vec2d(20.0, 40.0));
		lineSegment.push_back(osg::Vec2d(90.0, 40.0));
	}
	
	//
	ClipperLib::Paths paths2(1);
	for (const osg::Vec2d& pnt : lineSegment)
	{
		paths2[0].push_back(ClipperUtils::vecToIntPnt(pnt));
	}

	//
	ClipperLib::Clipper clipper;
	clipper.AddPaths(paths2, ClipperLib::PolyType::ptSubject, false);
	clipper.AddPaths(paths1, ClipperLib::PolyType::ptClip, true);
	ClipperLib::Paths solution;
	ClipperLib::PolyTree polytree;
	bool ret = clipper.Execute(ClipperLib::ClipType::ctIntersection, polytree,
		ClipperLib::PolyFillType::pftNonZero,
		ClipperLib::PolyFillType::pftNonZero);

	if (ret)
	{
		int num = polytree.Total();
		if (num <= 0) return;
		ClipperLib::PolyNode* first = polytree.GetFirst();
		ClipperLib::PolyNode* node = first;
		while (node)
		{
			const ClipperLib::Path& path = node->Contour;
			node = node->GetNext();
		}
	}

	//
	int a = 100;
	*/
}