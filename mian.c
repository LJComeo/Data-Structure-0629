#include "List.h"

int main()
{
	List list;
	ListInit(&list);
	ListPushBack(&list, 7);
	ListPushBack(&list, 6);
	ListPushBack(&list, 5);
	ListPushBack(&list, 4);
	ListPushBack(&list, 3);
	ListPushBack(&list, 2);
	ListPrint(&list);
	system("pause");
	return 0;
}