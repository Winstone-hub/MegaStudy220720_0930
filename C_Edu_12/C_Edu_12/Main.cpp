/*
* Chapter 12
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string>


int main(void)
{
	/*
	printf("apple이 저장된 시작 주소 값 : %p\n", "apple");
	printf("두번째 문자 주소 값 : %p\n", "apple" + 1);
	printf("첫번째 문자 : %c\n", *"apple");
	printf("두번째 문자 : %c\n", *("apple" + 1));
	printf("배열로 표현한 세번째 문자 : %c\n", "apple"[2]);
	*/


	// 451 예제
	/*
	{
		int* pi;
		double* pd;

		pi = (int*)malloc(sizeof(int));

		if (pi == NULL)
		{
			printf("# 메모리가 부족합니다.\n");
			exit(1);
		}

		pd = (double*)malloc(sizeof(double));

		*pi = 10;
		*pd = 3.141592;

		printf("정수형으로 사용 : %d\n", *pi);
		printf("실수형으로 사용 : %.7lf\n", *pd);

		free(pi);
		free(pd);
	}
	*/

	/*
	{
		printf("(void*) size : %d\n", sizeof(void*));
	}
	*/

	/*
	{
		// ** (void*) 의 사용
		int Array[5] = {10, 20, 30, 40, 50};

		void* pArr = Array;

		int* i = (int*)pArr;
		float* f = (float*)pArr;

		// ** 형태가 보존되었을때 출력
		printf("%d\n", *i);

		// 형태가 바뀔때 발생할 수 있는 문제
		printf("%f\n", *f);
	}
	*/

	//==============================================

	// ** int* pi = (int*)malloc(메모리를 할당할 크기);
	// ** int* pi = (int*)malloc(sizeof(int));
	// ** int* pi = (int*)malloc(4); 숫자를 사용해도 됨.

	{
		const int MAX = 8;

		int* Array = (int*)malloc(sizeof(int) * MAX);

		for (int i = 0; i < MAX; ++i)
			Array[i] = (10 * i + 10);

		for (int i = 0; i < MAX; ++i)
			printf("%d\n", Array[i]);
	}

	return 0;
}


