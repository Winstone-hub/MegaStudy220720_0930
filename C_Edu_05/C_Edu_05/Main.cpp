/*
* Chapter 05
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	// ** 1. ������ �տ��� ���� ���Ŵ�.
	// ** 2. ���࿡ ������ �տ� ���� ���ٸ�...
	// **  - �������� ���� �޾ƿ´�.


	// ** ��ǻ�� ��ũ��Ʈ **
	// ** 1. ������տ� ����.
	// ** 2. ���� Ž���Ѵ�.
	// ** 3. ���� ���� ���ٸ�... if(����)
	//		- �������� ���� �޾ƿ´�. { ������ �´ٸ� �ൿ�ϰԵ� ���๮ }
	// ** 4. ���� �տ� ���.
	// ** 5. �ſ� ���� ��� ���Ŵ�.



	{
		char* Name;
		int Number;

		printf("�Է� : ");
		scanf("%d", &Number);

		if (Number == 1)
		{
			Name = (char*)"ȫ�浿";
		}
		else if (Number == 2)
		{
			Name = (char*)"�Ӳ���";
		}
		else
		{
			Name = (char*)"�̸���";
		}

		printf("��� �� : %s\n", Name);
		printf("\n");
	}
	











	return 0;
}