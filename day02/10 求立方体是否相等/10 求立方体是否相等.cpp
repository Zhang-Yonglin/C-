#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

//立方体类
class Cube
{
public:
	
	//设置立方体边长
	void setABC(int a, int b, int c)
	{
		m_a = a;
		m_b = b;
		m_c = c;
	}
	
	
	//表面积
	int getArea()
	{
		return (m_a*m_b) * 2 + (m_a*m_c) * 2 + (m_b*m_c) * 2;
	}

	//体积
	int getVolume()
	{
		return (m_a*m_b*m_c);
	}

	int getA()
	{
		return m_a;
	}

	int getB()
	{
		return m_b;
	}

	int getC()
	{
		return m_c;
	}

	//同类之间无私处  m_a == another.m_a可以这样使用  如果是不同类则不可以直接调用another.m_a(因为m_a是私有成员)
	bool judgeCube(Cube &another)  //引用
	{
		if (m_a == another.m_a && m_b == another.getB() && m_c == another.getC()) 
		{
			return true;
		}
		
		else {
			return false;
		}
	}
	
private:
	int m_a;
	int m_b;
	int m_c;
};


//全局函数  面向过程
bool judgeCube(Cube &c1, Cube &c2)          //引用传递
{
	if (c1.getA() == c2.getA() &&       //判断两个立方体的边长是否相等
		c1.getB() == c2.getB() &&　　　//通过类的内部函数访问私有变量是可以的，类的外部无法直接访问私有变量
		c1.getC() == c2.getC()) {
		return true;
	}
	else {
		return false;
	}
}


//主函数
int main(void)
{
	Cube c1;
	c1.setABC(10, 20, 30);

	Cube c2;
	c2.setABC(10, 20, 30);

	cout << "c1 的体积是" << c1.getVolume() << endl;
	cout << "c1 的面积是" << c1.getArea() << endl;

	if (judgeCube(c1, c2) == true) {  //调用全局方法
		cout << "相等" << endl;
	}
	else {
		cout << "不相等" << endl;
	}
	cout << " ------ " << endl;


	if (c1.judgeCube(c2) == true) {  //调用成员方法
		cout << "相等" << endl;
	}
	else {
		cout << "不相等" << endl;
	}

	return 0;
}
