#pragma once
#include "Headers.h"

class Object;
class MainUpdate
{
private:
	// ** 변수 생성.
	Object* ObjectList[2];
public:
	// ** 초기화
	void Initialize();

	// ** 변경
	void Progress();

	// ** 갱신
	void Render();

	// ** 삭제
	void Release();
public:
	MainUpdate();
	~MainUpdate();
};

