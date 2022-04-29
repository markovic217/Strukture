#include "ChainedScatterTable.h"

ChainedScatterTable::ChainedScatterTable(unsigned int length)
{
	m = length;
	count = 0;
	lrmp = m;
	array = new ChainedScatterObject[m];
	for (int i = 0; i < m; i++)
	{
		array[i].next = i + 1;
	}
	array[m - 1].next = 0;
}


ChainedScatterTable::~ChainedScatterTable()
{
	delete[] array;
}

void ChainedScatterTable::insert(ChainedScatterObject obj)
{
	if (count == m)
		throw new exception("Tablica je puna!");
	unsigned int probe = h(obj.getKey());
	if (array[probe].status == 2)
	{
		while (array[probe].status != -1)
		{
			probe = array[probe].next;
		}
		unsigned int tail = probe;
		probe++;
		while (array[probe].status != 0)
			probe++;
		array[tail].next = probe;
 	}
	array[probe] = obj;
	array[probe].status = 2; // zauzet
	array[probe].next = -1;
	count++;
}

void ChainedScatterTable::update()

void ChainedScatterTable::print()
{
	for (unsigned int i = 0; i < m; i++)
	{
		if (i == m)
			cout << "---------------------------------------" <<endl;
		cout << i << " ";
		array[i].print();
	}
}

ChainedScatterObject ChainedScatterTable::find(char* key)
{
	unsigned int probe = h(key);
	while (probe != -1)
	{
		if (!array[probe].isEqualKey(key))
			probe = array[probe].next;
		else
			return array[probe];
	}
	return ChainedScatterObject();
}

// Kolokvijum 2021
ChainedScatterObject ChainedScatterTable::withdraw(char* key) {
	if (count == 0)
		return ChainedScatterObject(); //return NULL
	int probe = h(key);
	if (array[probe].getRecord() == NULL)
		return ChainedScatterObject(); // return NULL
	int prev;
	ChainedScatterObject r;
	bool ok = false;
	while (array[probe].next != -1) {
		ok = true;
		prev = probe;
		probe = array[probe].next;
	}
	if (ok) {
		r = array[probe];
		array[prev].next = -1;
		array[probe].status = 1; //Obrisan
		array[probe].next = (probe+1)<m ?probe + 1 :0;
		array[probe].deleteKey();
		array[probe].deleteRecord();
		count--;
		return r;
	}
	else {
		return ChainedScatterObject(); //return NULL;
	}
}
