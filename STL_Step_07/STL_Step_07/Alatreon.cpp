#include "Alatreon.h"

Alatreon::Alatreon()
{
}

Alatreon::~Alatreon()
{
}


Object* Alatreon::Initialize()
{
	key = "Alatreon";
	count = 100;

	return this;
}

void Alatreon::Start()
{
	Info = INFO(0, 0, 0);
	key = "Alatreon";
	count = 100;
}

int Alatreon::Update()
{
	--count;

	if (count <= 0)
		return 1;

	return 0;
}

void Alatreon::Render()
{
	cout << key << ": " << count << endl;
}

void Alatreon::OnDestroy(Object* pObj)
{
	delete pObj;
	pObj = nullptr;
}
