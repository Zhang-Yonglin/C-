#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;


//-------------抽象层------------
//定义拆开锦囊方法的类型
typedef void(TIPS)(void);  //定义函数指针

//定义锦囊
struct tip
{
	char from[64];    //谁写的
	char to[64];      //写给谁的。
	//锦囊的内容
	TIPS *tp;         //相当于抽象类的纯虚函数   tp为接受方法的指针，一定要定义方法，否则是一个空指针
};


//需要一个打开锦囊的架构函数
void open_tips(struct tip *tip_p)    //传入结构体类型指针
{
	cout << "打开了锦囊" << endl;
	cout << "此锦囊是由" << tip_p->from << "写给" << tip_p->to << "的。" << endl;
	cout << "内容是" << endl;
	tip_p->tp();                //此时就发生了多态现象
}


//提供一个创建一个锦囊的方法  返回一个锦囊指针
struct tip* create_tip(char*from, char *to, TIPS*tp)            //改为：struct tip* create_tip(const char*from, const char *to, TIPS*tp)在编译过程中就不会产生警告  
								//原因是传入的参数在常量区，需要使用常指针进行接收
{
	struct tip *temp = (struct tip*)malloc(sizeof(struct tip));  //在堆上开辟内存
	if (temp == NULL) 
	{
		return NULL;   //如果temp == NULL，函数返回             //有return的地方就是函数结束的地方
	}
	strcpy(temp->from, from);
	strcpy(temp->to, to);
	//给一个回调函数赋值， 一般称 注册回调函数
	temp->tp = tp;

	return temp;          //返回结构体类型的指针，此函数结束后，temp被释放，但是其中的元素已经在堆上建立，并返回给了在main函数中创建的结构体类型的指针
}


//提供一个销毁锦囊的方法
void destory_tip(struct tip *tp)  //传入参数为结构体类型指针
{
	if (tp != NULL) 
	{
		free(tp);        //释放tp指向内存存储的内容
		tp = NULL;       //tp赋值为空
	}
}


// ------------- 实现层------------
//诸葛亮写了3个锦囊
void tip1_func(void)
{
	cout << "一到东吴就拜会乔国老" << endl;
}


void tip2_func(void)
{
	cout << "如果主公乐不思蜀，就谎称曹贼来袭。赶紧回来 " << endl;
}


void tip3_func(void)
{
	cout << "如果被孙权追杀，向孙尚香求救" << endl;
}


void tip4_func(void)
{
	cout << "如果求救孙尚香都不灵，你们去死了，我是蜀国老大了" << endl;
}


//---------------  业务层-----------------
int main(void)
{
	//创建出3个锦囊
	struct tip *tip1 = create_tip("孔明", "赵云", tip1_func);
	struct tip *tip2 = create_tip("孔明", "赵云", tip2_func);
	struct tip *tip3 = create_tip("孔明", "赵云", tip3_func);
	struct tip *tip4 = create_tip("庞统", "赵云", tip4_func);

	//由赵云进行拆锦囊
	cout << "刚刚来到东吴， 赵云打开第一个锦囊" << endl;
	open_tips(tip1);
	cout << "-----------" << endl;

	cout << "刘备乐不思蜀， 赵云打开第二个锦囊" << endl;
	open_tips(tip2);
	cout << "-----------" << endl;

	cout << "孙权大军追杀，赵云打开第三个锦囊" << endl;
	open_tips(tip3);
	cout << "-----------" << endl;

	cout << "赵云发现，实在是杀不动了， 打开了第四个锦囊" << endl;
	open_tips(tip4);

	//销毁锦囊指针
	destory_tip(tip1);
	destory_tip(tip2);
	destory_tip(tip3);
	destory_tip(tip4);
	
	return 0;
	
}
