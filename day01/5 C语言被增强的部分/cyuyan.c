#include <stdio.h>

int g_val;       //bss段
int g_val = 20;  //data

struct student
{
	char name[64];
	int id;
};

foo()
{
	return 10;
}

int g(int a)
{
	return 10;
}

void test4()
{
	int a = 10;
	int b = 20;
	int c = 0;

	//左值 右值

	c = a < b ? a : b;

	printf("c = %d\n", c);

	*(a < b ? &a : &b )= 50;   //判断并重新给变量赋值，在C++中则不需要加*
	//10
	//10 = 50;
	printf("a = %d\n", a);
}

void test5()
{
	const int a = 10;
	//int array[a] = { 0 };

	int *p = &a;

	*p = 70;

	printf("a = %d\n", a);

}

enum season
{
	SPR = 0,
	SUM,
	AUT,
	WIN,
	WIN1,
	WIN2,
	WIN64,
};

void test6()
{
	enum  season s = 2;      //在C++中不可以赋值为数字序号，只能赋值为enum定义中的取值

	s = 64;

	if (s == 2) {

	}
}



int main(void)
{
	int a = 10;
	int b = 20;

	struct student s1;
	s1.id = 20;

	test4();


	printf("%d\n", g_val);

	//g(10,20,30,40,50);
	printf("-----------------\n");
	test5();
}
