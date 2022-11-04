#include "Object.h"

Object::Object()
{
}

Object::Object(string key, string name)
{
	this->key = key;
	this->name = name;
}

Object::Object(string key, string name, Vector2 position)
{
	this->key = key;
	this->name = name;
	this->position.x = position.x;
	this->position.y = position.y;
}

Object::~Object()
{
}
