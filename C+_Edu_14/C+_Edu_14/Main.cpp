/*
 * Vector
 */

#include <stdio.h>
#include <malloc.h>

int* Fornt;
int* Back;

int size = 0;
int* Vector = nullptr;

void push_back(int _value);

int main(void)
{
	push_back(10);
	push_back(20);

	printf("%d\n", *Fornt);
	printf("%d\n", *Back);

	/*
	for (int i = 0; i < 10; ++i)
	{
		Vector[i] = i;
	}

	Fornt = &Vector[0];
	Back = &Vector[9];

	printf("%d\n", *Fornt);
	printf("%d\n", *Back);
	*/

	return 0;
}

void push_back(int _value)
{
	++size;
	Vector = (int*)malloc(sizeof(int) * size);
	Vector[size - 1] = _value;

	Fornt = &Vector[0];
	Back = &Vector[size - 1];
}
