#pragma once
#include "Parent.h"

class Child : public Parent
{
public:
	// ** 오버라이딩 : 상속관계에서만 사용가능
	// ** 똑같은 이름의 함수를 사용할 때 어떤함수를 호출해야할지 모호한경우.
	// ** 함수를 호출하는 기술.

	virtual void Start()override 
	{
		// ** 오버라이드 함수.
	}
	virtual void Start(int number)override
	{

	}

	// ** 오버로딩 : 상속관계랑은 전혀 상관이 없음. 
	// ** 같은 클래스 내부에서 사용되며, 똑같은 이름의 함수를 호출하는 기술.
	// ** 매개변수의 개수나 형태에 따라 호출되는 함수가 달라진다.
	void Update(int)
	{
		// ** 오버로드 함수.
	}

	void Update(float)
	{
		// ** 오버로드 함수.
	}

	void Update()
	{
		// ** 오버로드 함수.
	}
};

