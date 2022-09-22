/*
 * Vector
 */

#include <stdio.h>
#include <malloc.h>

int* Front;
int* Back;

int size = 0;
int capacity = 0;


// ** �߰� ����.
void push_back(int _value);
void insert(int _Where, int _value);
void erase(int _Where);
void Output();

int main(void)
{
	Front = (int*)malloc(sizeof(int));

	push_back(10);
	push_back(20);
	push_back(30);
	push_back(40);
	push_back(50);
	push_back(60);
	push_back(70);

	insert(3, 25);
	insert(3, 23);
	push_back(100);
	//insert(3, 21);

	printf("%d\n", *Front);
	printf("%d\n", *Back);
	
	
	printf("size : %d\n", size);
	printf("capacity : %d\n", capacity);

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
			Temp[i] = Front[i];




		// ** ���� �Ҵ�� �޸𸮰����� �����Ѵ�.,
		//free(Front);



		// ** �þ ���뷮 ��ŭ�� ũ��� ���Ӱ� ������ �Ҵ� �Ѵ�.
		//Front = (int*)malloc(sizeof(int) * capacity);





		// ** ���Ӱ� �Ҵ�� ������ �����ص� �����͸� �ٽ� ���´�.
		/*
		for (int i = 0; i < size; ++i)
			Front[i] = Temp[i];
		*/





		//===============[���� ����]==================
		// ** �ӽ��� ������ �Ҵ� �����Ѵ�.
		//free(Temp);
		
		//�������������������������

		// ** �ӽ� ������ �ּҸ� Fornt�� �޾ƿ´�.
		// ** Temp �� ������ �ش� ������ ���������� �Ҹ�ȴ�.
		// ** ������ �Ҵ�� �޸��ּҴ� Front�� ���� �����Ƿ� ��� ����.
		Front = Temp;
		//============================================
	}
	
	// ** �� �б��� ���� ��/���� ��� ���� ���� ��ġ������ �׻� ���뷮�� ���´�.
	// ** �׻� (capacity > size) �� ���� �����̹Ƿ� ���� �߰��� �����ϴ�.
	Front[size] = _value;

	// ** ������ ���� �ּҰ� �ٲ�����Ƿ� ���Ӱ� ���� ���ش�.
	Back = &Front[size];

	// ** ���Ұ� �߰� �Ǿ����Ƿ� size�� ������Ŵ.
	++size;
}

void insert(int _Where, int _value)
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
			Temp[i] = Front[i];




		// ** ���� �Ҵ�� �޸𸮰����� �����Ѵ�.,
		//free(Front);




		// ** �þ ���뷮 ��ŭ�� ũ��� ���Ӱ� ������ �Ҵ� �Ѵ�.
		//Front = (int*)malloc(sizeof(int) * capacity);





		// ** ���Ӱ� �Ҵ�� ������ �����ص� �����͸� �ٽ� ���´�.
		/*
		for (int i = 0; i < size; ++i)
			Front[i] = Temp[i];
		*/





		//===============[���� ����]==================
		// ** �ӽ��� ������ �Ҵ� �����Ѵ�.
		//free(Temp);

		//�������������������������

		// ** �ӽ� ������ �ּҸ� Fornt�� �޾ƿ´�.
		// ** Temp �� ������ �ش� ������ ���������� �Ҹ�ȴ�.
		// ** ������ �Ҵ�� �޸��ּҴ� Front�� ���� �����Ƿ� ��� ����.
		Front = Temp;
		//============================================
	}

	--_Where;
	
	for (int i = size; i >= _Where; --i)
		Front[i + 1] = Front[i];

	// ** �� �б��� ���� ��/���� ��� ���� ���� ��ġ������ �׻� ���뷮�� ���´�.
	// ** �׻� (capacity > size) �� ���� �����̹Ƿ� ���� �߰��� �����ϴ�.
	Front[_Where] = _value;

	// ** ���������� �ּҰ� �ٲ�����Ƿ� ���Ӱ� ���� ���ش�.
	Back = &Front[size];

	// ** ���Ұ� �߰� �Ǿ����Ƿ� size�� ������Ŵ.
	++size;
}

void erase(int _Where)
{
	--size;

	for (int i = _Where - 1; i < size; ++i)
		Front[i] = Front[i + 1];
}

void Output()
{
	printf("[��ü ���]\n");

	for (int i = 0; i < size; ++i)
		printf("%d\n", Front[i]);
}
