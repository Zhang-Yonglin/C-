#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

//--------  抽象层---------
//抽象CPU类
class CPU
{
public:
	CPU(){};                      //不能直接写CPU();   CPU()表示函数的调用   而CPU(){}表示函数的定义
	virtual void caculate() = 0;  //纯虚函数
};


//抽象的card类
class Card
{
public:
	virtual void display() = 0;   //纯虚函数
};


//抽象的内存类
class Memory
{
public:
	virtual void storage() = 0;  //纯虚函数
};


//架构类
class Computer
{
public:
	Computer(CPU *cpu, Card *card, Memory *mem)  //有参构造
	{
		this->cpu = cpu;
		this->card = card;
		this->mem = mem;
	}

	void work()     //普通成员函数
	{
		this->cpu->caculate();
		this->card->display();
		this->mem->storage();
	}

	~Computer() {   //析构函数
		cout << "开始析构" << endl;
		if (this->cpu != NULL) {
			delete this->cpu;
		}
		if (this->card != NULL) {
			delete this->card;
		}
		if (this->mem != NULL) {
			delete this->mem;
		}
	}
private:
	CPU* cpu;     //类指针
	Card*card;
	Memory *mem;
};
// --------------------------

//-----------实现层----------
//具体的IntelCPU
class IntelCPU :public CPU
{
public:
	virtual void caculate() {                   //纯虚函数重写
		cout << "Intel CPU开始计算了" << endl;
	}
};

class IntelCard :public Card
{
public:
	virtual void display() {
		cout << "Intel Card开始显示了" << endl;

	}
};

class IntelMem :public Memory {
public:
	virtual void storage() {
		cout << "Intel mem开始存储了" << endl;

	}
};

class NvidiaCard :public Card
{
public:
	virtual void display() {
		cout << "Nvidia 显卡开始显示了" << endl;
	}
};

class KingstonMem :public Memory {
public:
	virtual void storage() {
		cout << "KingstonMem 开始存储了" << endl;
	}
};

//--------------------------



//--------业务层-------------------
int main(void)
{
	//1 组装第一台intel系列的电脑
#if 1
	CPU *intelCpu = new IntelCPU;
	Card *intelCard = new IntelCard;
	Memory *intelMem = new IntelMem;

	Computer *com1 = new Computer(intelCpu, intelCard, intelMem);
	com1->work();
	delete com1;      //delete com1的同时会调用com1的析构函数
	
	
	cout << "-------------------" << endl;
	
	#if 1
	CPU *intelCpu2 = new IntelCPU;
	Card *nCard2 = new NvidiaCard;
	Memory* kMem2 = new KingstonMem;
	
	Computer *com2 = new Computer(intelCpu2, nCard2, kMem2);
	com2->work();
	delete com2;
	#endif
	
	cout << "-------------------" << endl;
	
	//或者：
	#if 1
	intelCpu = new IntelCPU;
	intelCard = new IntelCard;
	intelMem = new IntelMem;
	
	Computer *com = new Computer(intelCpu, intelCard, intelMem);
	com->work();
	delete com;
	#endif
	/*
	但是不可以：
	CPU *intelCpu = new IntelCPU;
	Card *nCard = new NvidiaCard;
	Memory* kMem = new KingstonMem;
	因为intelCpu、nCard、kMem三个指针指针变量已经定义了，可以继续赋值，但是不可以再次定义	
	*/
	
	cout << "-------------------" << endl;
#endif

	Computer *com3 = new Computer(new IntelCPU, new IntelCard, new IntelMem);  //匿名定义  不定义具体的指针变量（优点是方便快捷，缺点是不能再次利用这些构将的内存了）  
	                                                                           //类似于Qt中的空间中的不指出具体指针名称的定义
	com3->work();
	delete com3;

	return 0;
}
