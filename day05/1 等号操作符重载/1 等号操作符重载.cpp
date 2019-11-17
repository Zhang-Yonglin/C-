#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

using namespace std;


class Student
{
public:
	Student()  //无参构造函数
	{
		this->id = 0;        //使用this的好处是能够知道当前使用的变量是类中的变量（这在变量很多时用处很大）
		this->name = NULL;
	}

	Student(int id, char *name)  //有参构造函数
	{
		this->id = id;

		//this->name = name;
		int len = strlen(name);
		this->name = new char[len + 1];
		strcpy(this->name, name);
	}

	Student(const Student &another) //拷贝构造函数  使用const的好处是：此处只能进行深拷贝而不能改变传进来的类中的变量
	{
		this->id = another.id;

		//深拷贝
		int len = strlen(another.name);
		this->name = new char[len + 1];
		strcpy(this->name, another.name);
	}

	Student & operator=(const Student &another) //=操作符重载
	{
		//1 防止自身赋值
		if (this == &another) 
		{
			return *this;
		}

		//2 先将自身额外开辟的空间回收掉，否则会发生内存泄漏
		if (this->name != NULL) 
		{
			delete[] this->name;
			this->name = NULL;
			this->id = 0;
		}

		//3 执行深拷贝（深拷贝会在堆上重新开辟内存，并进行内容拷贝）    //浅拷贝在调用析构函数时容易发生内存泄漏
		this->id = another.id;

		int len = strlen(another.name);
		this->name = new char[len + 1];
		strcpy(this->name, another.name);

		//4 返回本身
		return *this;
	}

	void printS()                     //打印函数
	{
		cout << name << endl;
	}

	~Student() {                      //析构函数
		if (this->name != NULL) 
		{
			delete[] this->name;
			this->name = NULL;
			this->id = 0;
		}
	}
private:
	int id;
	char *name;
};


int main(void)
{

	Student s1(1, "zhang3");  //调用有参构造函数   "zhang3"在常量区，不可改变，则接收它的指针也应该定义为常指针，否则编译时会有警告
	Student s2(s1);           //调用拷贝构造函数

	s2 = s1;                  //调用=操作符

	Student s3(2, "li4");     //调用有参构造函数   "li4"在常量区，不可改变，则接收它的指针也应该定义为常指针，否则编译时会有警告

	//s2 = s3 = s1;           //可以连等

	s1.printS();
	s2.printS();
	s3.printS();

	return 0;
}
