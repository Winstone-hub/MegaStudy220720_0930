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
		// ** �迭�� ����� ���� ���
		//char Buffer[5] = "�ѱ�";
		char Buffer[] = "�ѱ�";

		// ** ���
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
		// ** �����͸� ����� ���� ���
		
		// ** "�ѱ�" = ���ڿ��� �ʱ�ȭ �Ǿ��ֱ� ������ char[5] ��ŭ�� ���̸� �����ִ�.
		// ** ���ڿ� ���� �迭�� �ν��ϱ� ������ ������ ���� �� ��ȯ�� �ʿ��ϴ�.
		char* Buffer = (char*)"�ѱ�";

		// ** ���
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
		// ** ������ ������ ���ڸ� ���� �Է¹����� ����.
		char* Buffer = (char*)"�ѱ�";

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


	printf("1. �ּ� : %d\n", Array); // ���� �ּ�
	printf("1. �� : %d\n", *Array); // ���� ��
	printf("2. %d\n", *(Array + 1) ); // 20
	printf("3. �ּ� : %d\n", pArr + 2);  // 30�� �ּ�
	printf("3. �� : %d\n", *(pArr + 2));  // 30�� ��
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

	// ** �迭�� ����� ���� �ȿ��� �迭�� ũ�⸦ �Ʒ��� ���� ������ ���� Ȯ���� �� �ִ�.
	int Size = sizeof(Array) / sizeof(Array[0]);
	printf("%d\n", Size);

	return 0;
}

/*
* �迭�� ������ ������ [int*]�� ���� ������� �Ʒ��� ���� ���ް���. (  [int*] == [ int _pArr[] ] )
void print_arr(int _pArr[], int _size)
{

	for (int i = 0; i < _size; ++i)
	{
		printf("%d\n", _pArr[i]);
		//printf("%d\n", *(pArr+i));
	}
}
*/

// ** �迭�� �Լ��� ���� �� ������ �ݵ�� �迭�� ũ�⸦ �Բ� �����ؾ� �Ѵ�.
void print_arr(int* _pArr, int _size)
{
	for (int i = 0; i < _size; ++i)
	{
		printf("%d\n", _pArr[i]);
		//printf("%d\n", *(pArr+i));
	}
}

