#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;


//C语言中的结构体只能定义变量，不能定义成员方法，在C++中对结构体进行了升级，结构体中可以定义成员方法
//定义结构体(数据类型)
struct Hero
{
	char name[64];
	int sex;
};


//打印结构体内容
void printHero(struct Hero &h)   //引用传递
{
	cout << "Hero:" << endl;

	cout << "name = " << h.name << endl;
	cout << "sex = " << h.sex << endl;
}


//定义类（本质上是一个数据类型）
class AdvHero
{
public:                         //访问控制权限
	char name[64];
	int sex;

	void printHero()        //定义函数
	{
		cout << "advHero:" << endl;
		cout << "name = " << name << endl;
		cout << "sex = " << sex << endl;
	}
};


//定义类
class Animal
{
	                        //{}以内 叫类的内部， 以外叫类的外部
public:
	char kind[64];
	char color[64];

	//在public下面定义成员变量和函数 是能够在类的内部和外部都可以访问的。
	void printAnimal()
	{
		cout << "kind = " << kind << endl;
		cout << "color = " << color << endl;
	}

	void write()
	{
		cout << kind << "开始写字了" << endl;
	}
	void run()
	{
		cout << kind << "跑起来了" << endl;
	}
private:
	//在private下面定义的成员变量和方法只能够在类的内部访问
	
};


int main(void)
{
	//结构体
	Hero h;                //Hero是数据类型，h是对象（本质上是一个变量）  类也同理
	strcpy(h.name, "gailun");
	h.sex = 1;
	printHero(h);
	cout << "--------------" << endl;
	
	
	//类
	AdvHero advH;
	strcpy(advH.name, "ChunBro");
	advH.sex = 1;
	advH.printHero();
	cout << "--------------" << endl;
	
	
	//类
	Animal dog;
	strcpy(dog.kind, "dog");
	strcpy(dog.color, "yellow");

	Animal sheep;
	strcpy(sheep.kind, "sheep");
	strcpy(sheep.color, "white");

	dog.write();
	sheep.run();

	return 0;
	
}
