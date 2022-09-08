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

// ** 반복문을 사용한 데이터 추가.
void Testcase2(Node* _List, const int _Value)
{
	// ** 첫번째 위치의 노드를 받아온다.
	Node* pList = _List;

	// ** 마지막 노드를 찾는다.
	while (pList->Next != nullptr)
		pList = pList->Next;

	// ** 마지막 노드를 찾았다면 마지막 노드의 다음노드에 새로운 노드를 추가생성.
	pList->Next = (Node*)malloc(sizeof(Node));

	// ** 다음노드로 이동
	pList = pList->Next;

	// ** 데이터 초기화
	pList->Value = _Value;
	pList->Next = nullptr;
}

// ** 재귀함수를 호출하는 방식.
void Testcase1(Node* _List, const int _Value)
{
	// ** 리스트의 마지막데이터를 찾는다.
	if (_List->Next == nullptr)
	{
		// ** 마지막 데이터라면 다음 노드에 추가할 새로운 노드를 생성.
		Node* pList = (Node*)malloc(sizeof(Node));

		// ** 데이터를 초기화 한다.
		pList->Value = _Value;
		pList->Next = nullptr;

		// ** 새롭게 생성된 노드를 마지막 위치에 추가.
		_List->Next = pList;
	}
	else
		// ** 마지막 노드가 아니라면 다음노드를 찾기 위해 재귀호출한다.
		// ** 재귀함수를 호출할 때에는 다음 노드를 보내준다.
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