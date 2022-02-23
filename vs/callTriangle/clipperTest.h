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

/**
 * ClipperLib测试.
 */
class ClipperTest
{
public:
	//
	// <1>多边形A
	// <2>多边形B
	// A4#-----------#A3
	//   |           |
	//   |    B4#----|-------#B3
	//   |      |    |       |
	//   |    B1#----|-------#B2
	//   |           |
	// A1#-----------#A2
	// 布尔并
	static bool unionA();
	// 布尔交
	static bool intersectionA();
	// 布尔差
	static bool differenceA();

	//
	// <1>多边形A内含有一个孔B
	// <2>多边形C
	// A4#----------------------#A3
	//   |                      |
	//   | B2#-------#B3        |
	//   |   |       |          |
	//   |   |  C4#--|-----#C3  |
	//   |   |    |  |     |    |
	//   | B1#----|--#B4   |    |
	//   |        |        |    |
	//   |      C1#--------#C2  |
	//   |                      |
	// A1#----------------------#A2
	// 布尔并
	static bool unionHole();
	// 布尔交
	static bool intersectionHole();
	// 布尔差
	static bool differenceHole();

	//
	static bool test();

	static void testBoolLine();
};
