#include "Operator.h"


// ** Getter
// ** Setter


class Copy
{
public:
	char* name;

public:
	Copy() : name(nullptr) {}

	Copy(Copy* pCopy)
	{ 
		this->name = new char[strlen(pCopy->name)];
		strcpy(this->name, pCopy->name);
	}
};


int main(void)
{
	//** 실수 연산
	// 부호   지수부              가수부
	// 0     00000000    00000000000000000000000

	// 128.625 => 
	
	// ** 고정 소수점 
	//       정수부              실수부
	// 0 0000000 10000000 . 10100000 00000000

	// 1.0000000101 의  7 승.

	// 부동 소수점
	// 부호   지수부              가수부
	// 0     10000110    00000001010000000000000

	//===================================================



	//** 연산자 오버로딩
	/*
	Operator o;
	o.setAge(32);
	o.setName((char*)"홍길동");

	o.render();
	*/



	//==============================================

	// ** 깊은복사 & 얕은복사

	// ** c1을 생성
	Copy* c1 = new Copy;

	// ** c1 의 name 에 이름을 초기화.
	c1->name = (char*)"홍길동";



	//=================================
	
	// ** c2 에 c1 을 복사.
	//Copy* c2(c1); // 안됨.

	// ** c2 에 c1 을 복사.
	Copy* c2 = new Copy(c1); // 됨

	//=================================



	// ** c1이 삭제되기 전에 c2의 name은 정상 출력된다.
	//cout << c2->name << endl; // 정상 출력

	// ** c1 을 삭제.
	delete c1;

	// ** c2의 name을 출력.
	cout << c2->name << endl; // 출력되지 않음.



	return 0;
}