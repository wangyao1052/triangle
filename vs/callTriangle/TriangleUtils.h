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
	/**
	* 三角化网格输出到OFF文件.
	*
	* @param[in] polygon 多边形.
	*            数组第0项为多边形的外轮廓;后续项皆为多边形的孔轮廓.
	* @param[in] offFile .off文件名.
	* @param[in] szOption 三角化的参数字符串.
	*            默认值的参数含义:<1> p PSLG
	*                          <2> z zero index based
	*                          <3> Q quiet
	* @return 成功返回true;失败返回false.
	*/
	static bool triMesh(
		const std::vector<std::vector<osg::Vec2d>>& polygon,
		const std::string& offFile,
		const char* szOption = "pzQ");

};