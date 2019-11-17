#include <iostream>
#include <cstring>

using namespace std;

//函数模板
template<class T>
bool IsEqual(T t1,T t2){
    return t1==t2;
}

//函数模板特化
template<> 
bool IsEqual(char *t1,char *t2){
    return strcmp(t1,t2)==0;
}

int main(int argc, char* argv[])
{
    char str1[]="abc";
    char str2[]="abc";
    cout<<"函数模板和函数模板特化"<<endl;
    cout<<IsEqual(1,1)<<endl;
    cout<<IsEqual(str1,str2)<<endl;

    return 0;
}

