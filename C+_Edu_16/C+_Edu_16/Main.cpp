/*
 * Vector
 */

#include <stdio.h>
#include <malloc.h>

int* Fornt;
int* Back;

int size = 0;
int capacity = 0;

void push_back(int _value);
void erase(int _Where);
void Output();

int main(void)
{
	Fornt = (int*)malloc(sizeof(int));

	push_back(10);
	push_back(20);
	push_back(30);
	push_back(40);
	push_back(50);
	push_back(60);
	push_back(70);

	printf("%d\n", *Fornt);
	printf("%d\n", *Back);
	printf("%d\n", size);

	Output();
	return 0;
}

void push_back(int _value)
{
	// ** capacity(���뷮) ��(��) size(��������� ����) �� ���� ���� ���ٸ�
	// ** ���Ҹ� ���̻� �߰� �� �� ���� �����̹Ƿ�..
	if (capacity == size)
	{
		// ** ���뷮�� �÷��ش�.
		int result = (capacity >> 1);
		capacity += (result < 1) ? 1 : result;





		// ** ���뷮�� �þ�� �Ǹ� ���� �޸� ���� ���뷮�� �÷��� �ϱ� ������
		// ** �ø��� �������� �����͸� ���� �� �� �����Ƿ� �̸� �����͸� �Ȱ� �ξ�� �Ѵ�.
		// ** �׷��� ���� �ʿ��� �ӽ��� ������ ����.
		
		//===============[���� ����]==================
		//int* Temp = (int*)malloc(sizeof(int) * (size + 1));
		
		//�������������������������

		// ** �þ �������� ũ��� �ӽ��� ������ ���Ӱ� ����.
		int* Temp = (int*)malloc(sizeof(int) * capacity);
		//============================================





		// ** �ӽ��� ������ ���� �����͸� ���� �Ѵ�.
		// ** �̶�! �ּ��� ���簡 �ƴ϶� ���� ���簡 �̷�� ���� �Ѵ�.
		for (int i = 0; i < size; ++i)
			Temp[i] = Fornt[i];



		// ** ���� �Ҵ�� �޸𸮰����� �����Ѵ�.,
		free(Fornt);




		// ** �þ ���뷮 ��ŭ�� ũ��� ���Ӱ� ������ �Ҵ� �Ѵ�.
		//Fornt = (int*)malloc(sizeof(int) * capacity);





		// ** ���Ӱ� �Ҵ�� ������ �����ص� �����͸� �ٽ� ���´�.
		/*
		for (int i = 0; i < size; ++i)
			Fornt[i] = Temp[i];
		*/





		//===============[���� ����]==================
		// ** �ӽ��� ������ �Ҵ� �����Ѵ�.
		//free(Temp);
		
		//�������������������������

		// ** �ӽ� ������ �ּҸ� Fornt�� �޾ƿ´�.
		// ** Temp �� ������ �ش� ������ ���������� �Ҹ�ȴ�.
		// ** ������ �Ҵ�� �޸��ּҴ� Fornt�� ���� �����Ƿ� ��� ����.
		Fornt = Temp;
		//============================================
		





		// ** ���������� �ּҰ� �ٲ�����Ƿ� ���Ӱ� ���� ���ش�.
		Back = &Fornt[size];
	}
	
	// ** �� �б��� ���� ��/���� ��� ���� ���� ��ġ������ �׻� ���뷮�� ���´�.
	// ** �׻� (capacity > size) �� ���� �����̹Ƿ� ���� �߰��� �����ϴ�.
	Fornt[size] = _value;

	// ** ���Ұ� �߰� �Ǿ����Ƿ� size�� ������Ŵ.
	++size;
}

void erase(int _Where)
{
	--size;

	for (int i = _Where - 1; i < size; ++i)
		Fornt[i] = Fornt[i + 1];
}

void Output()
{
	printf("[��ü ���]\n");

	for (int i = 0; i < size; ++i)
		printf("%d\n", Fornt[i]);
}
