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

void Output(Student* _std);

int main(void)
{
	Student Std;

	Std.Name = (char*)"홍길동";
	Std.Kor = 100;
	Std.Eng = 90;
	Std.Math = 90;
	Std.Number = 1;

	/*
	{
		int number = 10;
		int* pointer = &number;
	}
	*/

	Output(&Std);

	return 0;
}

void Output(Student* _std)
{
	printf("학생 번호 : %d\n", _std->Number);
	printf("학생 이름 : %s\n", _std->Name);
	printf("국어 점수 : %d\n", _std->Kor);
	printf("영어 점수 : %d\n", _std->Eng);
	printf("수학 점수 : %d\n", _std->Math);
}
