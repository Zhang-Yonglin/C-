#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

/*
1 引用没有定义, 是一种关系型声明。声明它和原有某一变量(实体)的关系。故而类型与原类型保持一致, 且不分配内存。与被引用的变量有相同的地址。
2 声明的时候必须初始化, 一经声明, 不可变更。
3 可对引用, 再次引用。多次引用的结果, 是某一变量具有多个别名。
4 & 符号前有数据类型时, 是引用。其它皆为取地址
*/

void change_value(int *p)    // int p = a;
{
	*p = 30;
}

void change_value2(int &r)  //int &r = a
{
	r = 30;             //a = 30
}


int main(void)
{
	int a = 20;
	int b = 30;


	int *p = &a;
	*p = 30;
	cout << "a=" << a;

	p = &b;
	*p = 20;
	cout << "b=" << b;


	int &re = a;    //int & 使用引用数据类型， re就是a的别名

	re = 50;
	//&re;          //无法获取引用的地址

	re = b;         //让re成为b的引用？ 否  是将b的值赋值给b，即：a = b   因为引用一经声明，不可更改
	re = 50;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	
	int &re2 = b;  //引用一定要初始化，

	re2 = a;

	int &re3 = re;  //可对引用再次引用

	re3 = 100;
	cout << "a =" << a << endl;
	cout << "re =" << re << endl;
	cout << "re3 =" << re3 << endl;

	cout << "-------------" << endl;
	cout << "a =" << a << endl;
	change_value(&a);
	cout << "a =" << a <<  endl;
	a = 100;
	cout << "-------------" << endl;
	cout << "a =" << a << endl;
	change_value2(a);
	cout << "a =" << a << endl;

	return 0;
}

//变量名实质上是一段连续存储空间的别名，是一个标号（门牌号）
//通过变量来申请并命名内存空间
//通过变量的名字可以使用存储空间

