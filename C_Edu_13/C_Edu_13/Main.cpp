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

	Std.Name = (char*)"ȫ�浿";
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
	printf("�л� ��ȣ : %d\n", _std->Number);
	printf("�л� �̸� : %s\n", _std->Name);
	printf("���� ���� : %d\n", _std->Kor);
	printf("���� ���� : %d\n", _std->Eng);
	printf("���� ���� : %d\n", _std->Math);
}
