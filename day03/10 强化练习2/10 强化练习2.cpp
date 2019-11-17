#include <iostream>
#include <stdio.h>

using namespace	std;

//构造中调⽤构造是危险的⾏为
class MyTest
{
public:
	MyTest(int a, int b, int c)
	{
		_a = a;
		_b = b;
		_c = c;
	}
	MyTest(int a, int b)
	{
		_a = a;
		_b = b;
		MyTest(a, b, 100);        //创建一个匿名对象   调用结束后立刻释放内存（释放时会调用析构函数）
	}
	
	~MyTest()
	{
		printf("MyTest~: %d,%d,%d\n", _a, _b, _c);
	}
	
	int getC()
	{
		return	_c;
	}
	
	void setC(int val)
	{
		_c = val;
	}

private:
	int	_a;
	int	_b;
	int	_c;
};


int main()
{
	MyTest	t1(1, 2);
	printf("c: %d\n", t1.getC());	 //请问c的值是？ 0
	return 0;
}
