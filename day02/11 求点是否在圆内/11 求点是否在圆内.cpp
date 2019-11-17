#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


//点类   定义类时 类名最好首字母大写
class Point
{
public:
	void setXY(int x, int y)
	{
		m_x = x;
		m_y = y;
	}

	int getX()
	{
		return m_x;
	}

	int getY()
	{
		return m_y;
	}
private:
	int m_x;
	int m_y;
};


//圆类   定义类时 类名最好首字母大写
class Circle
{
public:
	void setXY(int x, int y)  //设置圆心坐标
	{
		x0 = x;
		y0 = y;
	}

	void setR(int r)         //设置圆的半径
	{
		m_r = r;
	}

	//提供一个判断点是否在圆内  true 在内部  false 在外部
	bool judgePoint(Point &p)   //地址引用  返回bool值
	{
		int dd;

		dd = (p.getX() - x0)*(p.getX() - x0) + (p.getY() - y0)*(p.getY() - y0);   
                //该点到圆心的距离的平方  注意：不能通过p.m_x来获取点的信息，因为m_x是私有变量，在类之外无法访问

		if (dd > m_r*m_r) 
		{
			return false;
		}
		else {
			return true;
		}
	}


private:
	int x0;
	int y0;
	int m_r;
};


int main(void)
{
	//圆类
	Circle c;
	c.setXY(2, 2);
	c.setR(4);

	//点类
	Point p;
	p.setXY(8, 8);

	//判断
	if (c.judgePoint(p) == true) 
	{
		cout << "圆的内部" << endl;
	}
	else {
		cout << "圆的外部" << endl;
	}

	return 0;
}
