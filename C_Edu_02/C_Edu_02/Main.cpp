/*
* Chapter 02
*/
#include <stdio.h>
#include <stdlib.h>



// **�Լ�
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

	// ** ���ڿ� ���ڿ�
	// 'A' = ����
	// 'AB' = X
	// 'H', 'e', 'l', 'l', 'o'
	
	// "A" = ���ڿ�
	// "AB" = O
	// "Hello"
	printf("\n");


	// ** ���Ĺ���
	// %d = ���� ǥ��
	// %f = �Ǽ� ǥ��
	// %c = ���� ǥ��
	// %s = ���ڿ� ǥ��
	// %% = % ǥ��

	printf("���� ��� : %d\n", 10);
	printf("�Ǽ� ��� : %f\n", 3.141592f);
	printf("���� ��� : %c\n", 'A');
	printf("���� ��� : %c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o');
	printf("���ڿ� ��� : %s\n", "A");
	printf("���ڿ� ��� : %s\n", "Hello");
	printf("%d%% �Դϴ�.\n",100);




	printf("\n");
	// \n = �ٹٲ� ǥ��
	// \t = tab ǥ��
	// \b = backspace(����)
	// \\ = \  ǥ��
	
	printf("goot\bd\tchance\n");
	printf("10,000\\\n");


	printf("%d�� %d�� ���� %d �Դϴ�.\n", 14254, 23421, 14254 + 23421);


	printf("\n");
	// ** ���� ǥ��

	printf("10������ 10 : %d\n", 10);
	printf("8������ 10 : %d\n", 010);
	printf("16������ 10 : %d\n", 0x10);


	printf("\n");
	// ** �ƽ�Ű �ڵ�ǥ
	printf("65 ���� ��� : %c\n", 65);
	printf("A ���� ��� : %d\n", 'A');
	
	





	return 0;
}