#include "List.h"

void ListInit(List* plist)//初始化
{
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	memset(&plist->_head->_data, 0, sizeof(LTDataType));//清零
	plist->_head->_next = plist->_head->_prev = plist->_head;
}

void ListPushBack(List* plist, LTDataType x)//后插
{
	ListNode * cur = (ListNode*)malloc(sizeof(ListNode));
	cur->_data = x;

	plist->_head->_prev->_next = cur;
	cur->_prev = plist->_head->_prev;
	plist->_head->_prev = cur;
	cur->_next = plist->_head;
}
void ListPopBack(List* plist)//后删
{
	ListNode * tmp = plist->_head->_prev;//找到head的前一个

	if (tmp != plist->_head)//把tmp删除
	{
		tmp->_prev->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
	}
}
void ListPushFront(List* plist, LTDataType x)//头插
{
	ListNode * cur = (ListNode*)malloc(sizeof(ListNode));
	cur->_data = x;

	plist->_head->_next->_prev = cur;
	cur->_next = plist->_head->_next;
	plist->_head->_next = cur;
	cur->_prev = plist->_head;
}
void ListPopFront(List* plist)//头删
{
	ListNode * tmp = plist->_head->_next;//找到head的后一个

	if (tmp != plist->_head)//删除tmp
	{
		tmp->_prev->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
	}
}

void ListDestory(List* plist)//清除链表
{
	ListNode * tmp = plist->_head->_next;//找到head的后一个

	while (tmp != plist->_head)//删除tmp
	{
		tmp->_prev->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
		tmp = plist->_head->_next;
	}
	free(plist->_head);
	plist->_head = NULL;
}
void ListPrint(List* plist)
{
	ListNode * cur = (ListNode*)malloc(sizeof(ListNode));
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		printf("%d<-->", cur->_data);
	}
	putchar('\n');
}