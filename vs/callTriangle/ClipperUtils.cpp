#include <cmath>

#include "ClipperUtils.h"
#include "clipper/clipper.hpp"

const long long ClipperUtils::sScale = 1e6;

bool ClipperUtils::unions(
	const std::vector<std::vector<osg::Vec2d>>& polys1,
	const std::vector<std::vector<osg::Vec2d>>& polys2,
	std::vector<std::vector<osg::Vec2d>>& polysOut)
{
	return ClipperUtils::boolean(ClipperLib::ClipType::ctUnion, polys1, polys2, polysOut);
}

bool ClipperUtils::intersections(
	const std::vector<std::vector<osg::Vec2d>>& polys1,
	const std::vector<std::vector<osg::Vec2d>>& polys2,
	std::vector<std::vector<osg::Vec2d>>& polysOut)
{
	return ClipperUtils::boolean(ClipperLib::ClipType::ctIntersection, polys1, polys2, polysOut);
}

bool ClipperUtils::differences(
	const std::vector<std::vector<osg::Vec2d>>& polys1,
	const std::vector<std::vector<osg::Vec2d>>& polys2,
	std::vector<std::vector<osg::Vec2d>>& polysOut)
{
	return ClipperUtils::boolean(ClipperLib::ClipType::ctDifference, polys1, polys2, polysOut);
}

bool ClipperUtils::boolean(
	ClipperLib::ClipType type,
	const std::vector<std::vector<osg::Vec2d>>& polys1,
	const std::vector<std::vector<osg::Vec2d>>& polys2,
	std::vector<std::vector<osg::Vec2d>>& polysOut)
{
	//
	polysOut.clear();
	//
	ClipperLib::Paths paths1;
	polygons2ClipperPaths(polys1, paths1);
	//
	ClipperLib::Paths paths2;
	polygons2ClipperPaths(polys2, paths2);

	//
	ClipperLib::Clipper clipper;
	clipper.AddPaths(paths1, ClipperLib::PolyType::ptSubject, true);
	clipper.AddPaths(paths2, ClipperLib::PolyType::ptClip, true);
	//clipper.StrictlySimple(true);
	ClipperLib::Paths solution;
	bool ret = clipper.Execute(type, solution, ClipperLib::PolyFillType::pftNonZero);
	if (ret)
	{
		clipperPaths2Polygons(solution, polysOut);
	}

	return ret;
}

bool ClipperUtils::intersectionsPolylinesAndPolygons(
	const std::vector<std::vector<osg::Vec2d>>& polys1,
	const std::vector<std::vector<osg::Vec2d>>& polys2,
	std::vector<std::vector<osg::Vec2d>>& polysOut)
{
	//
	polysOut.clear();
	//
	ClipperLib::Paths paths1;
	polygons2ClipperPaths(polys1, paths1);
	//
	ClipperLib::Paths paths2;
	polygons2ClipperPaths(polys2, paths2);

	//
	ClipperLib::Clipper clipper;
	clipper.AddPaths(paths1, ClipperLib::PolyType::ptSubject, false);
	clipper.AddPaths(paths2, ClipperLib::PolyType::ptClip, true);
	//clipper.StrictlySimple(true);
	ClipperLib::PolyTree solution;
	bool ret = clipper.Execute(ClipperLib::ClipType::ctIntersection, solution, ClipperLib::PolyFillType::pftNonZero);
	if (ret)
	{
		int num = solution.Total();
		if (num == 0) return ret;
		polysOut.reserve(num);
		ClipperLib::PolyNode* polyNode = solution.GetFirst();
		while (polyNode)
		{
			polysOut.push_back(std::vector<osg::Vec2d>());
			std::vector<osg::Vec2d>& poly = polysOut.back();
			poly.reserve(polyNode->Contour.size());
			for (const ClipperLib::IntPoint& intPnt : polyNode->Contour)
			{
				poly.push_back(intPoint2Vec2(intPnt));
			}

			polyNode = polyNode->GetNext();
		}
	}
	return ret;
}

void ClipperUtils::polygons2ClipperPaths(
	const std::vector<std::vector<osg::Vec2d>>& polys,
	ClipperLib::Paths& paths)
{
	paths.clear();

	size_t num = polys.size();
	paths.resize(num);
	for (size_t i = 0; i < num; ++i)
	{
		size_t numPnts = polys[i].size();
		paths[i].reserve(numPnts);
		for (const osg::Vec2d& pnt : polys[i])
		{
			paths[i].push_back(vec2IntPoint(pnt));
		}
	}
}

void ClipperUtils::polygons2ClipperPaths(
	const std::vector<osg::Vec2d>& poly,
	ClipperLib::Paths& paths)
{
	paths.clear();
	paths.resize(1);
	
	size_t numPnts = poly.size();
	paths[0].reserve(numPnts);
	for (const osg::Vec2d& pnt : poly)
	{
		paths[0].push_back(vec2IntPoint(pnt));
	}
}

void ClipperUtils::clipperPaths2Polygons(
	const ClipperLib::Paths& paths,
	std::vector<std::vector<osg::Vec2d>>& polys)
{
	polys.clear();

	size_t num = paths.size();
	polys.resize(num);
	for (size_t i = 0; i < num; ++i)
	{
		size_t numPnts = paths[i].size();
		polys[i].reserve(numPnts);
		for (const ClipperLib::IntPoint& intPnt : paths[i])
		{
			polys[i].push_back(intPoint2Vec2(intPnt));
		}
	}
}