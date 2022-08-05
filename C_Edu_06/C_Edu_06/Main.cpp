/*
* Chapter 06
*/

#include <stdio.h>

int main(void)
{
	// ** 반복문 (while)
	{
		// ** 조건이 무한루프 조건일때
		while (true)
		{
			// ** 탈출할 수 있는 요소가 필요하다.
			if (true)
				break;
		}
		printf("\n");
	}

	// ** 반복문 (for)
	{
		// ** 반복 될 횟수를 정해놓고 반복 해야하는 경우.
		// for( 초기문 ; 조건문 ; 증감문 )
		// ** 초기문, 조건문, 증감문 이 세가지 요소가 필요하다.
		for (int i = 0; i < 10; ++i)
		{
			printf("for 반복문 %d\n", i + 1);
		}
		printf("\n");
	}





	{
		// ** 일정 횟수 만큼 반복해야할때....

		int i = 0; // 초기문

		while (i < 10) // 조건문
		{
			printf("while 반복문 %d\n", i + 1);
			++i; // 증감문
		}
		// ** 초기문, 조건문, 증감문 이 세가지 요소가 필요하다.
		printf("\n");
	}


	{
		// 반복문 for

		// ** for문의 무한루프 조건일때
		for (;true;)
		{
			printf("for 반복문\n");

			// ** 탈출할 수 있는 요소가 필요하다.
			if (true)
				break;
		}
		printf("\n");
	}


	do
	{
		printf("최초에 한번은 실행됨.");
		break;
	} while (false);
	printf("\n");

	return 0;
}