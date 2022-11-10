#pragma once




typedef struct tagInfo
{
	int kor;
	int eng;
	int math;

	tagInfo() : kor(0), eng(0), math(0) {}

	tagInfo(int _kor, int _eng, int _math) : 
		kor(_kor), eng(_eng), math(_math) {}
}INFO;
