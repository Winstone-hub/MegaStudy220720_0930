#include "Functions.h"

struct Object
{
	char* Name;
	int Age;
};

Object* CreateObject(bool _b);



int Count = 0;

int main(void)
{
	//printf("%f\n", PI);
	//Output("ȫ�浿")
	
	/*
	{
		Object* o = CreateObject(false);

		if (!o) // ** Err �߻� !!
		{
			ERRMSG("���");
			exit(0);
		}
	}
	*/

	/*
	{
		printf("�� ���� ���� : %d\n", SUM(10, 20));
		printf("�� ���� ���� : %d\n", MUL(10, 20));
	}
	*/
	

//#if
 	   // ** ������ �ڵ�� �����Ű�� ���� �ڵ带 ����.
//#endif


/*
#ifndef 1

#endif // !1
*/



/*
//#define DEBUG

#ifdef DEBUG
	printf("DEBUG ���� �Ǿ����ϴ�.\n");
#else
	printf("DEBUG ���ǵ��� �ʾҽ��ϴ�.\n");
#endif // DEBUG
*/


	Count = 100;
	Func();






//https://www.youtube.com/watch?v=BeoCbJPuvSE

	return 0;
}




Object* CreateObject(bool _b)
{
	Object* Obj = nullptr;

	if (_b)
		Obj = (Object*)malloc(sizeof(Object));

	return Obj;
}