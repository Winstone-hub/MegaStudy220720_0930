#pragma once // ** 헤더파일의 중복 정의를 막아준다.
#include "Headers.h"

class Parent
{
	// ** 완전한 정보 은닉 상태
private:


	// ** 상속관계에서만 정보 공개 상태, 상속이 아닌 경우에는 비공개.
	// ** 상속 : public
	// ** 비 상속 : private
protected:
	string Name;
	int Age;

	// ** 완전한 정보 공개 상태
public:

	// ** virtual 키워드는 가상 함수 키워드
	// ** 순수 가상 함수
	virtual void Initialize() = 0;
	virtual void Render() = 0;
};

