/*
* Chapter 08
*/

#include <stdio.h>



int main(void)
{
	// ** ������ ���� �����Ͽ� ���.
	int Number1 = 1;
	int Number2 = 2;
	int Number3 = 3;
	int Number4 = 4;
	int Number5 = 5;

	printf("Number1 : %d\n", Number1);
	printf("Number2 : %d\n", Number2);
	printf("Number3 : %d\n", Number3);
	printf("Number4 : %d\n", Number4);
	printf("Number5 : %d\n", Number5);
	printf("\n");

	// ** ���� : ������ �������� ���� �ۼ��Ͽ��� �Ѵ�. ���ŷӴ�.

	// ====================================================

	// ** �ϳ��� �迭�� �����Ͽ� ���
	int Number[5] = {1, 2, 3, 4, 5};

	printf("Number[0] : %d\n", Number[0]);
	printf("Number[1] : %d\n", Number[1]);
	printf("Number[2] : %d\n", Number[2]);
	printf("Number[3] : %d\n", Number[3]);
	printf("Number[4] : %d\n", Number[4]);
	printf("\n");

	// ** ����1 : �迭�� ���������ν�, �ʱ�ȭ ������ ������ �پ���.

	// ==��==��==��==��==��==��==��==��==��==
	//				  ��  ��
	// ==��==��==��==��==��==��==��==��==��==

	// ** �迭�� ����Ͽ� ����� ������ �Ʒ��� ���� �ݺ����� ���� �迭�� Ȱ���� �� �ִ�.
	for (int i = 0; i < 5; ++i)
		printf("Number[%d] : %d\n", i, Number[i]);
	printf("\n");

	// ** ����2 : ���� ���� ��������ν�, ����� ������ ������ �پ���.


	// ====================================================

	{
		// ** ����� �Ұ����� ��.
		int Number[5];// = 10;
		Number[5] = 10;
	}
	

	return 0;
}