/*
* Chapter 06
*/

#include <stdio.h>

int main(void)
{
	/*
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
	*/

	/*
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
	*/




	/*
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
	*/


	/*
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
	*/


	/*
	do
	{
		// ** 최초 1회는 반드시 실행됨.
		printf("최초에 한번은 실행됨.");
		break;

		// ** 그 후에 조건을 확인하고 조건이 true인 경우 반복.
	} while (false);
	printf("\n");
	*/

	//==========================================================


	// ** 반복문의 중복 사용
	// [구구단]
	
	// 2 x 1 = 2
	// 2 x 2 = 4
	//    .
	//    .
	//    .
	//    .
	// 2 x 8 = 16
	// 2 x 9 = 18

	{
		int x, y;

		printf_s("시작단/끝단 입력 : ");
		scanf_s("%d %d", &x, &y);

		for (int i = x; i < y + 1; ++i)
		{
			for (int j = 2; j < 10; ++j)
			{
				//if (i % 2 || !(j % 2))
					//continue;

				//if (i % 2 && !(j % 2))
				printf_s("%d x %d = %d\n", i, j, i * j);
			}
			printf("\n");
		}
		printf("\n");
	}



	return 0;
}