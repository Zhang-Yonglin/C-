#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


//英雄类
//1999
class Hero
{
public:
	virtual int getAd() {  //虚函数
		return 10;
	}
};


//1999
class AdvHero :public Hero
{
public:
	virtual int getAd()   //对父类中的虚函数进行重写，virtual写不写都可以，写了可以加强类的可读性，起到注释作用（父类中的virtual一定要写）
	{
		return 1001;
	}
};


//怪兽类
//1999
class Monster
{
public:
	int getAd() {
		return 1000;
	}
};


//战斗方法
//1999 //写的架构函数，可以调用未来写的代码。
void playerFight(Hero *hp, Monster *mp)
{
	//多态对于编译器来讲的，也是一个动态联编，是一个迟邦定。
	if (hp->getAd() > mp->getAd()) {            //hp->getAd 发生了多态
		cout << "英雄胜利， 怪兽被打死" << endl;
	}
	else {
		cout << "英雄挂了，怪兽赢了" << endl;
	}
}


//2020年   //以前写的代码最好就不要动了，新的需求（拓展）通过类的继承和多态等实现，提高程序代码的可重用性
class BugHero :public Hero
{
public:
	virtual int getAd()
	{
		cout << "调用了bugHero的方法" << endl;
		return 66666;
	}
};


int main(void)
{
	Hero h;
	Monster m;
	playerFight(&h, &m);      //引用传递

	AdvHero advH;             //引用传递
	playerFight(&advH, &m);

	BugHero bH;
	playerFight(&bH, &m);     //引用传递

	cout << "-------------" << endl;
	 
	int a = 10;
	int b = 20;
	cout << a << endl;             //一定会运行  静态联编  多态：不确定运行父类函数还是子类函数，是动态联编
	
	if (a > 10) {                  //迟邦定
		cout << "a>10" << endl;
	}
	else {
		cout << "a < 10" << endl;
	}

	return 0;
}
