#pragma once
#include "Headers.h"

class Parent
{
protected:
	string Name;
	
	// ** [�߻� Ŭ���� Ư¡]
	// ** �����ʹ� ������ �� ������, �Լ��� ���� ���� �Լ��θ� ������ �� �ִ�.
	
	// ** [���������Լ��� Ư¡]
	// ** ���������Լ��� 1���� ���������, �� Ŭ������ �߻� Ŭ���θ� ��� �����ϴ�.

	// ** [����]
	// ** ���������Լ��� 1���� �����, �Ϲ��Լ� ���� �� ��� �Ұ�.

public:
	// ** ���� �����Լ�.
	virtual void Start()PURE;
	virtual void Start(int number)PURE;
};



