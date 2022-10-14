#pragma once
#include "Headers.h"

class Operator
{
private:
	char* name;
	int age;

public:
	void render() { cout << name << " : " << age << endl; } 

public:
	void setName(char* name) { this->name = name; }
	void setAge(int age) { this->age = age; }

public:
	void operator=(char* str)
	{
		this->name = new char[strlen(str) + 1];
		strcpy(this->name, str);
	}

public:
	Operator() : name(nullptr), age(0) {}
	Operator(char* _name, int _age) : name(_name), age(_age) {}
};

