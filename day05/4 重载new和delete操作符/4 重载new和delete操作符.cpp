#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>

using namespace std;


class A
{
public:
	A()                                    //无参构造
	{
		cout << "A()..." << endl;
	}
	A(int a) {                             //有参构造
		cout << "A(int)..." << endl;
		this->a = a;
	}

	//重载的new操作符 依然会触发对象的构造函数      //new可以触发构造函数，而malloc不能
	void * operator new(size_t size)         //size_t就是unsigned int类型   new应该返回一个void*万能指针
	{
		cout << "重载了new操作符" << endl;
		return malloc(size);             //重载new 则不能再用new来开辟内存了，否则就不叫重载了，使用malloc来开辟内存
	}

	void *operator new[](size_t size)
	{
		cout << "重载了new[]操作符" << endl;
		return malloc(size);
	}
	
	void operator delete(void * p)
	{
		cout << "重载了delete操作符" << endl;
		if (p != NULL) 
		{
			free(p);
			p = NULL;
		}
	}

	void operator delete[](void *p)
	{
		cout << "重载了delete[]操作符" << endl;
		if (p != NULL) 
		{
			free(p);
			p = NULL;
		}
	}

	~A() {                               //析构函数
		cout << "~A().... " << endl;
	}

private:
	int a;
};


int main(void)
{
	//char *array = malloc(sizeof(char)* 80);   
	//int *value_p = new int;

	A *array_p = new A[10];  //调用A的有参构造

	//array_p->operator new[](sizeof(A[10]));
	delete[] array_p;

	A *ap = new A(10);

	//ap->operator new(sizeof(A));

	delete ap;
	
	return 0;
}
