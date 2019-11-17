#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Circle.h"
#include "Point.h"

using namespace std;


int main(void)
{
	Circle c;         //实例化圆的对象
	c.setR(4);
	c.setXY(2, 2);

	Point p;          //实例化点的对象
	p.setXY(8, 8);

	//判断点是否在圆内
	if (c.judgePoint(p) == true) 
	{
		cout << "nei" << endl;
	}
	else {
		cout << "wai" << endl;
	}
	
	return 0;
}
