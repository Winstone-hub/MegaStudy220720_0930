#include <stdio.h>
#include <malloc.h>


struct Node
{
	int Value;
	Node* Next;
};



int main(void)
{
	Node* List = (Node*)malloc(sizeof(Node));
	List->Value = 10;

	List->Next = (Node*)malloc(sizeof(Node));
	List->Next->Value = 20;

	List->Next->Next = (Node*)malloc(sizeof(Node));
	List->Next->Next->Value = 30;


	printf("%d\n", List->Value);
	printf("%d\n", List->Next->Value);
	printf("%d\n", List->Next->Next->Value);


	return 0;
}