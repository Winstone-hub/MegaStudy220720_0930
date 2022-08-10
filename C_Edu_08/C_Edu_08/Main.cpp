/*
* Chapter 08
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>


int main(void)
{
	/*
	// ** 변수를 각각 선언하여 출력.
	int Number1 = 1;
	int Number2 = 2;
	int Number3 = 3;
	int Number4 = 4;
	int Number5 = 5;

	printf("Number1 : %d\n", Number1);
	printf("Number2 : %d\n", Number2);
	printf("Number3 : %d\n", Number3);
	printf("Number4 : %d\n", Number4);
	printf("Number5 : %d\n", Number5);
	printf("\n");
	*/

	// ** 단점 : 각각의 변수명을 직접 작성하여야 한다. 번거롭다.

	// ====================================================

	/*
	// ** 하나의 배열을 선언하여 출력
	int Number[5] = {1, 2, 3, 4, 5};

	printf("Number[0] : %d\n", Number[0]);
	printf("Number[1] : %d\n", Number[1]);
	printf("Number[2] : %d\n", Number[2]);
	printf("Number[3] : %d\n", Number[3]);
	printf("Number[4] : %d\n", Number[4]);
	printf("\n");
	*/

	// ** 장점1 : 배열로 선언함으로써, 초기화 구문이 현저히 줄었다.

	// ==▼==▼==▼==▼==▼==▼==▼==▼==▼==
	//				  응  용
	// ==▼==▼==▼==▼==▼==▼==▼==▼==▼==

	/*
	// ** 배열을 사용하여 출력할 때에는 아래와 같이 반복문을 통해 배열을 활용할 수 있다.
	for (int i = 0; i < 5; ++i)
		printf("Number[%d] : %d\n", i, Number[i]);
	printf("\n");
	*/

	// ** 장점2 : 위와 같이 출력함으로써, 출력의 구문도 현저히 줄었다.

	// ====================================================
	/*
	{
		** 사용이 불가능한 예.
		int Number[5] = 10;
		Number[5] = 10;
	}
	*/
	
	/*
	{
		// ** 정상적인 사용의 예
		int Array[5];

		//Array[0] = 1;
		//Array[1] = 2;
		//Array[2] = 3;
		//Array[3] = 4;
		//Array[4] = 5;

		printf("1. 입력 : ");
		scanf_s("%d", &Array[0]);

		printf("2. 입력 : ");
		scanf_s("%d", &Array[1]);

		printf("3. 입력 : ");
		scanf_s("%d", &Array[2]);

		printf("4. 입력 : ");
		scanf_s("%d", &Array[3]);

		printf("5. 입력 : ");
		scanf_s("%d", &Array[4]);
	}
	*/


	/*
	{
		// ** 배열의 초기화
		{
			// ** 전체 초기화
			int Array[5] = { 1, 2, 3, 4, 5 };

			// ** 5개의 원소에 각각 1,2,3,4,5 의 값이 초기화 됨
		}

		{
			// ** 부분 초기화
			int Array[5] = { 1, 2 };

			// ** 첫번째와 두번째 원소만 각각 1과 2로 초기화 되고,
			// ** 나머지 원소들은 0으로 초기화 된다.
		}

		{
			// ** 0 초기화
			int Array[5] = { 0 };

			// ** 전체 원소가 0으로 초기화 된다.
		}

		{
			// ** 배열의 길이를 정하지 않고 초기화.
			int Array[] = { 1, 2, 3, 4, 5 };
			// ** 전체 원소개수 만큼 길이를 초기화 한다.

			// ** 배열의 총 길이를 원소 1개의 데이터 크기로 나누면 원소의 개수를 확인할 수 있다.
			//int Count = sizeof(배열의 총 길이) / sizeof(원소 1개의 크기);
			int Count = sizeof(Array) / sizeof(int);

			printf("Count : %d\n", Count);
			printf("\n");
		}
	}
	*/


	/*
	{
		// ** 2의 n승에 해당하는 값으로 배열의 길이를 초기화 해준다.
		// ** 10 개만 사용하고 싶다면 16만큼의 길이로 초기화를 진행한 후
		int Array[16];
		
		// ** 아래와 같이 10만큼 사용하면 된다.
		for (int i = 0; i < 10; ++i)
		{
			Array[i] = 0;
		}
	}
	*/



	// **************************
	// *	문 자 열  배 열     *
	// **************************
/*
	{
		{
			// ** 널문자가 없는 경우
			//char Array[5] = { 'A', 'p', 'p', 'l', 'e' };
			//printf_s("%s", Array);
		}
		
		{
			// ** 널문자가 있는 경우
			char Array[6] = { 'A', 'p', 'p', 'l', 'e', '\0' };
			printf_s("%s", Array);
		}
	}
*/

	{
		// ** 문자열 초기화
		// ** 아래와 같이 문자열을 초기화 할 경우 자동으로 널 문자가 포함됨.
		char str1[128] = "cat";
		char str2[128];

		// ** 문자열 복사
		strcpy(str1, "tiger");
		strcpy(str2, str1);

		printf("str2 : %s\n", str2);
	}

	return 0;
}