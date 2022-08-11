/*
* Chapter 09
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>


int main(void)
{
	{
		// ** 1�ܰ�
		
		// ** �Ϲ� ����
		int Number = 10;
		// ** �Ϲ� ������ �����͸� ���´�

		// ** ������ ����
		int* pNumber;
		// ** ������ ������ [*] �� �����ش�.
		// ** ������ ������ �Ϲݺ����� �ּҸ� ���´�.
	}
	
	{
		// ** 2�ܰ�
		int Number = 10;

		// ** �ּҴ� ������ ���� ǥ���� �� �ִ�.
		printf_s("�ּ� : %p\n", &Number);
		printf_s("������ : %d\n", Number);
		printf_s("\n");
	}

	{
		// ** 3�ܰ�
		int Number = 10;

		// ** ������ ������ �Ϲݺ����� �ּҸ� �޴´�.
		int* pNumber = &Number;

		// ** ������ ������ �����͸� ����� ������ �׸� �տ� [*] �� ���δ�.
		printf_s("Pointer : %d\n", *pNumber);
		printf_s("\n");
	}


	{
		// ** 4�ܰ�
		int Number = 10;

		// ** ������ ������ �Ϲݺ����� �ּҸ� �޴´�.
		int* pNumber = &Number;

		// ** ������ ������ �����͸� ����� ������ �׸� �տ� [*] �� ���δ�.
		printf_s("Number �� : %d\n", Number);
		printf_s("Pointer �� ����Ű�� �� : %d\n", *pNumber);
		printf_s("Number �ּ� : %p\n", &Number);
		printf_s("Pointer �� ����Ű�� �� : %p\n", pNumber);
		printf_s("Pointer �� �ּ� : %p\n", &pNumber);

		printf_s("\n");
	}

	{
		// ** ������ ������ �Ϲݺ����� �����͸� �����Ѵ�.
		// ** ���� 
		int Number = 10;

		// ** ������ ������ �Ϲݺ����� �ּҸ� �޴´�.
		int* pNumber = &Number;

		// ** ������ ������ �����͸� ����� ������ �׸� �տ� [*] �� ���δ�.
		printf_s("Number �� : %d\n", Number);
		printf_s("Pointer �� ����Ű�� �� : %d\n", *pNumber);
		printf_s("\n");

		// ** �Ϲ� ������ ���� ����
		Number = 100;

		printf_s("Number �� : %d\n", Number);
		printf_s("Pointer �� ����Ű�� �� : %d\n", *pNumber);
		printf_s("\n");

		// ** ������ ������ ���� ����
		*pNumber = 1000;

		printf_s("Number �� : %d\n", Number);
		printf_s("Pointer �� ����Ű�� �� : %d\n", *pNumber);
		printf_s("\n");
	}


	// ** swap
	{
		int a = 10;
		int b = 20;

		printf("a : %d\n", a);
		printf("b : %d\n\n", b);

		if (true)
		{
			int temp = a;
			a = b;
			b = temp;
		}

		printf("a : %d\n", a);
		printf("b : %d\n\n", b);
	}
	

	{
		int a = 10;
		int b = 20;

		a ^= b;
		b ^= a;
		a ^= b;
		
		printf("a : %d\n", a);
		printf("b : %d\n\n", b);
	}





	{
		// ** �������� ũ��� ����ȯ�濡 ���� �� ũ�Ⱑ �޶�����.
		int Number = 10;
		long long lNum = 10;
		long long* Pointer = &lNum;

		// ** �������� ũ��
		// x86 = 4byte
		// x64 = 8byte

		printf("int : %d\n", sizeof(Number));
		printf("long long : %d\n", sizeof(lNum));
		printf("Pointer : %d\n\n", sizeof(Pointer));
	}

	return 0;
}