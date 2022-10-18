#pragma once

// 열거형
/*
enum {
	A, // = 0 
	B, // = 1
	C, // = 2
	D, // = 3
	E, // = 4
};
*/


// ** 상수, 정수
enum {
	Player,
	Enemy,
	Bullet,
	MAX,
};

enum class ObjectID {
	Player,
	Enemy,
	Bullet,
	MAX,
};



enum SceneID
{
	LOGOID,
	MENUID,
	STAGEID,
	EXITID,
};