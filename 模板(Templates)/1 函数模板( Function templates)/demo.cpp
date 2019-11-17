/*
模板(Templates)使得我们可以生成通用的函数， 这些函数能够接受任意数据类型的参数， 可返回任意类型的值， 而不需要
对所有可能的数据类型进行函数重载。 这在一定程度上实现了宏（macro） 的作用。 它们的原型定义可以是下面两种中的任
何一个：
template <class identifier> function_declaration;
template <typename identifier> function_declaration;

上面两种原型定义的不同之处在关键字 class 或 typename 的使用。 它们实际是完全等价的， 因为两种表达的意思和执行
都一模一样。
例如， 要生成一个模板， 返回两个对象中较大的一个， 我们可以这样写：
template <class GenericType>
GenericType GetMax (GenericType a, GenericType b) { return (a>b?a:b); }

在第一行声明中， 我们已经生成了一个通用数据类型的模板， 叫做 GenericType。 因此在其后面的函数中， GenericType 
成为一个有效的数据类型， 它被用来定义了两个参数a 和 b ， 并被用作了函数 GetMax 的返回值类型。

GenericType 仍没有代表任何具体的数据类型； 当函数 GetMax 被调用的时候， 我们可以使用任何有效的数据类型来调用它。
这个数据类型将被作为 pattern 来代替函数中GenericType 出现的地方。 用一个类型 pattern 来调用一个模板的方法如下：
function <type> (parameters);
例如， 要调用 GetMax 来比较两个 int 类型的整数可以这样写：
int x,y;
GetMax <int> (x,y);
因此， GetMax 的调用就好像所有的 GenericType 出现的地方都用 int 来代替一样。
这里是一个例子：
*/

// function template
#include <iostream>

using namespace std;

template <class T> 
T GetMax (T a, T b) 
{
	T result;
	result = (a>b)? a : b;
	return (result);
} 

int main () 
{
	int i=5, j=6, k;
	long l=10, m=5, n;
	k=GetMax<int>(i,j);  //可写为： k=GetMax(i,j); 
	n=GetMax<long>(l,m); //写为：n=GetMax<long>(l,m);
	cout << k << endl;
	cout << n << endl;
	return 0;
}

/*
在这个例子中， 我们将通用数据类型命名为 T 而不是 GenericType ， 因为 T 短一些，并且它是模板更为通用的标示之一，
虽然使用任何有效的标示符都是可以的。 )

在上面的例子中， 我们对同样的函数 GetMax()使用了两种参数类型： int 和 long， 而只写了一种函数的实现， 也就是说
我们写了一个函数的模板， 用了两种不同的 pattern来调用它。

如你所见， 在我们的模板函数 GetMax() 里， 类型 T 可以被用来声明新的对象
T result;
result 是一个 T 类型的对象， 就像 a 和 b 一样， 也就是说， 它们都是同一类型的， 这种类型就是当我们调用模板函数
时写在尖括号<> 中的类型。

在这个具体的例子中， 通用类型 T 被用作函数 GetMax 的参数， 不需要说明<int>或<long>， 编译器也可以自动检测到传
入的数据类型， 因此， 我们也可以这样写这个例子：
int i,j;
GetMax (i,j);
因为 i 和 j 都是 int 类型， 编译器会自动假设我们想要函数按照 int 进行调用。 这种暗示的方法更为有用， 
并产生同样的结果：
*/
