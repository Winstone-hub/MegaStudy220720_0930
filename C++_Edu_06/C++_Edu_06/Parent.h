#pragma once
#include "Headers.h"

class Parent
{
protected:
	string Name;
	
	// ** [추상 클래스 특징]
	// ** 데이터는 존재할 수 있지만, 함수는 순수 가상 함수로만 존재할 수 있다.
	
	// ** [순수가상함수의 특징]
	// ** 순수가상함수가 1개라도 만들어지면, 그 클래스는 추상 클래로만 사용 가능하다.

	// ** [정리]
	// ** 순수가상함수를 1개라도 만든다면...
	// ** 추상클래스 이므로 인스턴스화 불가.

public:
	// ** 순수 가상함수.
	virtual void Start()PURE;
	virtual void Start(int number)PURE;
};



