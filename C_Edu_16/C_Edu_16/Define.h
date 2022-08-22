#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// ** 상수
#define PI 3.141592f

// ** 메세지 출력
#define Output(str) printf("%s\n", str);
#define ERRMSG(FileName) printf("%d라인에서 Err가 발생하였습니다.\n%s 에서 File을 찾을수 없습니다.\n", __LINE__, FileName);

// ** 연산
#define SUM(a, b) (a + b)
#define MUL(a, b) (a * b)

extern int Count;
