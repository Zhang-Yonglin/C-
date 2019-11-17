#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


//家具类
class Furniture
{
public:
	int m = 2; //材质
};


//将父亲类继承爷爷类  改成虚继承， 防止儿子在多继承我的时候，出现爷爷中的变量会拷贝多份。
class Bed:virtual public Furniture
{
public:
	void sleep() {
		cout << "在床上睡觉" << endl;
	}
};


class Sofa:virtual public Furniture  //虚继承
{
public:
	void sit() {
		cout << "在沙发上休息" << endl;
	}
};


//沙发床
class SofaBed :public Bed, public Sofa
{
public:
	void SleepAndSit() {
		sleep();
		sit();
	}
};


int main(void)
{
	Bed b;
	b.sleep();

	Sofa s;
	s.sit();

	cout << " ------ " << endl;

	SofaBed sb;
	sb.SleepAndSit();

	cout << " ------ " << endl;
	cout << b.m << endl;
	
	sb.m = 100;               //此时只有一个m
	cout << sb.m << endl;
	cout << b.m << endl;
	
	sb.Bed::m = 200;
	cout << sb.m << endl;
	
	sb.Sofa::m = 300;
	cout << sb.m << endl;
	
	
	return 0;
}

//如果说爷爷中有一个变量，儿子会继承这个变量，但是如果儿子会被多继承，那么爷爷中这个变量会在孙子中拷贝多份。
//解决方法是在儿子继承爷爷的时候，加上virtual关键字
