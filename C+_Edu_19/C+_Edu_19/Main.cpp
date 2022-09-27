#include <stdio.h>
#include <Windows.h>

struct Vector2
{
	int x, y;

	Vector2() : x(0), y(0) { }

	Vector2(int _x, int _y) : x(_x), y(_y) { }
};

struct Object
{
	Vector2 Position;
	Vector2 Scale;
	char* Texture;
};

struct Node
{
	Object* pObj;
	int Index;
	Node* Front;
	Node* Back;

	// ** 충돌 이벤트를 처리하기 위한 임시변수.
	// ** Count 가 계속 증가하고 Limit 변수와 값이 같아지면 충돌이라고 가정.
	int Count;
	int Limit;
};

// ** 첫번째 원소를 가르키는 노드
Node* Begin;

// ** 마지막 원소를 가르키는 노드
Node* End;


void SetCursorPosition(int _x, int _y);
Node* CreateNode();
Object* CreateObject(int _x, int _y, char* _Texture);
void BullseProgress(int _x, int _y, int _Index, char* _Texture);
void Output();

int main(void)
{
	// ** Begin과 BulletList가 같은 시작점을 가르킨다.
	Node* BulletList = Begin = CreateNode();

	// ** 초기화 시점에 노드가 존재하지 않으므로 가르킬 노드가 없음.
	BulletList->Front = nullptr;
	BulletList->Back = nullptr;

	// ** Begin Object를 생성.
	BulletList->pObj = CreateObject(0, 0, (char*)"Begin");

	// ** 인덱스 초기화.
	int Index = 0;

	// ** 현재 값은 시작노드로 지정된 원소이기 때문에 값을 0으로 본다.
	BulletList->Index = Index;

	// ** 노드가 존재하지 않기 때문에 마지막을 가르키는 원소도 시작점과 같음.
	End = Begin;

	Object* Enemy = CreateObject(0, 0, (char*)"Enemy");

	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();
			system("cls");

			if (GetAsyncKeyState(VK_SPACE))
			{
				// 총알 생성.
				//BulletList->pObj = CreateObject(Index++, 0, (char*)"Bullet");

				BullseProgress((Index / 39) * 20, Index % 39 - 1, ++Index, (char*)"Bullet");
			}



			Output();
		}
	}

	return 0;
}

// ** 커서의 위치를 이동시킨다.
void SetCursorPosition(int _x, int _y)
{
	// ** 좌표를 설정.
	COORD pos = { (SHORT)_x, (SHORT)_y };

	// ** 설정한 좌표로 이동시키는 함수.
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), pos);
	// ** GetStdHandle(STD_OUTPUT_HANDLE) = 현재 콘솔창의 핸들.
	// ** HANDLE : 윈도우 창의 기본 설정값을 셋팅할 수 있음.
}

Node* CreateNode()
{
	Node* pNode = (Node*)malloc(sizeof(Node));

	pNode->pObj = nullptr;
	pNode->Front = nullptr;
	pNode->Back = nullptr;

	return pNode;
}

Object* CreateObject(int _x, int _y, char* _Texture)
{
	Object* pObj = (Object*)malloc(sizeof(Object));

	pObj->Position = Vector2(_x, _y);

	pObj->Texture = _Texture;
	pObj->Scale = Vector2(strlen(_Texture), 1);

	return pObj;
}

void BullseProgress(int _x, int _y, int _Index, char* _Texture)
{
	// ** 임시의 node에 End가 가르키는 원소를 넘겨준다.
	Node* node = End;

	// ** 마지막 노드가 가르키는 다음 위치에 새로운 노드를 생성.
	node->Back = CreateNode();

	// ** 그리고 현재 노드는 새롭게 생성한 노드의 위치로 이동시킴.
	node = node->Back;

	// ** 새롭게 생성된 노드의 Index를 초기화.
	node->Index = _Index;

	


	node->Count = 0;

	srand(GetTickCount64());
	node->Limit = rand()%100;



	// ** 새롭게 생성된 노드의 Obj에 Object를 생성.
	node->pObj = CreateObject(_x, _y, _Texture);

	// ** 새롭게 생성된 노드의 이전 노드를 셋팅하고.
	node->Front = End;

	// ** 다음 노드가 가르키는 곳에는 nullptr 로 셋팅.
	node->Back = nullptr;

	// ** 모든 초기값이 셋팅이 완료 되었다면 새롭게 생성된 노드를 마지막 노드로 셋팅.
	End = node;
}

void Output()
{
	// ** 첫버째 노드를 임시 노드에 저장.
	Node* node = Begin;

	// ** 첫번째 노드는 원소가 아니기 때문에 다음 노드로 이동시킨다.
	node = node->Back;

	// ** 현재 노드가 존재 하지 않거나, 
	// ** 현재 노드가 가르키는 Obj가 존재하지 않을때 까지... (반복)
	while (node && node->pObj)
	{
		SetCursorPosition(
			node->pObj->Position.x,
			node->pObj->Position.y);

		printf("%d.%s : %d (%d)\n", node->Index, node->pObj->Texture, node->Count, node->Limit);

		if (node->Count >= node->Limit)
		{
			// ** 삭제.
		}
		else
			++node->Count;


		// ** 다음 노드를 가르킨다.
		node = node->Back;
	}
}
