/*
* Chapter 07
*/

#include <stdio.h>


// ** 함수의 전방 선언
int sum(int _x, int _y);
// * 전방 선언은 항상 main(void)의 상단에 위치 시켜야 한다.


// ** 함수 전방성언시 매개변수의 이름은 생략해도 된다.
void Output(int, int);
int Compare(int _x, int _y);

/*
//** 함수가 재귀적으로 호출되기 때문에 종료되는 구간이 없다면 스택 오버프로우 발생한다.
void Recursive()
{
	printf("재귀호출");
	Recursive();
}
*/


// ** 매개 변수를 사용하여 재귀함수의 호출횟수를 카운트하고 함수를 종료시키는 방법.
void Recursive(int _n)
{
	if (_n == 0)
		return;
	else
	{
		printf("%d 재귀호출\n", _n);
		Recursive(_n - 1);
	}
}


int main(void)
{
	/*
	int a = 10, b = 20;

	int result = sum(a, b);
	//sum(a, b); 

	//printf_s("%d\n", result);
	printf_s("result : %d\n", sum(a, b));
	*/
 

	// ** 영역 표현하는 중괄호 { } 를 사용하여, 여러개의 영역을 갖을수 있다.
	{
		// 일본
		{
			// 도쿄
		}

		{
			// 오사카
		}
	}


	{
		// 중국
		{
			// 상해
		}

		{
			// 심천
		}
	}


	{
		// 한국
		{
			// 서울
			{
				// 강남
			}
		}

		{
			// 부산
			{
				// 서면
			}
		}
	}




	// ** 영역 내부에서의 변수 사용.
	/*
	{
		// 같은 이름의 변수를 사용.
		int x = 10; 

		{
			// ** 변수의 이름이 같은 경우 해당 영역 내부에 있는 변수를 우선순위로 정한다.
			int x = 20;
			

			printf_s("첫번째 : %d\n", x);
		}


		printf_s("두번째 : %d\n", x);

		// ** 1. 문제 : 상위에 있는 변수의 값을 사용할 수 없다.
		// ** 2. 문제 : 변수의 이름이 같기 때문에 변수 사용에 혼란이 생길수 있다.
	}
	*/


	/*
	// ** 변수의 존재 기간.
	{
		// ** 변수는 선언된 해당 영역이 종료되는 지점까지 사용 가능.
		int 변수1 = 10;

		{
			int 변수2 = 20;

			변수1 = 변수2;

			// 변수1 <= 사용 가능.
		}

		// 변수2 = 30;   <= X   사용 불가.
	}
	*/



	// ================================
	/*
	{
		// ** 같은 이름의 변수명을 다른 영역에서 도로 갖을수 있다.
		int result = sum(a, b);
	}
	*/


	Output(10, 20);


	int result = Compare(30, 30);
	printf("%d\n", result);


	Recursive(5);

	return 0;
}


// ** 함수의 정의
int sum(int _x, int _y)
{
	int result = _x + _y;
	return result;
}

void Output(int _x, int _y)
{
	printf("%d + %d = %d 입니다\n", _x, _y, _x + _y);
}


int Compare(int _x, int _y)
{
	if (_x > _y)
		return _x;
	else if (_x < _y)
		return _y;
	else
		return 0;
}

