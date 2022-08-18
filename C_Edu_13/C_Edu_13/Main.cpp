/*
 * Chapter 13
 */
#include <stdio.h>
#include <string>

struct Student
{
	char* Name;
	int Number;
	int Kor;
	int Eng;
	int Math;
};

void Output(Student* _std, int _size);

int main(void)
{
	Student Std[40];

	//Std[0].Name = (char*)"홍길동";

	// ** 배열의 크기를 알 수 있다.
	for (int i = 0; i < (sizeof(Std) / sizeof(Std[0])); ++i)
	{
		Std[i].Kor = i * 10;
		Std[i].Eng = i * 20;
		Std[i].Math = i * 30;
		Std[i].Number = i + 1;
	}
	

	/*
	{
		int number = 10;
		int* pointer = &number;
	}
	*/

	//========================================================

	/*
	{
		int i = 10;
		int Array[10] = { 1, 2, 3, 4, 5, 6 ,7, 8, 9 };
		int* pi = &i;

		pi = Array;
		printf("%d\n", *(pi + 1));
	}
	*/

	Output(Std, sizeof(Std) / sizeof(Std[0]));

	return 0;
}

// ** 매개변수로 배열이 전달 될 때에는 배열의 크기를 함께 전달해주어야 한다.
void Output(Student* _std, int _size)
{
	for (int i = 0; i < _size; ++i)
	{
		printf("학생 번호 : %d\n", (_std + i)->Number);
		printf("국어 점수 : %d\n", (_std + i)->Kor);
		printf("영어 점수 : %d\n", (_std + i)->Eng);
		printf("수학 점수 : %d\n", (_std + i)->Math);
		printf("\n");
	}
}
