//#include <stdio.h>
#include <iostream>
#include <string>

/* 
[객체지향의 특징 5가지]

1. 정보은닉
2. 캡슐화
3. 추상화
4. 상속
5. 다형성
*/

// namespace = ::

/*
* std 시작되지만 언급 되어있는 목록만 생략 가능.

using std::cout;
using std::endl;
using std::cin;
*/

// ** std 시작되는 namespace 는 모두 생략 가능.
using namespace std;

const float PI = 3.141592f;

// ** 심볼릭 상수 = PI;
// ** 리터럴 상수 = 3.141592f;


// ** pointer const 의 사용 예시. 
const char* const FileName = "../Data/image.png";
//string FileName = "../Data/image.png";


int main(void)
{
	int Number = 0;

	// ** 입력
	cin >> Number;

	// ** 출력 
	cout << "Hello World!! : " << Number << endl;

	return 0;
}
