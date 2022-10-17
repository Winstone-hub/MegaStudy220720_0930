#pragma once


struct Vector3
{
	float x, y, z;

	Vector3() : x(0), y(0), z(0) {};

	Vector3(const float& _x, const float& _y) :
		x(_x), y(_y), z(0) {};

	Vector3(const float& _x, const float& _y, const float& _z) :
		x(_x), y(_y), z(_z) {};

	const Vector3 operator*(const float& _f) const { return Vector3( this->x * _f, this->y * _f, this->z * _f); }
	const Vector3 operator/(const float& _f) const { return Vector3( this->x / _f, this->y / _f, this->z / _f); }
	const Vector3 operator+(const Vector3& _v) const { return Vector3( this->x + _v.x, this->y + _v.y, this->z + _v.z); }
	const Vector3 operator-(const Vector3& _v) const { return Vector3( this->x - _v.x, this->y - _v.y, this->z - _v.z); }

	const Vector3 operator+=(const Vector3& _v)
	{
		return Vector3(this->x += _v.x, this->y += _v.y, this->z += _v.z);
	}

	const Vector3 operator-=(const Vector3& _v)
	{
		return Vector3( this->x -= _v.x, this->y -= _v.y, this->z -= _v.z);
	}
};

struct Transform
{
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;
};