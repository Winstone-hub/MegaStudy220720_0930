#include "Headers.h"
#include "Object.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "ObjectFacyory.h"

int main(void)
{
	Vector2 position;
	position.x = 0;
	position.y = 0;

	Object* pObj = ObjectFacyory::CreateObject<Bullet>("ȫ�浿", position);

	cout << pObj->GetKey() << endl;
	cout << pObj->GetName() << endl;
	cout << pObj->GetPosition().x << ", " << pObj->GetPosition().y << endl << endl;

	return 0;
}