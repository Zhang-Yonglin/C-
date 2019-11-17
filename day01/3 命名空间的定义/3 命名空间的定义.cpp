#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


//定义一个命名空间
namespace spaccA {

	int g_a = 10;
}


namespace spaceB {

	int a = 20;

	namespace spaceC {
	
		struct teacher
		{
			int id;
			char name[64];
		};
	}

	namespace spaceD {
	
		struct teacher
		{
			int id;
			char name[64];
		};
	}

	using namespace spaceC; //在spaceB中使用了using namespace spaceC，因此在main函数中只需要使用usning namespace spaceB即可使用struct teacher
}


int main(void)
{
	//using spaccA::g_a;
	using namespace spaccA;
	int a = 10;
	cout << g_a << endl;


	//spaceB::spaceC::teacher t1;
	//using spaceB::spaceC::teacher;
	//teacher t1;

	//using namespace spaceB::spaceC;   //在引用命名空间时，一定要引用到底部
	//spaceB::spaceC::teacher t1;

	using namespace spaceB;
	teacher t1;

	t1.id = 10;

	//spaceB::spaceD::teacher t2;
	//t2.id = 20;
	
	cout << t1.id <<endl;

	return 0;
}
