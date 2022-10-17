#include "Headers.h"
#include "Child.h"
#include "MainUpdate.h"

/*
int Sum(const int& num1, const int& num2)
{
	cout << &num1 << endl << &num2 << endl;
	return num1 + num2;
}
*/

int main(void)
{
	//=======================================
	/*
	int num1 = 0, num2 = 0;
	cout << &num1 << endl << &num2 << endl;

	cout << Sum(num1, num2) << endl;
	*/
	//=======================================
	/*
	Object* pc = new Child();
	//Child* pc = new Child();

	delete pc;
	pc = nullptr;
	*/
	//=======================================

	ULONGLONG Time = GetTickCount64();

	MainUpdate Main;
	Main.Start();

	while (true)
	{
		if (Time < GetTickCount64())
		{
			Time = GetTickCount64();

			Main.Update();
			Main.Render();
		}
	}

	return 0;
}


