#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>

using namespace std;

class Point;         //先声明，否则下面的类PointManager中使用Point类时会报错


class PointManager {
public:
	double PointDistance(Point &p1, Point &p2);  //引用传递  计算两点之间的距离
	//如果将函数PointDistance的定义直接写在这个位置，则会无法识别其中的变量，因为类的具体实现都在下面，所以此处将函数PointDistance的声明和定义分开来写
};


class Point
{

public:
	//声明全局函数 PointDistance 是我类Point类的一个友元函数。
	//friend double PointDistance(Point &p1, Point &p2);              //全局函数方式
	friend double PointManager::PointDistance(Point &p1, Point &p2);  //类中函数方式  声明一个友元函数，则此类的私有成员可以被该函数所访问

	Point(int x, int y) {                                             //有参构造函数
		this->x = x;
		this->y = y;
	}


	int getX()
	{
		return this->x;
	}

	int getY()
	{
		return this->y;
	}
private:
	int x;
	int y;

};


//计算两点之间的距离
double PointManager::PointDistance(Point &p1, Point &p2)
{
	double dis;
	int dd_x = p1.x - p2.x;              //友元函数可以访问类的私有成员变量
	int dd_y = p1.y - p2.y;

	dis = sqrt(dd_x*dd_x + dd_y *dd_y);  //计算两点之间距离

	return dis;
}

//全局函数
# if 0
double PointDistance(Point &p1, Point &p2)
{
	double dis;
	int dd_x = p1.getX() - p2.getX();  //如果函数PointDistance经常被调用，则每次都要调用getX()和getY()，它们是成员方法，需要压栈出栈，会有很大的压栈出栈开销
	int dd_y = p1.getY() - p2.getY();

	dis = sqrt(dd_x*dd_x + dd_y *dd_y);

	return dis;
}
#endif


int main(void)
{
	
	Point p1(1, 2);
	Point p2(2, 2);

	//cout << PointDistance(p1, p2) << endl;

	PointManager pm;
	cout << pm.PointDistance(p1, p2) << endl;

	return 0;
}

//同类对象间无私处  异类对象间有友元
