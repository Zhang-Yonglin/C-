/*
模板的特殊化是当模板中的 pattern 有确定的类型时， 模板有一个具体的实现。 例如假设我们的类模板 pair1 包含一个取模
计算（module operation） 的函数， 而我们希望这个函数只有当对象中存储的数据为整型(int)的时候才能工作， 其他时候， 
我们需要这个函数总是返回 0。 这可以通过下面的代码来实现：
*/

// Template specialization
#include <iostream>

using namespace std;

template <class T> 
class pair1 
{
	T value1, value2;
	public:
		pair1 (T first, T second){value1=first;value2=second;}   //有参构造函数
		T module () {return 0;}
};

template <>
class pair1 <int> 
{
	int value1, value2;
	public:
		pair1 (int first, int second){value1=first;value2=second;} 
		
		int module ()
		{
			return value1%value2;
		}
};




int main () 
{
	pair1 <int> myints (100,75);
	pair1 <float> myfloats(100.0,75.0);
	cout << myints.module() << '\n';
	cout << myfloats.module() << '\n';
	return 0;
}

/*
25
0
*/
