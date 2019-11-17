#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


//方法一： 直接定义一个数组类型
typedef int(ARRAY_INT_10)[10];   //ARRAY_INT_10 是一个新的数据类型


//方法二：
typedef int(*ARRAY_INT_10_P)[10];


int main(void)
{
	int array[10];                          //array是数组名，是常指针，始终指向数组首元素的地址  array 应该是一个指向int类型指针。

	//方法一：
	//ARRAY_INT_10 *array_10_p = &array;    //array_10_p为指向ARRAY_INT_10这种数组的指针
						//array_10_p和array不是一个类型 有：*array_10_p === array
	//方法二：
	ARRAY_INT_10_P array_10_p = &array;

	for (int i = 0; i < 10; i++) {
		(*array_10_p)[i] = i + 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << array[i] << endl;
	}

	//方法三：
	int(*p)[10] = &array;                   //指向10个整形的数组的指针

	cout << "------" << endl;
	for (int i = 0; i < 10; i++) {
		cout << (*p)[i] << endl;
	}

	return 0;
	
}
