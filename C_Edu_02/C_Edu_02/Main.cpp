/*
* Chapter 02
*/
#include <stdio.h>
#include <stdlib.h>



// **함수
void Output()
{
	printf_s("Hello World!!\n");
}


int main(void)
{
	Output();
	/*
	{
		printf_s("Hello World!!");
	}
	*/
	10 + 20;

	// ** 문자와 문자열
	// 'A' = 문자
	// 'AB' = X
	// 'H', 'e', 'l', 'l', 'o'
	
	// "A" = 문자열
	// "AB" = O
	// "Hello"
	printf("\n");


	// ** 서식문자
	// %d = 정수 표현
	// %f = 실수 표현
	// %c = 문자 표현
	// %s = 문자열 표현
	// %% = % 표현

	printf("정수 출력 : %d\n", 10);
	printf("실수 출력 : %f\n", 3.141592f);
	printf("문자 출력 : %c\n", 'A');
	printf("문자 출력 : %c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o');
	printf("문자열 출력 : %s\n", "A");
	printf("문자열 출력 : %s\n", "Hello");
	printf("%d%% 입니다.\n",100);




	printf("\n");
	// \n = 줄바꿈 표현
	// \t = tab 표현
	// \b = backspace(삭제)
	// \\ = \  표현
	
	printf("goot\bd\tchance\n");
	printf("10,000\\\n");


	printf("%d과 %d의 합은 %d 입니다.\n", 14254, 23421, 14254 + 23421);


	printf("\n");
	// ** 진수 표현

	printf("10진수의 10 : %d\n", 10);
	printf("8진수의 10 : %d\n", 010);
	printf("16진수의 10 : %d\n", 0x10);


	printf("\n");
	// ** 아스키 코드표
	printf("65 문자 출력 : %c\n", 65);
	printf("A 정수 출력 : %d\n", 'A');
	
	





	return 0;
}