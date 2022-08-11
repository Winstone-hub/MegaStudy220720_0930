/*
* Chapter 09
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>


int main(void)
{
	{
		// ** 1단계
		
		// ** 일반 변수
		int Number = 10;
		// ** 일반 변수는 데이터를 갖는다

		// ** 포인터 변수
		int* pNumber;
		// ** 포인터 변수는 [*] 을 붙혀준다.
		// ** 포인터 변수는 일반변수의 주소를 갖는다.
	}
	
	{
		// ** 2단계
		int Number = 10;

		// ** 주소는 다음과 같이 표현할 수 있다.
		printf_s("주소 : %p\n", &Number);
		printf_s("데이터 : %d\n", Number);
		printf_s("\n");
	}

	{
		// ** 3단계
		int Number = 10;

		// ** 포인터 변수는 일반변수의 주소를 받는다.
		int* pNumber = &Number;

		// ** 포인터 변수가 데이터를 출력할 때에는 항목 앞에 [*] 를 붙인다.
		printf_s("Pointer : %d\n", *pNumber);
		printf_s("\n");
	}


	{
		// ** 4단계
		int Number = 10;

		// ** 포인터 변수는 일반변수의 주소를 받는다.
		int* pNumber = &Number;

		// ** 포인터 변수가 데이터를 출력할 때에는 항목 앞에 [*] 를 붙인다.
		printf_s("Number 값 : %d\n", Number);
		printf_s("Pointer 가 가르키는 값 : %d\n", *pNumber);
		printf_s("Number 주소 : %p\n", &Number);
		printf_s("Pointer 가 가르키는 값 : %p\n", pNumber);
		printf_s("Pointer 의 주소 : %p\n", &pNumber);

		printf_s("\n");
	}

	{
		// ** 포인터 변수와 일반변수는 데이터를 공유한다.
		// ** 검증 
		int Number = 10;

		// ** 포인터 변수는 일반변수의 주소를 받는다.
		int* pNumber = &Number;

		// ** 포인터 변수가 데이터를 출력할 때에는 항목 앞에 [*] 를 붙인다.
		printf_s("Number 값 : %d\n", Number);
		printf_s("Pointer 가 가르키는 값 : %d\n", *pNumber);
		printf_s("\n");

		// ** 일반 변수의 값만 변경
		Number = 100;

		printf_s("Number 값 : %d\n", Number);
		printf_s("Pointer 가 가르키는 값 : %d\n", *pNumber);
		printf_s("\n");

		// ** 포인터 변수의 값만 변경
		*pNumber = 1000;

		printf_s("Number 값 : %d\n", Number);
		printf_s("Pointer 가 가르키는 값 : %d\n", *pNumber);
		printf_s("\n");
	}


	// ** swap
	{
		int a = 10;
		int b = 20;

		printf("a : %d\n", a);
		printf("b : %d\n\n", b);

		if (true)
		{
			int temp = a;
			a = b;
			b = temp;
		}

		printf("a : %d\n", a);
		printf("b : %d\n\n", b);
	}
	

	{
		int a = 10;
		int b = 20;

		a ^= b;
		b ^= a;
		a ^= b;
		
		printf("a : %d\n", a);
		printf("b : %d\n\n", b);
	}





	{
		// ** 포인터의 크기는 개발환경에 따라 그 크기가 달라진다.
		int Number = 10;
		long long lNum = 10;
		long long* Pointer = &lNum;

		// ** 포인터의 크기
		// x86 = 4byte
		// x64 = 8byte

		printf("int : %d\n", sizeof(Number));
		printf("long long : %d\n", sizeof(lNum));
		printf("Pointer : %d\n\n", sizeof(Pointer));
	}

	return 0;
}