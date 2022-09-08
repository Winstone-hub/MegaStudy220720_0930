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
	List->Value = 10;
	size = 1;


	AddData(20);
	AddData(30);
	AddData(40);
	AddData(50);
	Testcase1(List, 60);
	Testcase2(List, 70);

	Output();

	printf("\n<마지막 데이터를 삭제 합니다.>\n");
	printf("%d\n", Pop());

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

	// ** 마지막 노드 셋팅
	End = pList;

	// ** 사이즈 증가.
	++size;
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

		// ** 마지막 노드 셋팅.
		End = _List->Next;

		// ** 사이즈 증가
		++size;
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
	++size;
}

int Pop()
{
	// ** 첫번째 위치의 노드를 받아온다.
	int Value = End->Value;

	// ** 처음 노드를 지정
	Node* pList = Begin;

	// ** 리스트의 전체 사이즈만큼 반복
	for (int i = 0; i < size; ++i)
	{
		// ** 현재노드의 다음 노드와 같은 값의 노드를 찾는다.
		if (pList->Next->Value == Value)
		{
			// ** 현재노드는 마지막 노드의 이전 노드이므로, 마지막 노드로 초기화.
			End = pList;

			// ** 현재 노드를 마지막 노드로 셋팅.
			pList = pList->Next;

			// ** 반복문을 탈출한다.
			break;
		}

		// ** if문에서 마지막 노드를 찾지 못했다면 다음노드로 이동.
		pList = pList->Next;
	}
	
	// ** 반복문이 종료되었다면 현재 노드는 마지막 노드 이므로 삭제해준다.
	free(pList);

	// ** 그리고 삭제된 노드의 위치를 nullptr로 초기화 한다.
	End->Next = nullptr;

	// ** 원소가 삭제되었으므로, 사이즈를 줄여준다.
	--size;

	// ** 최초의 마지막 노드 값을 반환하고 함수를 종료한다.
	return Value;
}

void Output()
{
	Node* NodeList = Begin;

	printf("<전체 데이터를 출력 합니다.>\n");
	while (NodeList != nullptr)
	{
		printf("%d\n", NodeList->Value);
		NodeList = NodeList->Next;
	}
	printf("\n");
}