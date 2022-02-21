#include <fstream>
#include <iomanip>
#include <cassert>

#include "TriangleUtils.h"
#include "triangle.h"

/**
* 计算多边形的形心.
*/
static osg::Vec2d _computePolygonCentroid(const std::vector<osg::Vec2d>& polygon)
{
	size_t numPnts = polygon.size();
	if (numPnts < 3)
	{
		return osg::Vec2d(0.0, 0.0);
	}

	osg::Vec2d center(0.0, 0.0);
	double totalArea(0.0);
	for (size_t i = 1; i < numPnts - 1; ++i)
	{
		double area = (polygon[i].x() - polygon[0].x()) * (polygon[i + 1].y() - polygon[0].y())
			- (polygon[i + 1].x() - polygon[0].x()) * (polygon[i].y() - polygon[0].y());
		totalArea += area;
		center.x() += area * (polygon[0].x() + polygon[i].x() + polygon[i + 1].x()) / 3;
		center.y() += area * (polygon[0].y() + polygon[i].y() + polygon[i + 1].y()) / 3;
	}
	center.x() /= totalArea;
	center.y() /= totalArea;

	return center;
}

bool TriangleUtils::triMesh(
	const std::vector<std::vector<osg::Vec2d>>& polygon,
	const std::string& offFile,
	const char* szOption)
{
	// 
	size_t numLoops = polygon.size();
	size_t numPoints(0);
	size_t numSegments(0);
	for (const std::vector<osg::Vec2d>& loop : polygon)
	{
		numPoints += loop.size();
		numSegments += loop.size();
	}
	if (polygon.empty() || numPoints == 0 || numSegments == 0)
	{
		assert(false);
		return false;
	}

	//
	triangulateio in;
	//
	in.numberofpoints = numPoints;
	in.pointlist = (REAL*)malloc(size_t(in.numberofpoints) * 2 * sizeof(REAL));
	if (!in.pointlist)
	{
		return false;
	}
	{
		size_t idx(-1);
		for (const std::vector<osg::Vec2d>& loop : polygon)
		{
			for (const osg::Vec2d& point : loop)
			{
				++idx;
				in.pointlist[idx] = point.x();
				++idx;
				in.pointlist[idx] = point.y();
			}
		}
	}
	//
	in.numberofsegments = numSegments;
	in.segmentlist = (int*)malloc(size_t(in.numberofsegments) * 2 * sizeof(int));
	if (!in.segmentlist)
	{
		return false;
	}
	{
		size_t idx(-1);
		size_t base(0);
		for (const std::vector<osg::Vec2d>& loop : polygon)
		{
			size_t num = loop.size();
			for (size_t i = 0; i < num; ++i)
			{
				++idx;
				in.segmentlist[idx] = i + base;
				++idx;
				in.segmentlist[idx] = (i + 1) % num + base;
			}
			base += num;
		}
	}
	//
	in.numberofholes = numLoops - 1;
	if (in.numberofholes)
	{
		in.holelist = (double*)malloc(size_t(in.numberofholes) * 2 * sizeof(REAL));
	}
	{
		size_t idx(-1);
		for (size_t i = 1; i < numLoops; ++i)
		{
			osg::Vec2d center = _computePolygonCentroid(polygon[i]);
			++idx;
			in.holelist[idx] = center.x();
			++idx;
			in.holelist[idx] = center.y();
		}
	}
	

	//
	triangulateio out;
	triangulate(const_cast<char*>(szOption), &in, &out, nullptr);

	// 输出.off文件
	std::ofstream file(offFile.c_str(), std::ios::out);
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

	return true;
}