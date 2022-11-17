#pragma once

struct Vector3
{
	float x, y, z;

	Vector3() : x(0), y(0), z(0) {}
	Vector3(float _x, float _y) : x(_x), y(_y), z(0) {}
	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

	Vector3 operator+(Vector3 v) { return Vector3( x + v.x, y + v.y, z + v.z); }
	Vector3 operator-(Vector3 v) { return Vector3( x - v.x, y - v.y, z - v.z); }
	Vector3 operator*(float f) { return Vector3( x * f, y * f, z * f); } 
	Vector3 operator/(float f) { return Vector3( x / f, y / f, z / f); }
};

struct Transform
{
	Vector3 Position;
	Vector3 Scale;
	Vector3 Direction;
};