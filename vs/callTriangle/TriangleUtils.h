#pragma once

#include <string>
#include <vector>

#include <osg/Vec2d>

/**
 * 三角化工具类.
 */
class TriangleUtils
{
public:
	static bool triMesh(
		const std::vector<std::vector<osg::Vec2d>>& polygon,
		const std::string& offFile,
		const char* szOption = "pzQ");

};