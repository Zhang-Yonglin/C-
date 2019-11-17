#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;


//定义结构体
struct teacher
{
	int id;
	char name[64];
};


int get_mem(struct teacher** tpp)  //二级指针传参
{
	struct teacher *tp = NULL;
	tp = (struct teacher*) malloc(sizeof(struct teacher));
	if (tp == NULL) 
	{
		return -1;
	}

	tp->id = 100;
	strcpy(tp->name, "li4");

	*tpp = tp;

	return 0;
}


void free_teacher(struct teacher **tpp)
{
	if (tpp == NULL) 
	{
		return;
	}

	struct teacher *tp = *tpp;

	if (tp != NULL) 
	{
		free(tp);     
		*tpp = NULL;
	}
}


int get_mem2(struct teacher* &tp)  //指针的引用来接收
{
	tp = (struct teacher*)malloc(sizeof(struct teacher));
	if (tp == NULL) 
	{
		return -1;
	}
	
	tp->id = 300;
	strcpy(tp->name, "wang5");

	return 0;
}


void free_mem2(struct teacher * &tp)
{
	if (tp != NULL) 
	{
		free(tp);     //注意：释放的内容是tp所指向的内存存储的内容，但是tp依然指向这块内存，为使得不再引用这块内存，需要将tp也清零，即下一行代码，将tp的值赋值为NULL，从而防止野指针的出现
		tp = NULL;
	}
}


int main(void)
{
	//指针   C++完全兼容指针
	struct teacher *tp = NULL;  //定义结构体指针

	get_mem(&tp);               //传入的指针的地址，则必须使用指针的指针（即二级指针）来接收
	cout << "id =" << tp->id << ", name = " << tp->name << endl;
	free_teacher(&tp);

	cout << "---------------" << endl;

	//引用
	get_mem2(tp);
	cout << "id =" << tp->id << ", name = " << tp->name << endl;
	free_mem2(tp);

	return 0;
	
}




