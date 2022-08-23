/*
* Chapter 17
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>


int main(void)
{
	/*
	{
		// ** 개별 초기화 방법
		char Array[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };

		for (int i = 0; i < 10; ++i)
		{
			printf("%c", Array[i]);
		}
		printf("\n");
		printf("%s\n\n", Array);
	}
	*/


	/*
	{
		// ** 문자열 초기화 방법.
		char Array[10] = { "ABCDEFGHI" };

		// ** 문자열 초기화 시에는 마지막 문자열이 끝나는 지점에 NULL값이 들어가야 한다.
		// ** NULL 값의 공간이 1byte 만큼 필요하므로 개별초기화 방법보다 공간이 1더 필요함.

		{
			// ** 널 문자
			NULL;
			'\0';
		}

		for (int i = 0; i < 10; ++i)
		{
			printf("%c", Array[i]);
		}
		printf("\n");
		printf("%s\n", Array);
	}
	*/


	{
		//(int* Pointer = &int)
		//(short* Pointer = &short)
		//(long* Pointer = &long)

		//(char* Pointer = &char)


		/*
		// ** 문자 배열 초기화
		char Buffer[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', NULL };

		// ** Buffer의 주소를 str1으로 대입
		char* str1 = Buffer;

		// ** str1변수가 받은 주소를 str2에 동일하게 넘겨준다.
		// ** str1과 str2가 같은 주소를 참조 받고있다.
		char* str2 = str1;

		// ** 이때 str1의 주소에 있는 내용을 변경하게된다면
		str1[3] = 'A';

		// ** str2 도 같은 주소를 참조 받았기 때문에 내용이 함께 변경 되는것을 알수 있다.
		printf("str2 : %s\n", str2);
		*/
	}

	{
		// ** 파일 저장하기

		FILE* pf = fopen("../Datas/Data.txt", "wt");

		if (pf == NULL)
			printf("파일을 열지 못했습니다\n");
		else
		{
			int Age = 32;
			char Name[128] = "홍길동";

			fprintf(pf, "%s : %d", Name, Age);

			fclose(pf);
		}
	}



	{
		// ** 파일 불러오기

		FILE* pf = fopen("../Datas/Data.txt", "r");

		int Age[20];
		char Name[128];

		int Count = 0;
		while (fgetc(pf) != NULL)
		{
			//int n = fscanf(pf, "%d", &Age);
			fgets(Name, sizeof(Name), pf);

			printf("%s\n", Name);
			fflush(pf);
		}
	}



	

	



	return 0;
}