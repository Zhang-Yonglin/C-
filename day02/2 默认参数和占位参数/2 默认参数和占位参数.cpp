#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


//默认值设置
void func(int a = 666)
{
	cout << "a = " << a << endl;
}


//求立方体体积
int get_volume(int len, int width=199, int height=10)  //默认规则：默认值从右往左放置
{
	cout << "len = " << len << endl;
	cout << "w = " << width << endl;
	cout << "h = " << height << endl;

	return len*width*height;                       //返回体积
}


void func2(int x, int=0)                               //亚元  占位参数  C++留下的一个坑，没啥意义
{
	cout << "x =" << x << endl;

}


int main(void)
{
	int value = 10;

	func();

	int len = 10;
	int w = 20;
	int h = 30;

	cout << "体积是" << get_volume(w,h) << endl;

	func2(199, 10);
	func2(200);

	return 0;
	
}
