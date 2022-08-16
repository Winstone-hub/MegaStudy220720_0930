/*
* Chapter 11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string>





void print_arr(int* _pArr, int _size);
//void print_arr(int _pArr[], int _size);

int main(void)
{
	/*
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
	*/

	/*
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
	*/

	/*
	{
		// ** 포인터 변수에 문자를 직접 입력받을수 없음.
		char* Buffer = (char*)"한글";

		scanf("%s", Buffer);
		printf("%s", Buffer);
	}
	printf("\n");
	*/

	/*
	{
		char Buffer[128] = "";

		scanf("%s", Buffer);
		printf("%s", Buffer);
	}
	printf("\n");
	*/

	/*
	{
		int* Number = (int*)malloc(sizeof(int) * 10);

		for (int i = 0; i < 10; ++i)
			Number[i] = i + 1;

		for (int i = 0; i < 10; ++i)
			printf("%d\n", Number[i]);

		printf("sizeof : %d", sizeof(Number));
	}
	printf("\n");
	*/



	//===================================================

	/*
	int Array[5] = { 10, 20, 30, 40, 50 };

	int* pArr = Array;
	int* pArr2 = Array + 2;


	printf("1. 주소 : %d\n", Array); // 시작 주소
	printf("1. 값 : %d\n", *Array); // 시작 값
	printf("2. %d\n", *(Array + 1) ); // 20
	printf("3. 주소 : %d\n", pArr + 2);  // 30의 주소
	printf("3. 값 : %d\n", *(pArr + 2));  // 30의 값
	printf("4. %d\n", pArr[3]);  // 40
	printf("5. %d\n", *pArr2);  // 30
	printf("6. %d\n", pArr2 - pArr); // ?
	printf("6. %d\n", pArr2[-2]); // ?
	*/


	//0x0010
	//0x0014
	//0x0018
	//0x0022
	//0x0026
	
	//0x0010
	//0x0018
	//--------
	//0x0008


	//===================================================

	int Array[5] = { 10, 20, 30, 40, 50 };

	print_arr(Array, 5);

	// ** 배열이 선언된 영역 안에서 배열의 크기를 아래와 같은 계산식을 통해 확인할 수 있다.
	int Size = sizeof(Array) / sizeof(Array[0]);
	printf("%d\n", Size);

	return 0;
}

/*
* 배열을 전달할 때에는 [int*]와 같은 방식으로 아래와 같이 전달가능. (  [int*] == [ int _pArr[] ] )
void print_arr(int _pArr[], int _size)
{

	for (int i = 0; i < _size; ++i)
	{
		printf("%d\n", _pArr[i]);
		//printf("%d\n", *(pArr+i));
	}
}
*/

// ** 배열을 함수로 전달 할 때에는 반드시 배열의 크기를 함께 전달해야 한다.
void print_arr(int* _pArr, int _size)
{
	for (int i = 0; i < _size; ++i)
	{
		printf("%d\n", _pArr[i]);
		//printf("%d\n", *(pArr+i));
	}
}

