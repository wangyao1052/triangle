#pragma once

#include <vector>
#include <cmath>

#include <osg/Vec2d>
#include <osg/Vec3d>

#include "clipper/clipper.hpp"

class ClipperUtils
{
public:
	// 布尔运算:并集
	static bool unions(
		const std::vector<std::vector<osg::Vec2d>>& polys1,
		const std::vector<std::vector<osg::Vec2d>>& polys2,
		std::vector<std::vector<osg::Vec2d>>& polysOut);

	// 布尔运算:交集
	static bool intersections(
		const std::vector<std::vector<osg::Vec2d>>& polys1,
		const std::vector<std::vector<osg::Vec2d>>& polys2,
		std::vector<std::vector<osg::Vec2d>>& polysOut);

	// 布尔运算:差集
	static bool differences(
		const std::vector<std::vector<osg::Vec2d>>& polys1,
		const std::vector<std::vector<osg::Vec2d>>& polys2,
		std::vector<std::vector<osg::Vec2d>>& polysOut);

	/**
	* 多段线与多边形求交集.
	*
	* @param[in] polys1 多段线.
	* @param[in] polys2 多边形.
	* @param[out] polysOut 输出的多段线.
	* @return 执行成功返回true;执行失败返回false.
	*/
	static bool intersectionsPolylinesAndPolygons(
		const std::vector<std::vector<osg::Vec2d>>& polys1,
		const std::vector<std::vector<osg::Vec2d>>& polys2,
		std::vector<std::vector<osg::Vec2d>>& polysOut);

private:
	// 布尔运算
	static bool boolean(
		ClipperLib::ClipType type,
		const std::vector<std::vector<osg::Vec2d>>& polys1,
		const std::vector<std::vector<osg::Vec2d>>& polys2,
		std::vector<std::vector<osg::Vec2d>>& polysOut);

	//
	static void polygons2ClipperPaths(
		const std::vector<std::vector<osg::Vec2d>>& polys,
		ClipperLib::Paths& paths);
	static void polygons2ClipperPaths(
		const std::vector<osg::Vec2d>& poly,
		ClipperLib::Paths& paths);
	//
	static void clipperPaths2Polygons(
		const ClipperLib::Paths& paths,
		std::vector<std::vector<osg::Vec2d>>& polys);

	//
	static inline ClipperLib::IntPoint vec2IntPoint(const osg::Vec2d& vec);
	static inline osg::Vec2d intPoint2Vec2(const ClipperLib::IntPoint& intPnt);
	//
	static const long long sScale;
};

ClipperLib::IntPoint ClipperUtils::vec2IntPoint(const osg::Vec2d& vec)
{
	return ClipperLib::IntPoint(
		std::round(vec.x() * sScale), std::round(vec.y() * sScale));
}

osg::Vec2d ClipperUtils::intPoint2Vec2(const ClipperLib::IntPoint& intPnt)
{
	return osg::Vec2d(
		double(intPnt.X) / sScale, double(intPnt.Y) / sScale);
}