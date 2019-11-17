#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

//抽象的图形类
class Shape
{
public:
	//打印出图形的基本属性
	virtual void show() = 0;       //纯虚函数
	//得到图形的面积
	virtual double getArea() = 0;  //纯虚函数

	virtual ~Shape() {             //虚析构函数
	}
};


//圆类
class Circle :public Shape             //继承一个抽象类，一定要将其实现，否则不能实例化
{
public:
	Circle(double r) {             //有参构造
		this->r = r;
	}
	//打印出图形的基本属性
	virtual void show()  {
		cout << "圆的半径是 " << r << endl;
	}
	//得到图形的面积
	virtual double getArea()  {
		cout << "获取圆的面积" << endl;
		return this->r*this->r *3.14;
	}
	~Circle() {
		cout << "圆的析构函数。。" << endl;
	}
private:
	double r;
};


//正方形类
class Square :public Shape
{
public:
	Square(double a) {            //有参构造
		this->a = a;
	}
	//打印出图形的基本属性
	virtual void show() {
		cout << "正方形的边长是" << this->a << endl;
	}
	//得到图形的面积
	virtual double getArea() {
		cout << "得到正方形的面积" << endl;
		return a*a;
	}

	~Square() {
		cout << "正方形的析构函数" << endl;
	}
private:
	double a;
};


//主函数
int main(void)
{
	Shape *array[2] = { 0 };                         //创建指针类并初始化

	for (int i = 0; i < 2; i++) {
		if (i == 0) {                            //生成一个圆
			double r;
			cout << "请输入圆的半径" << endl;
			cin >> r;
			array[i] = new Circle(r);
		}
		else {                                   //生成一个正方形
			double a;
			cout << "请输入正方形的边长" << endl;
			cin >> a;
			array[i] = new Square(a);
		}
	}

	cout << "-----------" << endl;
	
	//遍历这个array数组
	for (int i = 0; i < 2; i++) {
		array[i]->show();
		cout << array[i]->getArea() << endl;
		delete array[i];
	}
	return 0;
}
