/*
* Chapter 10
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>


int main(void)
{
	// ** �迭�� �������� ����
	{
		// ** �迭 ���� �� �ʱ�ȭ
		int Array[8] = { 0 };

		// ** �ʱ�ȭ
		for (int i = 0; i < 8; ++i)
			Array[i] = i + 1;

		printf("[�Ϲ� ���]\n");
		for (int i = 0; i < 8; ++i)
			printf("%d\n", Array[i]);
		printf("\n");


		printf("[�����͸� ����� ���]\n");

		// ** �迭�� �ε���(���ȣ)�� ���� ���·� �ּҹ�ȯ������ ���� �ּҸ� ���� �� �� �ִ�.
		int* iter = Array;

		for (int i = 0; i < 8; ++i)
			printf("%d\n", (*(iter + i)));
			
		printf("\n");
	}

	{
		int Array[8] = { 0 };

		// ** ����
		printf("[�����͸� ����� ������� �߻��Ҽ� �ִ� ����]\n");
		int* iter = Array;

		for (int i = 0; i < 100; ++i)
			printf("%d\n", (*(iter + i)));

		printf("\n");
	}



	// ** �ζ� ��ȣ�� �����ϴ� ���α׷��� �ۼ��� ���ô�.
	/*
	* ����: 1�� Ȯ�� : 1/8155060
	*/
	/*
	int Number[5][6] = {
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0}
	};
	*/
	int Number[5][6];

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			srand((i+1) * (j + 1) * rand());
			Number[i][j] = rand() % 45 + 1;
		}
	}

	// ** ���� ����
	/*
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			for (int k = (j + 1); k < 6; ++k)
			{
				if (Number[i][j] > Number[i][k])
				{
					int Temp = Number[i][j];
					Number[i][j] = Number[i][k];
					Number[i][k] = Temp;
				}
			}
		}
	}
	*/

	// ** ���� ����
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			int Select = j;
			
			for (int k = (j + 1); k < 6; ++k)
			{
				if (Number[i][Select] > Number[i][k])
					Select = k;
			}

			int Temp = Number[i][j];
			Number[i][j] = Number[i][Select];
			Number[i][Select] = Temp;
		}
	}

	for (int i = 0; i < 5; ++i)
	{
		printf("%02d. ", i + 1);
		for (int j = 0; j < 6; ++j)
			printf("%02d ", Number[i][j]);
		printf("\n");
	}
	printf("\n");
		


	// ** ����1
	{
		/*
		{
			char Array[80];

			printf("�̸� �Է� : ");
			scanf("%s", Array);
			printf("��� : %s\n\n", Array);
		}
		*/

		{
			char Array[80];

			printf("�̸� �Է� : ");
			//scanf_s("%s", &Array[4], sizeof(Array) - 4);
			scanf("%s", &Array[4]);

			Array[0] = ' ';
			Array[1] = ' ';
			Array[2] = ' ';
			Array[3] = ' ';

			//printf_s("�̸� �Է� : %s", Array);
			printf_s("�̸� �Է� : %c%c", Array[4], Array[5]);
		}
		
		/*
		{
			char* Array = (char*)"�ܡܡܡܡܡܡܡܡܡ�";
			//char Array[] = "123456789012345678901234567890";

			//printf("%s", Array);
			
			//for (int i = 0; i < strlen(Array) + 1 ; i += 2)
				//printf("%c%c", Array[i], Array[i+1]);
			

			for (int i = 4; i < strlen(Array) - 5; i += 2)
				printf("%c%c", Array[i], Array[i+1]);
		}
		*/
	}




	return 0;
}
