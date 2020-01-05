#include <iostream>
#include "rem_dup_lib.h"

using namespace std;

void removeConsecutive(Item* head)
{
	if(head == NULL)
	{
		return;
	}
	else if(head->next == NULL)
	{
		return;
	}
	else
	{
		if(head->val == head->next->val)
		{
			Item* temp = head->next;
			head->next = head->next->next;
			delete temp;
			removeConsecutive(head);
		}
		else
		{
			removeConsecutive(head->next);
		}
	}
}

Item* concatenate(Item* head1, Item* head2)
{
	if(head1 == NULL)
	{
		return head2;
	}
	else if(head1->next == NULL)
	{
		head1->next = head2;
		return head1;
	}
	else
	{
		Item* temp = getLastElement(head1);
		temp->next = head2;
		return head1;

	}
}


Item* getLastElement(Item* head)
{
	if(head->next == NULL)
	{
		return head;
	}
	else 
	{
		return getLastElement(head->next);
	}
}
