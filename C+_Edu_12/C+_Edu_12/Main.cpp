#include <stdio.h>
#include <malloc.h>

struct Node
{
	int Value;
	Node* Next;
};

Node* Begin;
Node* End;
int size = 0;

void erase(int _where);
void Testcase2(Node* _List, const int _Value);
void Testcase1(Node* _List, const int _Value);
void AddData(int _Value);
int Pop();
void Output();

int main(void)
{
	Node* List = (Node*)malloc(sizeof(Node));
	Begin = List;
	End = List;
	List->Value = 1;
	size = 1;

	for (int i = 1; i < 50; ++i)
		AddData(i + 1);

	erase(50);
	erase(1);
	erase(24);
	Output();

	return 0;
}

void erase(int _where)
{
	// ** ��尡 1�����϶����� ����Ʈ�� ��ü����.
	if (size == 1)
		// ** ����� �׽�Ʈ�� ���ؼ� ������.
		return;

	// ** ù��° ���� ���� ��尡 ���� ������ ���� ���� ���� �� �� ����. (������ ��尡 ����)
	// ** ù��° ���� begin �� �ȴ�.
	if(_where == 1)
	{
		Node* left = Begin;
		Begin = Begin->Next;

		free(left);
	}
	// ** ������ ���� ���� ��尡 ���� ������ ���� ���� ���� �� �� ����. (������ ��尡 ����)
	// ** ������ ���� end �� �ȴ�.
	else if (_where == size)
	{
		Pop();
	}
	// ** �߰��� �ִ� ������ _where �� ī������ �ؼ� 
	else
	{
		Node* left = Begin;
		Node* current = nullptr;
		Node* right = nullptr;

		for (int i = 1; i < _where - 1; ++i)
			left = left->Next;

		current = left->Next;
		right = current->Next;

		left->Next = right;
		free(current);
	}
}

// ** �ݺ����� ����� ������ �߰�.
void Testcase2(Node* _List, const int _Value)
{
	// ** ù��° ��ġ�� ��带 �޾ƿ´�.
	Node* pList = _List;

	// ** ������ ��带 ã�´�.
	while (pList->Next != nullptr)
		pList = pList->Next;

	// ** ������ ��带 ã�Ҵٸ� ������ ����� ������忡 ���ο� ��带 �߰�����.
	pList->Next = (Node*)malloc(sizeof(Node));

	// ** �������� �̵�
	pList = pList->Next;

	// ** ������ �ʱ�ȭ
	pList->Value = _Value;
	pList->Next = nullptr;

	// ** ������ ��� ����
	End = pList;

	// ** ������ ����.
	++size;
}

// ** ����Լ��� ȣ���ϴ� ���.
void Testcase1(Node* _List, const int _Value)
{
	// ** ����Ʈ�� �����������͸� ã�´�.
	if (_List->Next == nullptr)
	{
		// ** ������ �����Ͷ�� ���� ��忡 �߰��� ���ο� ��带 ����.
		Node* pList = (Node*)malloc(sizeof(Node));

		// ** �����͸� �ʱ�ȭ �Ѵ�.
		pList->Value = _Value;
		pList->Next = nullptr;

		// ** ���Ӱ� ������ ��带 ������ ��ġ�� �߰�.
		_List->Next = pList;

		// ** ������ ��� ����.
		End = _List->Next;

		// ** ������ ����
		++size;
	}
	else
		// ** ������ ��尡 �ƴ϶�� ������带 ã�� ���� ���ȣ���Ѵ�.
		// ** ����Լ��� ȣ���� ������ ���� ��带 �����ش�.
		Testcase1(_List->Next, _Value);
}

void AddData(int _Value)
{
	End->Next = (Node*)malloc(sizeof(Node));
	End = End->Next;

	End->Next = nullptr;
	End->Value = _Value;
	++size;
}

int Pop()
{
	// ** ù��° ��ġ�� ��带 �޾ƿ´�.
	int Value = End->Value;

	// ** ó�� ��带 ����
	Node* pList = Begin;

	// ** ����Ʈ�� ��ü �����ŭ �ݺ�
	for (int i = 0; i < size; ++i)
	{
		// ** �������� ���� ���� ���� ���� ��带 ã�´�.
		if (pList->Next->Value == Value)
		{
			// ** ������� ������ ����� ���� ����̹Ƿ�, ������ ���� �ʱ�ȭ.
			End = pList;

			// ** ���� ��带 ������ ���� ����.
			pList = pList->Next;

			// ** �ݺ����� Ż���Ѵ�.
			break;
		}

		// ** if������ ������ ��带 ã�� ���ߴٸ� �������� �̵�.
		pList = pList->Next;
	}

	// ** �ݺ����� ����Ǿ��ٸ� ���� ���� ������ ��� �̹Ƿ� �������ش�.
	free(pList);

	// ** �׸��� ������ ����� ��ġ�� nullptr�� �ʱ�ȭ �Ѵ�.
	End->Next = nullptr;

	// ** ���Ұ� �����Ǿ����Ƿ�, ����� �ٿ��ش�.
	--size;

	// ** ������ ������ ��� ���� ��ȯ�ϰ� �Լ��� �����Ѵ�.
	return Value;
}

void Output()
{
	Node* NodeList = Begin;

	printf("<��ü �����͸� ��� �մϴ�.>\n");
	while (NodeList != nullptr)
	{
		printf("%d\n", NodeList->Value);
		NodeList = NodeList->Next;
	}
	printf("\n");
}