#include "MyString.h"


//无参构造函数
MyString::MyString()    
{
	this->len = 0;
	this->str =NULL;  //this->str =NULL; this->str = "";  这两个语句不同，前面表示不指向任何内存，后面表示指向空字符串
}


//拷贝构造函数  将str拷贝给this->str
MyString::MyString(const char *str)  
{
	if (str == NULL) 
	{
		this->len = 0;
		this->str = new char[0 + 1];
		strcpy(this->str, "");          //如果str为空开辟空字符串
	}
	else {
		int len = strlen(str);          //这个len是有效长度，即不包括\0
		this->len = len;                //这个len是有效长度，即不包括\0

		this->str = new char[len + 1];  //在堆上开辟内存空间  加1是额外存放\0的
		strcpy(this->str, str);
	}
}


//拷贝构造函数
//初始化时候被调用的
MyString::MyString(const MyString &another)   
{
	this->len = another.len;                //字符串的有效长度（不包括\0）
	this->str = new char[this->len + 1];    //重新在堆上开辟内存
	strcpy(this->str, another.str);         //拷贝
}


//析构函数
MyString::~MyString()   
{
	if (this->str != NULL) 
	{
		cout << this->str << "执行了析构函数" << endl;
		delete this->str;                            //释放内存
		this->str = NULL;                            //重新给指针赋值为空
		this->len = 0;
	}
}


//[]重载
char & MyString::operator[](int index)  
{
	return this->str[index];                            //返回的是引用
}


//=重载
MyString &  MyString::operator=(const MyString &another)  
{
	if (this == &another) 
	{
		return *this;
	}

	if (this->str != NULL) 
	{
		delete[] this->str;
		this->str = NULL;
		this->len = 0;
	}

	this->len = another.len;
	this->str = new char[this->len + 1];
	strcpy(this->str, another.str);

	return *this;
}


//<<重载
ostream & operator<<(ostream &os, MyString&s)  
{
	os << s.str;     //返回的是指针
	return os;
}


//>>重载
istream & operator>>(istream &is, MyString &s)  
{
	//1 将s之前的字符串释放掉
	if (s.str != NULL) 
	{
		delete[] s.str;
		s.str = NULL;
		s.len = 0;
	}

	//2 通过cin添加新的字符串
	char temp_str[4096] = { 0 };
	cin >> temp_str;                            //输入字符串

	int len = strlen(temp_str);
	s.str = new char[len + 1];                  //在堆上开辟新的内存
	strcpy(s.str, temp_str);
	s.len = len;

	return is;
}


//+重载
MyString MyString::operator+(MyString &another)     //返回匿名对象
{
	MyString temp;

	int len = this->len + another.len;

	temp.len = len;

	temp.str = new char[len + 1];
	memset(temp.str, 0, len + 1);               //下面是追加，所以temp.str需要清空，否则不知道会追加到什么地方  如果下面一行是用strcpy，则不需要使用memset进行清空
	strcat(temp.str, this->str);
	strcat(temp.str, another.str);
	
	/*
	temp.str = new char[len + 1];
	//memset(temp.str, 0, len + 1); 
	strcpy(temp.str, this->str);
	strcat(temp.str, another.str);              //此行代码不需要使用strcpy，因为上一行代码一定会产生\0，可以进行追加  而且如果这行也使用strcpy，则会将上面的内容覆盖掉。
	*/
	

	return temp;
}

