#include "triangleTest.h"
#include "TriangleUtils.h"


bool TriangleTest::hole1()
{
	std::vector<std::vector<osg::Vec2d>> polygons;
	polygons.resize(2);
	// 外轮廓
	{
		polygons[0].push_back(osg::Vec2d(0.0, 0.0));
		polygons[0].push_back(osg::Vec2d(50.0, 0.0));
		polygons[0].push_back(osg::Vec2d(100.0, 0.0));
		polygons[0].push_back(osg::Vec2d(100.0, 100.0));
		polygons[0].push_back(osg::Vec2d(0.0, 100.0));
	}
	// 孔
	{
		polygons[1].push_back(osg::Vec2d(40.0, 40.0));
		polygons[1].push_back(osg::Vec2d(40.0, 60.0));
		polygons[1].push_back(osg::Vec2d(60.0, 60.0));
		polygons[1].push_back(osg::Vec2d(60.0, 40.0));
	}

	// Delaunay
	TriangleUtils::triMesh(polygons, "hole1.off");
	// CDT
	// q   --- no angles smaller than 20 degrees.
	// a10 --- maximum triangle area 10.
	TriangleUtils::triMesh(polygons, "hole1-cdt.off", "pzQqa10");

	return true;
}

bool TriangleTest::mayCrash_duplicatedPoints()
{
	// ok
	{
		//
		std::vector<std::vector<osg::Vec2d>> polygons;
		polygons.resize(1);
		polygons[0].push_back(osg::Vec2d(0.0, 0.0));
		polygons[0].push_back(osg::Vec2d(100.0, 0.0));
		polygons[0].push_back(osg::Vec2d(100.0, 0.0)); // 重复点,依然会正确三角剖分
		polygons[0].push_back(osg::Vec2d(100.0, 100.0));
		polygons[0].push_back(osg::Vec2d(0.0, 100.0));
		//
		TriangleUtils::triMesh(polygons, "crash_duplicatedPoints.off");
	}

	// crash
	{
		//
		std::vector<std::vector<osg::Vec2d>> polygons;
		polygons.resize(1);
		polygons[0].push_back(osg::Vec2d(0.0, 0.0));
		polygons[0].push_back(osg::Vec2d(100.0, 0.0));
		polygons[0].push_back(osg::Vec2d(100.0, 100.0));
		polygons[0].push_back(osg::Vec2d(0.0, 100.0));
		polygons[0].push_back(osg::Vec2d(0.0, 100.0)); // 重复点,导致crash
		//
		TriangleUtils::triMesh(polygons, "crash_duplicatedPoints.off");
	}

	return true;
}