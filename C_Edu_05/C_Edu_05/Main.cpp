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



	{
		char* Name;
		int Number;

		printf("입력 : ");
		scanf("%d", &Number);

		if (Number == 1)
		{
			Name = (char*)"홍길동";
		}
		else if (Number == 2)
		{
			Name = (char*)"임꺽정";
		}
		else
		{
			Name = (char*)"이몽룡";
		}

		printf("결과 값 : %s\n", Name);
		printf("\n");
	}
	











	return 0;
}