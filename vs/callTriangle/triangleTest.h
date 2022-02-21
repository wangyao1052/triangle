#pragma once

class TriangleTest
{
public:
	/**
	* 孔.
	* 
	* #-----------#
	* |           |
	* |   #---#   |
	* |   |   |   |
	* |   #---#   |
	* |           |
	* #-----#-----#
	*/
	static bool hole1();

	/**
	* 存在重复点时
	* <1>某些情况下,程序会crash.
	* <2>某些情况下,程序会正常运行.
	*/
	static bool mayCrash_duplicatedPoints();
};
