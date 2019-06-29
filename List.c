#include "List.h"

void ListInit(List* plist)//��ʼ��
{
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	memset(&plist->_head->_data, 0, sizeof(LTDataType));//����
	plist->_head->_next = plist->_head->_prev = plist->_head;
}

void ListPushBack(List* plist, LTDataType x)//���
{
	ListNode * cur = (ListNode*)malloc(sizeof(ListNode));
	cur->_data = x;

	plist->_head->_prev->_next = cur;
	cur->_prev = plist->_head->_prev;
	plist->_head->_prev = cur;
	cur->_next = plist->_head;
}
void ListPopBack(List* plist)//��ɾ
{
	ListNode * tmp = plist->_head->_prev;//�ҵ�head��ǰһ��

	if (tmp != plist->_head)//��tmpɾ��
	{
		tmp->_prev->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
	}
}
void ListPushFront(List* plist, LTDataType x)//ͷ��
{
	ListNode * cur = (ListNode*)malloc(sizeof(ListNode));
	cur->_data = x;

	plist->_head->_next->_prev = cur;
	cur->_next = plist->_head->_next;
	plist->_head->_next = cur;
	cur->_prev = plist->_head;
}
void ListPopFront(List* plist)//ͷɾ
{
	ListNode * tmp = plist->_head->_next;//�ҵ�head�ĺ�һ��

	if (tmp != plist->_head)//ɾ��tmp
	{
		tmp->_prev->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
	}
}

void ListDestory(List* plist)//�������
{
	ListNode * tmp = plist->_head->_next;//�ҵ�head�ĺ�һ��

	while (tmp != plist->_head)//ɾ��tmp
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