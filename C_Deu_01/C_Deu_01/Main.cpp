/*
* Chapter 01
*/
#include <stdio.h> // stdio.h : std -> 스텐다드, i -> 인풋, o -> 아웃풋, .h -> 확장자가 헤더
// ** include : ~포함하다., ~포함시키다
// ** 앞쪽에 # 붙어있다면 전처리기, 전처리 지시문, 전처리기 지시문 등 으로 표현

#include <stdlib.h> // stdlib.h : std -> 스텐다드, lib -> 라이브러리, .h -> 확장자가 헤더

// ** 보안을 위한 경고 메시지를 띄우지 말라고 지시함.
#define _CRT_SECCURE_NO_WARNINGS


// ** main 함수는 매우 특별한 함수 입니다.
// ** 컴파일러가 프로그램을 실행 시킬때 main함수를 찾기 때문에...
int main(void)
{
	// () 소괄호
	// {} 중괄호
	// [] 대괄호

	// ** 출력 함수
	printf("Be happy!");
	
	// ** 콘솔 출력 화면음 일시 정지시켜준다.
	system("pause");

	return 0;
}
