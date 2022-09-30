#include <iostream>

using namespace std;

// ** inline = Ű����

// ** ��� ��)
/* inline int FunctionName()
*  {
*		�Լ��� inline Ű���尡 �پ��ִٸ� �� �Լ��� �켱ó�� ���.
*		��Ȳ�� ���� �켱ó�� ��󿡼� ���ܵ� ���� �ִ�.
*		���ܶ�°� ���� ���ܰ� �ƴ϶� ��������� �и��� �ִٴ� ��.
*  }
*/


// ** ������
// ** ���� ������
// ** �Ҹ���
struct Vector2
{
	float x, y;

	// ** ������
	Vector2() : x(0), y(0) {};

	// ** ���� ������
	Vector2(float _x, float _y) : x(_x), y(_y) {};
};

class Transform
{
private:// ** �����
	Vector2 Psosition;

protected: // ** ��Ӱ��� ����

public: // **  ����
	float x, y; // ** �ɹ� ����

public:
	void Output()
	{
		cout << "X : " << Psosition.x << endl;
		cout << "Y : " << Psosition.y << endl;
	}

public:
	// ** ������ ���� �ڵ����� ȣ���� �Ǵ� �Լ�.
	// ** ����ڰ� ���� �������� �ʴ��� �⺻ �����ڰ� ȣ���.
	Transform() : x(0), y(0), Psosition( Vector2(0.0f, 0.0f) )
	{
		cout << "������" << endl;
	}

	// ** ��������ڴ� ���� ȣ���ؾ߸� ȣ���.
	// ** ��������ڴ� �Ű������� ������ �ڷ����� Ÿ������ ���еǾ�,
	// ** �������� ��������ڸ� ������ �� �ִ�.
	Transform(float _x, float _y) : x(_x), y(_y)
	{
		cout << "float _x, float _y" << endl;
	}

	Transform(int _x, int _y) : x(_x), y(_y)
	{
		cout << "int _x, int _y" << endl;
	}

	Transform(int _x, float _y) : x(_x), y(_y)
	{
		cout << "int _x, float _y" << endl;
	}

	Transform(float _x, int _y) : x(_x), y(_y)
	{
		cout << "float _x, int _y" << endl;
	}

	// ** �Ҹ�Ǳ� ������ �ڵ����� ȣ���� �Ǵ� �Լ�.
	// ** ����ڰ� ���� �������� �ʴ��� �⺻ �Ҹ��ڰ� ȣ���.
	~Transform()
	{
		cout << "�Ҹ���" << endl;
	}
};



class MyEmpty
{
private:
	int number;
public:
	void Initialize()
	{
	}
	void Output()
	{

	}
private:
	MyEmpty() : number(0)
	{

	}
};

/*
void empty::Output()
{
	cout << number << endl;
}
*/


int main(void)
{
	// ** ���� ������ ȣ��
	Transform t = Transform(0.0f, 0);
	t.Output();

	cout << "���α׷��� ����˴ϴ�." << endl;
	return 0;
}


