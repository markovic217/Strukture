#include"DList.h"

void main()
{
	DList *list = new DList();
	list->addToHead(6);
	list->addToHead(3);
	list->addToHead(2);
	list->addToHead(7);
	list->addToHead(1);
	list->addToHead(9);
	list->addToHead(4);
	list->printAll();

//Kolokvijum 2021
	list->exchange(4, 6);
	list->printAll();
	list->exchange(5, 6);
	list->exchange(5, 10);
	list->exchange(1, 3);
	list->printAll();
	list->exchange(3, 7);
	list->exchange(3, 7);
	list->printAll();

	delete list;
}