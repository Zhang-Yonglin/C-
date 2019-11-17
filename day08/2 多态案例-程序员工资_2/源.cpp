#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

class programmer
{
public:
	programmer()               //无参构造函数
	{
	}
	virtual void wage() = 0;   //纯虚函数
	virtual ~programmer()      //虚析构函数
	{
	}
	
};

class unior_programmer :public programmer
{
public:
	virtual void wage()
	{
		cout << "初级程序员年薪10万!" << endl;
	}
};

class unior_mid_programmer :public programmer
{
public:
	virtual void wage()
	{
		cout << "中级程序员年薪50万!" << endl;
	}
};

class adv_programmer :public programmer
{
public:
	virtual void wage()
	{
		cout << "高级程序员年薪100万!" << endl;
	}
};

//架构
class Pay
{
public:
	Pay(programmer * programmer2)      //有参构造
	{
		programmer2->wage();

		if (programmer2 != NULL)
		{
			delete programmer2; //释放内存
		}
	}

private:
	//programmer *pro;

};

int main(void)
{ 
	Pay *p = new Pay(new unior_programmer);
	delete p;

	Pay *p1 = new Pay(new unior_mid_programmer);
	delete p1;

	Pay *p2 = new Pay(new adv_programmer);
	delete p2;
	
	return 0;
}
