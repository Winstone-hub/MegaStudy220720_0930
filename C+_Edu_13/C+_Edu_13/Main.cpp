#include <stdio.h>
#include <malloc.h>

struct Node
{
	int Value;
	Node* Next;
	Node* front;
};

Node* Begin;
Node* End;
int size = 0;

void erase(int _where);
void push_back(int _Value);
int pop_back();
void Output();
void clear();

int main(void)
{
	Node* List = (Node*)malloc(sizeof(Node));
	Begin = List;
	End = List;
	List->front = nullptr;
	List->Next = nullptr;
	List->Value = 1;
	size = 1;

	for (int i = 1; i < 50; ++i)
		push_back(i + 1);
	
	//clear();

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
	if (_where == 1)
	{
		Node* left = Begin;
		Begin = Begin->Next;

		free(left);
	}
	// ** 마지막 노드는 다음 노드가 없기 때문에 이전 노드와 연결 할 수 없다. (연결할 노드가 없다)
	// ** 마지막 노드는 end 가 된다.
	else if (_where == size)
	{
		pop_back();
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

void push_back(int _Value)
{
	End->Next = (Node*)malloc(sizeof(Node));

	End->Next->front = End;
	
	End = End->Next;
	
	End->Next = nullptr;
	End->Value = _Value;
	++size;
}

int pop_back()
{
	// ** 첫번째 위치의 노드를 받아온다.
	int Value = End->Value;

	// ** 마지막 노드를 주고
	Node* pList = End;

	// ** End 노드의 이전 노드를 End 노드로 셋팅.
	End = End->front;

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
	Node* NodeList = End;

	printf("<전체 데이터를 출력 합니다.>\n");

	while (NodeList != nullptr)
	{
		printf("%d\n", NodeList->Value);
		NodeList = NodeList->front;
	}
	printf("\n");

	/*
	Node* NodeList = Begin;

	printf("<전체 데이터를 출력 합니다.>\n");

	while (NodeList != nullptr)
	{
		printf("%d\n", NodeList->Value);
		NodeList = NodeList->Next;
	}
	printf("\n");
	*/
}

void clear()
{
	// ** 새롭게 생성하고 Begin을 준다.
	Node* NodeList = Begin;

	// ** NodeList 가 nullptr 이 아니라면 반복함.
	while (NodeList != nullptr)
	{
		// ** 이전 정보를 이미 NodeList에 넘겨 주었기 때문에 begin 은 다음 노드를 가르키도록 해준다.
		Begin = Begin->Next;

		// ** 이전 노드의 정보를 지운다.
		free(NodeList);
		NodeList = nullptr;

		// ** 다시 begin을 NodeList에 넘겨준다.
		NodeList = Begin;
	}
}