#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


class Student
{
public:
	Student(int id, double score)  //有参构造函数
	{
		//创建一个学生
		m_id = id;
		m_score = score;

		m_count++;            //累加一个个数  学生人数
		sum_score += score;   //分数累加和
	}

	static int getCount()         //获得学生人数
	{
		return m_count;
	}

	static double getAvg()        //返回学生平均成绩
	{
		return sum_score / m_count;
	}

	~Student() 
        {
		m_count--;
		sum_score -= m_score;
	}

private:
	int m_id;
	double m_score;              //得分

	//统计学生个数的静态成员变量
	static int m_count;          //静态成员变量在这里的好处就是能够在多个实例之间共享，从而实现累加

	//统计学生总分数的静态成员变量
	static double sum_score;
};


int Student::m_count = 0;

double Student::sum_score = 0.0;


int main(void)
{
	Student s1(1, 80);
	Student s2(2, 90);
	Student s3(3, 100);  //析构时先创建的实例后释放

	cout << "学生总人数: " << Student::getCount() << endl;  //因为变量是private,因此不能直接引用，需要使用类中的函数来获得
	cout << "学生的平均分: " << Student::getAvg() << endl;

	return 0;
}
