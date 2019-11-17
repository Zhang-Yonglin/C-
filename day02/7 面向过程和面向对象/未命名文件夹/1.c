#include<stdio.h>
#include<string.h>


int main()
{
	int substring(char* s, char a);      //函数声明
	//char *string= "aaabbbcc";          //warning的原因是字符串常量存放在const内存区...
	char string[]= "aaabbbcc";           //warning的原因是字符串常量存放在const内存区...
	//而字符串指针变量定义却是指向char型，稍微有点区别，但是不影响结果。  
	char b = 'c';
	printf("%d\n",substring(string,b));
	
	return 0;
    
}


//函数定义
int substring(char* s, char a) //判断一个字符是否存在于大的字符串中 
{
    int result=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(a==*(s+i))
        {
            result = 1;
            //return 1;
        }
        //else break;
    }
    return result;
}

