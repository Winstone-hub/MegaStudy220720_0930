//#include <stdio.h>
#include <iostream>
#include <string>

/* 
[��ü������ Ư¡ 5����]

1. ��������
2. ĸ��ȭ
3. �߻�ȭ
4. ���
5. ������
*/

// namespace = ::

/*
* std ���۵����� ��� �Ǿ��ִ� ��ϸ� ���� ����.

using std::cout;
using std::endl;
using std::cin;
*/

// ** std ���۵Ǵ� namespace �� ��� ���� ����.
using namespace std;

const float PI = 3.141592f;

// ** �ɺ��� ��� = PI;
// ** ���ͷ� ��� = 3.141592f;


// ** pointer const �� ��� ����. 
const char* const FileName = "../Data/image.png";
//string FileName = "../Data/image.png";


int main(void)
{
	int Number = 0;

	// ** �Է�
	cin >> Number;

	// ** ��� 
	cout << "Hello World!! : " << Number << endl;

	return 0;
}
