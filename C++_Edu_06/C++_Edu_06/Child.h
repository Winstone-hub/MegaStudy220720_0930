#pragma once
#include "Parent.h"

class Child : public Parent
{
public:
	// ** �������̵� : ��Ӱ��迡���� ��밡��
	// ** �Ȱ��� �̸��� �Լ��� ����� �� ��Լ��� ȣ���ؾ����� ��ȣ�Ѱ��.
	// ** �Լ��� ȣ���ϴ� ���.

	virtual void Start()override 
	{
		// ** �������̵� �Լ�.
	}
	virtual void Start(int number)override
	{

	}

	// ** �����ε� : ��Ӱ������ ���� ����� ����. 
	// ** ���� Ŭ���� ���ο��� ���Ǹ�, �Ȱ��� �̸��� �Լ��� ȣ���ϴ� ���.
	// ** �Ű������� ������ ���¿� ���� ȣ��Ǵ� �Լ��� �޶�����.
	void Update(int)
	{
		// ** �����ε� �Լ�.
	}

	void Update(float)
	{
		// ** �����ε� �Լ�.
	}

	void Update()
	{
		// ** �����ε� �Լ�.
	}
};

