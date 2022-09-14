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
	// ** 노드가 1개뿐일때에는 리스트를 전체삭제.
	if (size == 1)
		// ** 현재는 테스트를 위해서 리턴함.
		return;

	// ** 첫번째 노드는 이전 노드가 없기 때문에 다음 노드로 연결 할 수 없다. (연결할 노드가 없다)
	// ** 첫번째 노드는 begin 이 된다.
	if(_where == 1)
	{
		Node* left = Begin;
		Begin = Begin->Next;

		free(left);
	}
	// ** 마지막 노드는 다음 노드가 없기 때문에 이전 노드와 연결 할 수 없다. (연결할 노드가 없다)
	// ** 마지막 노드는 end 가 된다.
	else if (_where == size)
	{
		Pop();
	}
	// ** 중간에 있는 노드들은 _where 로 카운팅을 해서 
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