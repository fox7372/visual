#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct lie
{
	int data;
	struct lie*next;
}lie;

lie* creatnote(int data)
{
	lie* newnote = (lie*)malloc(sizeof(lie));
	if (newnote == NULL) {
		printf("ÄÚ´æ·ÖÅäÊ§°Ü£¡\n");
		exit(1);
	}
	
	newnote->next=NULL;
	newnote->data = data;
	return newnote;
}
lie* creatlist(int arr[], int length)
{
	if (length <= 0) return NULL;
	lie* head= creatnote(arr[0]);
	lie* tail = head;
	
	for (int i = 1; i <length; i++)
	{
		lie* newlie = creatnote(arr[i]);
		tail->next = newlie;
		tail= newlie;
	}
	return head;
	
}
void printflie(lie* head)
{
	lie* now = head;
	while (now != NULL)
	{
		printf("%d\t", now->data);
		now = now->next;

	}
}
void freelie(lie* head)
{
	lie* temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
lie* addlie(lie*head,int data,int m)
{
	lie* amm=head;
	for (int i = 1; i < m; i++)
	{
		amm = amm->next;
	}
	lie* mm = creatnote(data);
	mm->next = amm->next;
	amm->next = mm;
	return head;
}
lie* dellie(lie* head, int m)
{
	lie* t = head;
	for (int i = 1; i < m; i++)
	{
		t = t->next;
	}
	lie* k = head;
	for (int j = 1; j < m - 1; j++)
	{
		k = k->next;
	}
	k->next = t->next;
	free(t);
	return head;
}
