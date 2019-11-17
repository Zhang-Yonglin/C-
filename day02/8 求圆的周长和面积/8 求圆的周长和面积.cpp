#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#define PI 3.14

using namespace std;

//圆的周长
double getCircleGirth(double r)
{
	return 2 * PI *r;
}

//圆的面积
double getCircleArea(double r)
{
	return PI*r*r;
}

//用面向对象实现
//圆类
class Circle
{
public:
	void setR(double r)
	{
		m_r = r;
	}

	double getR()
	{
		return m_r;
	}

	double getGirth()  //周长
	{
		return 2 * PI *m_r;
	}

	double getArea()   //面积
	{
		return m_r*m_r*PI;
	}

private:
	double m_r;       //圆的私有成员 半径       m可以表示me或者my，表示私有成员，可用可不用，用了会使得代码清晰
};


class Circle2
{
public:

	void setR(double r)
	{
		m_r = r;
	}

	double getR()
	{
		return m_r;
	}

	double getArea()
	{
		m_area = m_r*m_r*3.14;
		return m_area;
	}

	double getGirth()
	{
		m_girth = m_r * 2 * 3.14;
		return m_girth;
	}

private:
	double m_r;
	double m_girth;     //周长
	double m_area;      //面积
};


int main(void)
{
	double r = 10; //圆的半径

	double g;
	double a = 0;

	g = getCircleGirth(r);
	a = getCircleArea(r);
	cout << "圆的半径是" << r << endl;
	cout << "圆的周长是" << g << endl;
	cout << "圆的面积是" << a << endl;

	cout << "-------------" << endl;


	Circle c;
	c.setR(10);
	cout << "圆的半径是" << c.getR() << endl;
	cout << "圆的周长是" << c.getGirth() << endl;
	cout << "圆的面积是" << c.getArea() << endl;

	cout << "------------" << endl;


	Circle2 c2;
	c2.setR(10);
	cout << "圆的半径是" << c2.getR() << endl;
	cout << "圆的周长是" << c2.getGirth() << endl;
	cout << "圆的面积是" << c2.getArea() << endl;

	return 0;
}
