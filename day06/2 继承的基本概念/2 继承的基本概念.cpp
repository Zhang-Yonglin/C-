#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;


class Student
{
public:
	Student()                     //无参构造
	{

	}
	Student(int id, string name)  //有参构造
	{
		this->id = id;
		this->name = name;
	}

	void printS()                 //打印函数
	{               
		cout << "id = " << this->id << ", name = " << this->name << endl;
	}
	
	int id;
	string name;
};


//创建一个新的学生类，增加score、功能
class Student2
{
public:
	Student2(int id, string name, int score)  //有参构造
	{
		this->id = id;
		this->name = name;
		this->score = score;
	}

	void printS()                             //打印函数
	{                           
		cout << "id = " << this->id << ", name = " << this->name << endl;
		cout << "score = " << this->score << endl;
	}
private:
	int id;
	string name;

	//add
	int score;
};


//通过继承创建一个新的学生类
class Student3 :public Student  //public表示继承方式
{
public:
	Student3(int id, string name, int score) :Student(id, name)  //直接给父类赋值
	{

		this->score = score;
	}

	void printS()                                                //打印函数
	{                      
		Student::printS();
		cout << "score = " << this->score << endl;
	}
private:
	int score;
};


int main(void)
{
	Student3 s3(1, "zhang3", 80);

	s3.printS();

	return 0;
}
