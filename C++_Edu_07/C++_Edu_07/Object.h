#pragma once
#include "Headers.h"

class Object
{
private:
	// ** 변수 생성.
public:
	// ** 초기화
	virtual void Initialize()PURE;

	// ** 변경
	virtual void Progress()PURE;

	// ** 갱신
	virtual void Render()PURE;

	// ** 삭제
	virtual void Release()PURE;
};