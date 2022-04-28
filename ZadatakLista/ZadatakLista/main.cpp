//Proba commita
#include "LList.h"

void main()
{
	LList *list = new LList();
	list->addToHead(6);
	list->addToHead(3);
	list->addToHead(2);
	list->addToHead(7);
	list->addToHead(1);
	list->addToHead(9);
	list->addToHead(4);	

	//Jun 2 2021
	LList* list2 = new LList();
	list2->addToTail(1);
	list2->addToTail(2);
	list2->addToTail(3);
	list2->addToTail(4);
	list2->addToTail(6);
	list2->addToTail(7);
	list2->addToTail(9);
	list2->injectOrRemove(1);
	list2->injectOrRemove(5);
	list2->injectOrRemove(10);
	list2->injectOrRemove(1);
	list2->injectOrRemove(5);
	//list2->printAll();
	delete list2;

	delete list;
}