#include "Prototype.h"
#include "Player.h"

Prototype* Prototype::Instance = nullptr;

Prototype::Prototype()
{

}

Prototype::~Prototype()
{

}

void Prototype::Initialize()
{
	Transform Info;
	Info.Position = Vector3(0.0f, 0.0f, 0.0f);
	Info.Direction = Vector3(0.0f, 0.0f, 0.0f);
	Info.Scale = Vector3(0.0f, 0.0f, 0.0f);

	string key = "";
	PrototypeObjects[key] = (new Player(Info))->Initialize(key = "Player");
}

Object* Prototype::FindObject(string _key)
{
	auto iter = PrototypeObjects.find(_key);

	if(iter == PrototypeObjects.end())
		return nullptr;

	return iter->second;
}
