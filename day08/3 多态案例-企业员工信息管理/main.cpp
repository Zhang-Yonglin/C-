#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//导入类的头文件
#include "Employee.h"
#include "Technician.h"
#include "Manager.h"
#include "SalesMan.h"
#include "SalesManager.h"

using namespace std;


int main(void)
{

#if 0
	Employee *em1 = new Technician;  //父类指针可以指向子类对象
	
	em1->init();
	em1->getPay();
	em1->upLevel(1);
	em1->displayStatus();

	delete em1;
#endif

#if 0
	Employee *em2 = new Manager;
	
	em2->init();
	em2->upLevel(1);
	em2->getPay();
	em2->displayStatus();
	
	delete em2;
#endif 

#if 0
	Employee *em3 = new SalesMan;

	em3->init();
	em3->upLevel(0);
	em3->getPay();
	em3->displayStatus();

	delete em3;
#endif

#if 0
	Employee *em4 = new SalesManager;
	
	em4->init();
	em4->upLevel(1);
	em4->getPay();
	em4->displayStatus();

	delete em4;
#endif

#if 1
	Employee *person_array[] = {new Technician, new Manager, new SalesMan, new SalesManager};   //父类指针可以指向子类对象

	for (int i = 0; i < sizeof(person_array) / sizeof(person_array[0]); i++) {                  //架构
		person_array[i]->init();
		person_array[i]->upLevel(0);
		person_array[i]->getPay();
		person_array[i]->displayStatus();
	}

	for (int i = 0; i < sizeof(person_array) / sizeof(person_array[0]); i++) {                  //析构
		delete person_array[i];
	}
#endif

	return 0;
	
}
