/*
* Chapter 11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string>


int main(void)
{
	{
		// ** 배열을 사용한 문자 출력
		//char Buffer[5] = "한글";
		char Buffer[] = "한글";

		// ** 출력
		printf("%c%c %c%c\n",
			Buffer[0],
			Buffer[1],
			Buffer[2],
			Buffer[3]);
	}
	printf("\n");

	{
		// ** 포인터를 사용한 문자 출력
		
		// ** "한글" = 문자열로 초기화 되어있기 때문에 char[5] 만큼의 길이를 갖고있다.
		// ** 문자열 또한 배열로 인식하기 때문에 다음과 같이 형 변환이 필요하다.
		char* Buffer = (char*)"한글";

		// ** 출력
		printf("%c%c %c%c\n",
			Buffer[0],
			Buffer[1],
			Buffer[2],
			Buffer[3]);
	}
	printf("\n");

	/*
	{
		// ** 포인터 변수에 문자를 직접 입력받을수 없음.
		char* Buffer = (char*)"한글";

		scanf("%s", Buffer);
		printf("%s", Buffer);
	}
	*/

	/*
	{
		char Buffer[128] = "";

		scanf("%s", Buffer);
		printf("%s", Buffer);
	}
	*/


	{
		int* Number = (int*)malloc(sizeof(int) * 10);

		for (int i = 0; i < 10; ++i)
			Number[i] = i + 1;

		for (int i = 0; i < 10; ++i)
			printf("%d\n", Number[i]);

		printf("sizeof : %d", sizeof(Number));
	}

	return 0;
}