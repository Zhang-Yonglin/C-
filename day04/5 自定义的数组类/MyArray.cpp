#include "MyArray.h"


MyArray::MyArray()
{
	cout << "MyArray()..." << endl;
	this->len = 0;
	this->space = NULL;
}


MyArray::MyArray(int len)                            //初始化时传入数组长度
{
	if (len <= 0) 
	{
		this->len = 0;
		return;
	}
	else {
		this->len = len;

		//给space开辟空间
		this->space = new int[this->len];    //在堆上开辟空间并返回地址  space其实是一个数组名
		cout << endl;
		cout << "MyArray::MyArray(int len) ..." << endl;
	}
}


MyArray::MyArray(const MyArray &another)             //拷贝构造函数
{
	if (another.len >= 0) 
	{
		this->len = another.len;

		//深拷贝
		this->space = new int[this->len];
		for (int i = 0; i < this->len; i++) 
		{
			this->space[i] = another.space[i];
		}
		cout << "MyArray::MyArray(const MyArray &another) ..." << endl;

	}
}


MyArray::~MyArray()
{
	if (this->space != NULL) 
	{
		delete[]this->space;   //释放指针指向的数组内存的内容
		this->space = NULL;    //给指针赋值为NULL，防止野指针
		len = 0;
		cout << "MyArray::~MyArray() ..." << endl;
	}
}


void MyArray::setData(int index, int data)
{
	if (this->space != NULL) 
	{
		this->space[index] = data;  //给数组中的元素赋值
	}
}


int MyArray::getData(int index)
{
	return this->space[index];         //获得数组中的元素
}


int MyArray::getLen()
{
	return this->len;                  //获得数组的长度
}


void MyArray::operator=(const MyArray& another)
{
	if (another.len >= 0) 
	{
		this->len = another.len;

		//深拷贝
		this->space = new int[this->len];
		for (int i = 0; i < this->len; i++) 
		{
			this->space[i] = another.space[i];
		}
		cout << "MyArray::operator=(const MyArray& another) ..." << endl;

	}
}

