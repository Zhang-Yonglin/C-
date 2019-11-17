/*
除了模板参数前面跟关键字 class 或 typename 表示一个通用类型外， 函数模板和类模板还可以包含其它不是代表一个类型
的参数， 例如代表一个常数， 这些通常是基本数据类型的。 例如， 下面的例子定义了一个用来存储数组的类模板：
*/

// array template
#include <iostream>

using namespace std;

template <class T, int N>
class array 
{
	T memblock [N];
	public:
		void setmember (int x, T value);
		T getmember (int x);
};

template <class T, int N>
void array<T,N>::setmember (int x, T value) 
{
	memblock[x]=value;
} 

template <class T, int N>
T array<T,N>::getmember (int x) 
{
	return memblock[x];
} 


int main () 
{
	array <int,5> myints;
	array <float,5> myfloats;
	myints.setmember (0,100);
	myfloats.setmember (3,3.1416);
	cout << myints.getmember(0) << '\n';
	cout << myfloats.getmember(3) << '\n';
	return 0;
}

/*
100
3.1416
*/

/*我们也可以为模板参数设置默认值， 就像为函数参数设置默认值一样。
下面是一些模板定义的例子：
	template <class T> // 最常用的： 一个 class 参数。
	template <class T, class U> // 两个 class 参数。
	template <class T, int N> // 一个 class 和一个整数。
	template <class T = char> // 有一个默认值。
	template <int Tfunc (int)> // 参数为一个函数。
*/
