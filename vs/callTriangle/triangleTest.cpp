#include "triangleTest.h"
#include "TriangleUtils.h"


bool TriangleTest::hole1()
{
	std::vector<std::vector<osg::Vec2d>> polygons;
	polygons.resize(2);
	{
		polygons[0].push_back(osg::Vec2d(0.0, 0.0));
		polygons[0].push_back(osg::Vec2d(100.0, 0.0));
		polygons[0].push_back(osg::Vec2d(100.0, 100.0));
		polygons[0].push_back(osg::Vec2d(0.0, 100.0));
	}
	{
		polygons[1].push_back(osg::Vec2d(40.0, 40.0));
		polygons[1].push_back(osg::Vec2d(40.0, 60.0));
		polygons[1].push_back(osg::Vec2d(60.0, 60.0));
		polygons[1].push_back(osg::Vec2d(60.0, 40.0));
	}
	TriangleUtils::triMesh(polygons, "hole1.off");

	return true;
}