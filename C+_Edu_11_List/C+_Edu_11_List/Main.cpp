#include <stdio.h>
#include <malloc.h>

struct Node
{
	int Value;
	Node* Next;
};

Node* Begin;
Node* End;

void AddData(int _Value);
void Output();
void Testcase1(Node* _List, const int _Value);
void Testcase2(Node* _List, const int _Value);

int main(void)
{
	Node* List = (Node*)malloc(sizeof(Node));
	Begin = List;
	End = List;
	List->Value = 10;

	AddData(20);
	AddData(30);
	AddData(40);
	AddData(50);
	Testcase1(List, 60);
	Testcase2(List, 70);

	Output();

	return 0;
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
}

void Output()
{
	Node* NodeList = Begin;

	while (NodeList != nullptr)
	{
		printf("%d\n", NodeList->Value);
		NodeList = NodeList->Next;
	}
}