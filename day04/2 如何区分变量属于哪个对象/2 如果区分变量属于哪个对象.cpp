#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


class Test
{
public:
	Test(int i)                //有参构造函数
	{
		mI = i;
	}

	int getI()
	{
		return this->mI;  //this就是指向调用该成员函数方法的对象地址
		//return mI;
	}
private:
	int mI;
};

/*
struct Test
{
	int mI;
};

void Test_init(Test *pthis, int i)
{
	pthis->mI = i;
}

int getI(struct Test *pthis)
{
	return pthis->mI;
}
*/


int main(void)
{

	Test t1(10);  // Test(&t1, 10)
	Test t2(20);

	t1.getI();    // getI(&t1)
	
	return 0;
}
