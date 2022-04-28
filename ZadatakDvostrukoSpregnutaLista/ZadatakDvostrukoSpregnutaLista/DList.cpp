#include "DList.h"



DList::DList()
{
	head = NULL;
}


DList::~DList()
{
	while (!isEmpty())
	{
		int tmp = deleteFromHead();
	}
}

DListNode* DList::findNodePtr(int el)
{
	if (isEmpty())
		throw new exception("List is empty");
	DListNode *ret = head;
	while (ret != NULL && ret->info != el)
	{
		ret = ret->next;
	}
	return ret;
}

int DList::getHeadEl()
{
	if (isEmpty())
		throw new exception("List is empty");
	return head->info;
}

int DList::getNextEl(int el)
{
	if (isEmpty())
		throw new exception("List is empty");
	DListNode* tmp = findNodePtr(el);
	if (tmp == NULL)
		throw new exception("Node doesn't exist");
	if (tmp->next == NULL)
		throw new exception("Element doesn't have next node");
	return tmp->next->info;
}

int DList::getPreviousEl(int el)
{
	if (isEmpty())
		throw new exception("List is empty");
	DListNode* tmp = findNodePtr(el);
	if (tmp == NULL)
		throw new exception("Node doesn't exist");
	if (tmp->prev == NULL)
		throw new exception("Element doesn't have previous node");
	return tmp->prev->info;
}

bool DList::isInList(int el)
{
	if (isEmpty())
		return false;
	DListNode* tmp = findNodePtr(el);
	if (tmp == NULL)
		return false;
	else
		return true;
}

void DList::deleteEl(int el)
{
	if (!isEmpty())
		if (head->isEqual(el))
		{
			DListNode *tmp = head;
			head = head->next;
			head->prev = NULL;
			delete tmp;
		}
		else
		{
			DListNode *tmp;
			for (tmp = head->next; tmp != NULL && !(tmp->isEqual(el)); tmp = tmp->next);
			if (tmp != NULL)
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				delete tmp;
			}
		}
}

void DList::addToHead(int el)
{
	head = new DListNode(el, NULL, head);
	if(head->next!=NULL)
		head->next->prev = head;
}

void DList::addToTail(int el)
{
	if (!isEmpty())
	{
		DListNode* tmp = head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new DListNode(el, tmp, NULL);
	}
	else
		addToHead(el);
}

int DList::deleteFromHead()
{
	if (isEmpty())
		throw new exception("List is empty");
	int el = head->info;
	DListNode *tmp = head;
	head = head->next;
	if(head!=NULL)
		head->prev = NULL;
	delete tmp;
	return el;
}

int DList::deleteFromTail()
{
	if (isEmpty())
		throw new exception("List is empty");
	int el;
	if (head->next == NULL)
	{
		return deleteFromHead();
	}
	else
	{
		DListNode *tmp = head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		el = tmp->info;
		tmp->prev->next = NULL;
		delete tmp;
	}
	return el;
}

void DList::printAll()
{
	DListNode *tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->print() << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

//Kolokvijum 2021
void DList::exchange(int a, int b) {
	DListNode* n1 = findNodePtr(a);
	DListNode* n2 = findNodePtr(b);
	if (n1 != NULL && n2 != NULL){		
		DListNode *n1prev = n1->prev, *n1next = n1->next,
				  *n2prev = n2->prev, *n2next = n2->next;
		if (n1next == n2) {
			n1prev->next = n2;
			n2->prev = n1prev;
			n2->next = n1;
			n1->prev = n2;
			n1->next = n2next;
			n2next->prev = n1;
		}
		else 
		if (n1prev == n2){
			n1next->prev = n2;
			n2->next = n1next;
			n2->prev = n1;
			n1->next = n2;
			n1->prev = n2prev;
			n2prev->next = n1;
		}
		else
		{
			if (n1prev != NULL)
				n1prev->next = n2;
			if (n1next != NULL)
				n1next->prev = n2;
			n2->prev = n1prev;
			n2->next = n1next;
			if (n2prev != NULL)
				n2prev->next = n1;
			if (n2next != NULL)
				n2next->prev = n1;
			n1->prev = n2prev;
			n1->next = n2next;
			if (n1 == head) {
				head = n2;
				return;
			}
			if (n2 == head) {
				head = n1;
				return;
			}
		}
	}
}