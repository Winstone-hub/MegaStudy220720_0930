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

	//Std[0].Name = (char*)"ȫ�浿";

	// ** �迭�� ũ�⸦ �� �� �ִ�.
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

// ** �Ű������� �迭�� ���� �� ������ �迭�� ũ�⸦ �Բ� �������־�� �Ѵ�.
void Output(Student* _std, int _size)
{
	for (int i = 0; i < _size; ++i)
	{
		printf("�л� ��ȣ : %d\n", (_std + i)->Number);
		printf("���� ���� : %d\n", (_std + i)->Kor);
		printf("���� ���� : %d\n", (_std + i)->Eng);
		printf("���� ���� : %d\n", (_std + i)->Math);
		printf("\n");
	}
}
