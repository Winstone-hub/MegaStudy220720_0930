#include "Headers.h"
#include "Child.h"


// ** operator
class Test
{
private:
	int Number;
public:
	void Render()
	{
		cout << Number << endl;
	}
public:
	Test() : Number(0)
	{

	}

	Test(int _Number) : Number(_Number)
	{

	}

public:
	Test operator+=(Test& p)
	{
		Number += p.Number;
		return Test(Number);
	}

	Test operator+(Test& p)
	{
		return Test(Number + p.Number);
	}
};





int main(void)
{
	Vector3 Position = Vector3(10.0f, 10.0f);
	Vector3 Point = Vector3(5.0f, 5.0f);

	Position -= Point;

	cout << Position.x << ", "
		<< Position.y << ", "
		<< Position.z << endl;

	Position += Point;

	cout << Position.x << ", "
		<< Position.y << ", "
		<< Position.z << endl;

	Test t1 = Test(10);
	Test t2 = Test(20);
	Test t3 = t1 + t2;
	t3.Render();

	t1 += t3;
	t1.Render();



	return 0;
}