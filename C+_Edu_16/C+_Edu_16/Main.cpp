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
	// ** capacity(수용량) 가(이) size(현재원소의 개수) 와 값이 서로 같다면
	// ** 원소를 더이상 추가 할 수 없는 상태이므로..
	if (capacity == size)
	{
		// ** 수용량을 늘려준다.
		int result = (capacity >> 1);
		capacity += (result < 1) ? 1 : result;





		// ** 수용량이 늘어나게 되면 실제 메모리 상의 수용량도 늘려야 하기 때문에
		// ** 늘리는 과정에서 데이터를 보존 할 수 없으므로 미리 데이터를 옴겨 두어야 한다.
		// ** 그러기 위해 필요한 임시의 공간을 생성.
		
		//===============[변경 사항]==================
		//int* Temp = (int*)malloc(sizeof(int) * (size + 1));
		
		//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

		// ** 늘어난 수량량의 크기로 임시의 공간을 새롭게 생성.
		int* Temp = (int*)malloc(sizeof(int) * capacity);
		//============================================





		// ** 임시의 공간에 기존 데이터를 복사 한다.
		// ** 이때! 주소의 복사가 아니라 값의 복사가 이루어 져야 한다.
		for (int i = 0; i < size; ++i)
			Temp[i] = Fornt[i];



		// ** 기존 할당된 메모리공간을 해제한다.,
		free(Fornt);




		// ** 늘어난 수용량 만큼의 크기로 새롭게 공간을 할당 한다.
		//Fornt = (int*)malloc(sizeof(int) * capacity);





		// ** 새롭게 할당된 공간에 복사해둔 데이터를 다시 들고온다.
		/*
		for (int i = 0; i < size; ++i)
			Fornt[i] = Temp[i];
		*/





		//===============[변경 사항]==================
		// ** 임시의 공간을 할당 해제한다.
		//free(Temp);
		
		//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

		// ** 임시 공간의 주소를 Fornt가 받아온다.
		// ** Temp 는 생성된 해당 영역을 빠저나가면 소멸된다.
		// ** 하지만 할당된 메모리주소는 Fornt에 남아 있으므로 사용 가능.
		Fornt = Temp;
		//============================================
		





		// ** 시작지점의 주소가 바뀌었으므로 새롭게 셋팅 해준다.
		Back = &Fornt[size];
	}
	
	// ** 위 분기의 실행 유/무와 상관 없이 현재 위치에서는 항상 수용량이 남는다.
	// ** 항상 (capacity > size) 와 같은 상태이므로 원소 추가가 가능하다.
	Fornt[size] = _value;

	// ** 원소가 추가 되었으므로 size를 증가시킴.
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
	printf("[전체 출력]\n");

	for (int i = 0; i < size; ++i)
		printf("%d\n", Fornt[i]);
}
