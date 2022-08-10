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

	return 0;
}