/*
* Chapter 06
*/

#include <stdio.h>

int main(void)
{
	// ** �ݺ��� (while)
	{
		// ** ������ ���ѷ��� �����϶�
		while (true)
		{
			// ** Ż���� �� �ִ� ��Ұ� �ʿ��ϴ�.
			if (true)
				break;
		}
		printf("\n");
	}

	// ** �ݺ��� (for)
	{
		// ** �ݺ� �� Ƚ���� ���س��� �ݺ� �ؾ��ϴ� ���.
		// for( �ʱ⹮ ; ���ǹ� ; ������ )
		// ** �ʱ⹮, ���ǹ�, ������ �� ������ ��Ұ� �ʿ��ϴ�.
		for (int i = 0; i < 10; ++i)
		{
			printf("for �ݺ��� %d\n", i + 1);
		}
		printf("\n");
	}





	{
		// ** ���� Ƚ�� ��ŭ �ݺ��ؾ��Ҷ�....

		int i = 0; // �ʱ⹮

		while (i < 10) // ���ǹ�
		{
			printf("while �ݺ��� %d\n", i + 1);
			++i; // ������
		}
		// ** �ʱ⹮, ���ǹ�, ������ �� ������ ��Ұ� �ʿ��ϴ�.
		printf("\n");
	}


	{
		// �ݺ��� for

		// ** for���� ���ѷ��� �����϶�
		for (;true;)
		{
			printf("for �ݺ���\n");

			// ** Ż���� �� �ִ� ��Ұ� �ʿ��ϴ�.
			if (true)
				break;
		}
		printf("\n");
	}


	do
	{
		printf("���ʿ� �ѹ��� �����.");
		break;
	} while (false);
	printf("\n");

	return 0;
}