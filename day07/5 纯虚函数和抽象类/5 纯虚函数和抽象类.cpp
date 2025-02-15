#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

//定义抽象类
//图形类
//如果说一个类 拥有一个纯虚函数 就称这个类是一个抽象类。
//不管这个类中有没有成员属性，只要这个类有纯虚函数，就是一个抽象类， 抽象类就是不能够实例化的。
class Shape
{
public:
	//求图形面积的方法
	//表示图形类声明一个方法getArea（），它是一个纯虚函数，没有函数的实现。
	virtual double getArea() = 0;  //0是纯语法概念  不是初值为0或者返回0
};

//子类继承抽象类，并对纯虚函数进行具体实现:

//三角形
class Tri :public Shape
{
public:
	Tri(int a, int h)           //有参构造
	{
		this->a = a;
		this->h = h;
	}
	virtual double getArea()    //纯虚函数的实现
	{  
		cout << "三角形求面价:";
		return 0.5*a*h;
	}
private:
	int a;
	int h;
};


//正方形：
//如果说一个普通类，继承拥有纯虚函数的类，如果说不重写纯虚函数，依然是一个抽象类。
//依然不能被实例化， 如果想实例化， 必须要重写这个父类中所有纯虚函数
class Rect : public Shape
{
public:
	Rect(int a) 
	{
		this->a = a;
	}
	virtual double getArea() 
	{
		cout << "正方形求面积:";
		return a*a;
	}
private:
	int a;//正方形边长
};


//圆形
class Circle :public Shape
{
public:
	Circle(int r)
	{
		this->r = r;
	}

	virtual double getArea()
	{
		cout << "圆形求面积:";
		return 3.14*r * 4;
	}
private:
	int  r;
};


//面向抽象类写一个架构函数
void printArea(Shape *sp)              //父类指针
{
	cout << sp->getArea() << endl;
}


//业务层  面向的抽象类编程  main函数只需要与抽象类关联即可  派生类与抽象类耦合
int main(void)
{
	//main 中所有使用的变量类型 都是 抽象类Shape的类型。
	Shape *sp1 = new Rect(10);  //父类指针指向子类的对象
	//sp1->getArea();

	Shape *sp2 = new Circle(20);
	//sp2->getArea();

	Shape *sp3 = new Tri(10, 20);
	//sp3->getArea();

	printArea(sp1);
	printArea(sp2);
	printArea(sp3);

	return 0;
}

//纯虚函数是一个在基类中说明的虚函数，在基类中没有定义，要求任何一个派生类都定义自己的版本
//纯虚函数为每个派生类提供一个公共界面（接口的封装和设计、软件的模块功能划分）
//纯虚函数的语法： virtual 类型 函数名（参数表）= 0;

//抽象类的存在就是让别人继承的，并且重写虚函数。
//抽象类对其它类来说就是一个接口

//main函数  高层业务逻辑层
//抽象类    抽象层
//派生类    实现层
//高内聚 低耦合
//依赖倒转原则
