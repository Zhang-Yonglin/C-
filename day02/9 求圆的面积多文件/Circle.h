#pragma once        //等价于下面一段代码   防止头文件被重复引用

#if 0

#ifndef __CIRCLE_H_
#define __CIRCLE_H_

//此处写头文件定义代码

#endif

#endif

class Circle
{
public:
	//设置半径：
	void setR(double r);
	//得到半径
	double getR();
	//面积
	double getArea();
	//周长
	double getGirth();

private:
	double m_r;
	double m_area;
	double m_girth;
};   //注意这里有分号

