/*
* Chapter 03
*/
#include <stdio.h>

// 1 bit  = 0 or 1 = 2��
// 2 bit  = 00, 01, 10, 11 = 4��
// 3 bit  = 000, 001, 010, 011, 100, 101, 110, 111 = 8 ��

/* 4 bit = 16��
* 0000, 0001, 0010, 0011, 0100, 0101, 0110, 0111
* 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111
*/ 

// 5 bit = 32��
// 6 bit = 64��
// 7 bit = 128��
// 8 bit = 256�� = 1byte


// 10000000 = -128
//     .
//     .
//     .
//     .
// 11111110 = -2
// 11111111 = -1
// 00000000 =  0
// 00000001 =  1
// 00000010 =  2
// 00000011 =  3
// 00000100 =  4
//     .
//     .
//     .
//     .
// 01111111 = 127

int main(void)
{
	// ** signed
	// ** sizeof() = �������� ũ�⸦ ������ ��ȯ.
	printf("char : %d\n", sizeof(char));
	printf("short : %d\n", sizeof(short));
	printf("int : %d\n", sizeof(int));
	printf("long : %d\n", sizeof(long));
	printf("__int64 : %d\n", sizeof(__int64));
	printf("\n");

	// ** unsigned
	// ** sizeof() = �������� ũ�⸦ ������ ��ȯ.
	printf("unsigned char : %d\n", sizeof(unsigned char));
	printf("unsigned short : %d\n", sizeof(unsigned short));
	printf("unsigned int : %d\n", sizeof(unsigned int));
	printf("unsigned long : %d\n", sizeof(unsigned long));
	printf("unsigned __int64 : %d\n", sizeof(unsigned __int64));
	printf("\n");






	// ** ���� ����
	char c;   // (�ڷ��� : char) (�����̸� : c)

	// ** ���� �ʱ�ȭ.
	c = 127; // (�����̸� : c) (���Կ����� : =) (�� : 127)

	// ** ���� ���� �� �ʱ�ȭ.
	short s = 32767; // (�ڷ��� : short) (�����̸� : s) (���Կ����� : =) (�� : 32767)
	int i = 2147483647;
	long n = 2147483647;

	// ** �ʱ�ȭ �� ������ ���� ���
	printf("char : %d\n", c);
	printf("short : %d\n", s);
	printf("int : %d\n", i);
	printf("long : %d\n", n);
	printf("\n");

	// ** ������ Ÿ���� �ִ� ǥ���������� +1 �� �� ���ԵȰ��
	c = c + 1;
	s = s + 1;
	i = i + 1;
	n = n + 1;

	// ** ��� ��µǴ��� Ȯ��.
	printf("char : %d\n", c);
	printf("short : %d\n", s);
	printf("int : %d\n", i);
	printf("long : %d\n", n);
	printf("\n");



	/* 
	unsigned ������ ������ Ÿ������ ������ 
		�� ������ �Ȱ��� ������ �ʱ�ȭ 
	*/ 
	unsigned char uc = 127;
	unsigned short us = 32767;
	unsigned int ui = 2147483647;
	unsigned long un = 2147483647;

	// ** ���� 1�� ������.
	uc = uc + 1;
	us = us + 1;
	ui = ui + 1;
	un = un + 1;

	// ** ��� ��µǴ��� Ȯ��.
	printf("unsigned char : %d\n", uc);
	printf("unsigned short : %d\n", us);
	printf("unsigned int : %u\n", ui);
	printf("unsigned long : %u\n", un);
	printf("\n");


	// ** �Ǽ��� ������ Ÿ�� ũ�� Ȯ��.
	printf("float : %d\n", sizeof(float));
	printf("double : %d\n", sizeof(double));
	printf("long double : %d\n", sizeof(long double));
	printf("\n");

	return 0;
}