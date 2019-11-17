/*
我们也可以定义类模板（class templates） ， 使得一个类可以有基于通用类型的成员，而不需要在类生成的时候定义具体
的数据类型
*/

// class templates
#include <iostream>

using namespace std;


template <class T> 
class pair1 
{
	T value1, value2;
	public:
		pair1 (T first, T second) 
		{
			value1=first;
			value2=second;
		} 
		
		T getmax ()
		{

			T retval;
			retval = value1>value2?value1:value2;
	
			return retval;

		}
};




int main () 
{

	pair1<int> myobject (100, 75);
	cout << myobject.getmax() << endl;
	
	return 0;
}
