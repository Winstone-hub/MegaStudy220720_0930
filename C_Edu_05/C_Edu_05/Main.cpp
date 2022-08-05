/*
* Chapter 05
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	// ** 1. 정수기 앞에서 물을 마신다.
	// ** 2. 만약에 정수기 앞에 컵이 없다면...
	// **  - 인포에서 컵을 받아온다.


	// ** 컴퓨터 스크립트 **
	// ** 1. 정수기앞에 선다.
	// ** 2. 컵을 탐색한다.
	// ** 3. 만약 컵이 없다면... if(조건)
	//		- 인포에서 컵을 받아온다. { 조건이 맞다면 행동하게될 실행문 }
	// ** 4. 컵을 손에 쥔다.
	// ** 5. 컵에 물을 담아 마신다.



	// ** if ~ else 문
	/*
	{
		int Number;

		printf("입력 : ");
		scanf_s("%d", &Number);

		if (Number == 1)
			printf("홍길동"); 
		else if (Number == 2)
			printf("임꺽정");
		else if (Number == 3)
			printf("이몽룡");
		else
			printf("잘못 입력 하였습니다.");
		printf("\n\n");
	}
	*/


	// ** switch ~ case 문
	/*
	{
		int Number;

		printf("입력 : ");
		scanf_s("%d", &Number);

		switch (Number)
		{
		case 1:
			printf("홍길동");
			break;
		case 2:
			printf("임꺽정");
			break;
		case 3:
			printf("이몽룡");
			break;
		default:
			printf("잘못 입력 하였습니다.");
		}
		printf("\n\n");
	}
	*/

	return 0;
}