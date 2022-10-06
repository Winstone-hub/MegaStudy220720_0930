#include "Headers.h"

#include "Child1.h"
#include "Child2.h"

// ** 상속
// ** 동일한 클래스, 함수 등을 사용할 수 있도록 해준다.

// ** namespace 를 사용하여 클래스를 작성 하는것이 가능하다.

// ** 추상성
// ** 가상함수 & 순수가상함수

// ** 다형성
// ** 오버로딩 & 오버라이딩
// ** 연산자 오버로딩




int main(void)
{
	/*
	Parent* pP = new Parent;
	Child* pC = new Child;
	*/

	// ** Number는 int로 선언되어 있다.
	// ** float 값을 형변환을 해서 준다고 해도,
	// ** Number의 형태는 절대 변하지 않는다.
	int Number = (float)3.141592f;

	// ** Parent* pP1도 마찬가지 이다.
	// ** new Child1 를 해서 pP1 에 Child1를 주었다고 해도,
	// ** pP1의 Parent* 타입이 Child1* 타입으로 변경되지 않는다.
	Parent* ObjectList[2];

	ObjectList[0] = new Child1;

	// ** 현재 Parent 는 함수가 존재하지 않기 때문에
	// ** 형변환을 통하여 Child1 의 클래스에 있는 함수를 호출하여야 한다.
	ObjectList[0]->Initialize();
	ObjectList[0]->Render();

	// ** Child2를 생성
	ObjectList[1] = new Child2;

	// ** Child1 의 함수를 호출하여 값을 초기화.
	ObjectList[1]->Initialize();

	// ** 임꺽정이 나와야 하지만 홍길동이 나온다.
	ObjectList[1]->Render();

	// ** 부모가 동일한 데이터타입일 경우에는 자식클래스의
	// ** 형변환이 가능하다. 다만 포함하고 있는 데이터까지 공유 되는것은 아니기 때문에
	// ** 데이터의 값을 출력하거나 사용할 경우 신중하게 생각하자.





	// ** 하나의 데이터 타입으로 여러 자식클래스를 둘수 있다.
	// ** 일괄 호출
	for (int i = 0; i < 2; ++i)
		ObjectList[i]->Render();




	return 0;
}