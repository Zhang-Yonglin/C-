#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <memory>

using namespace std;


//普通类
class A
{
public:
	A(int a)                       //有参构造函数
	{
		cout << "A()..." << endl;
		this->a = a;
	}

	void func() {                  //打印函数
		cout << "a = " << this->a << endl;
	}

	~A() {                         //析构函数
		cout << "~A()..." << endl;
	}
private:
	int a;
};


//实现智能指针类
class MyAutoPtr
{
public:
	MyAutoPtr(A * ptr)            //有参构造函数
	{
		this->ptr = ptr;      //ptr = new A(10)
	}

	~MyAutoPtr() {                //析构函数
		if (this->ptr != NULL) 
		{
			cout << "delte ptr" << endl;
			delete ptr;
			this->ptr = NULL;
		}
	}

	A* operator->()              //重载->操作符 无需参数 返回A类型指针
	{
		return this->ptr;
	}


	A& operator*()               //重载*操作符  无需参数 返回引用
	{
		return *ptr;
	}

private:
	A *ptr;  //类指针
};


//测试函数1
void test1()
{
#if 1
	A* ap = new A(10);

	ap->func();                  //也可以用下面的调用方法
	(*ap).func();

	delete ap;

#endif

	auto_ptr<A> ptr(new A(10));  //创建智能指针pyr指向new A(10)  会自动释放指针

	ptr->func();
	(*ptr).func();               //不需要手动释放
}


//实现一个智能指针测试
void test2()
{
	MyAutoPtr my_p(new A(10));

	my_p->func();               //my_p.ptr -> func()
	(*my_p).func();             //*ptr.func()
}


int main(void)
{

	test1();
	cout << "---------" << endl;
	test2();

	return 0;
}

//智能指针无需手动释放
//auto_ptr<int> ptr(new int)  即创建了一个智能指针等于new int
//*ptr = 20;


