// ** �⺻ �����
#include <stdio.h>

// ** system �Լ�
#include <stdlib.h>

// ** input �� ������â�� ���� �Ҷ� ���� ���̺귯��
#include <Windows.h>

struct Time
{
	char Hour;
	char Minute;
	char Second;
};

int main(void)
{
	// ** �ð� �Լ�.
	//DWORD Time = GetTickCount(); ��ǻ�Ͱ� ���� �������� 49.7��

	// ** GetTickCount64() = 1/1000 ��  <=  0.001 �� ����
	ULONGLONG lTime = GetTickCount64();

	Time tTime;

	tTime.Hour = 0;
	tTime.Minute = 0;
	tTime.Second = 0;
	
	while (true)
	{
		// if Ư�� �̺�Ʈ�� �߻� �Ѵٸ�.....
		// else �ƴ϶��
		if (lTime + 999 < GetTickCount64())
		{
			// ** ����
			lTime = GetTickCount64();

			// ** ȭ���� �����ش�.
			system("cls");

			// ** �ð��� ���
			printf("%02d:%02d:%02d\n", 
				tTime.Hour, 
				tTime.Minute, 
				++tTime.Second);

			// ** ��ħ�� 60�� �Ǹ� ��ħ�� �ٽ� 0���� ����� ��ħ 1���� 
			if (tTime.Second >= 61)
			{
				tTime.Second = 0;
				++tTime.Minute;
			}

			// ** ��ħ�� 60�� �Ǹ� ��ħ�� �ٽ� 0���� ����� �ð� 1���� 
			if (tTime.Minute >= 61)
			{
				tTime.Minute = 0;
				++tTime.Hour;
			}

			// ** ��ħ�� 24�ð� �Ǹ� �ð��� 0���� ����. 
			if (tTime.Hour >= 24)
				tTime.Hour = 0;
		}
	}

	return 0;
}