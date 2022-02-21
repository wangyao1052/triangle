#pragma once

#include <vector>
#include <string>

#include <osg/Vec2>
#include <osg/Vec2d>
#include <osg/Vec2f>
#include <osg/Vec3>
#include <osg/Vec3d>
#include <osg/Vec3f>

#include <clipper/clipper.hpp>

#include "triangle.h"

class ClipperTest
{
public:
	// 测试布尔并
	static bool unionA();
	// 测试布尔交
	static bool intersectionA();
	// 测试布尔差
	static bool differenceA();

	static void testBoolLine();
};
