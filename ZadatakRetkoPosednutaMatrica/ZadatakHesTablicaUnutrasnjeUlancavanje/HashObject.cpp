#include "HashObject.h"
using namespace std;
HashObject::HashObject()
{
	key = NULL;
	record = NULL;
}

HashObject::HashObject(char* k, SparseMatrixCell* v)
{
	key = new char[strlen(k) + 1];
	strcpy(key, k);
	record = v;
}

HashObject::~HashObject()
{
	if (key)
		delete[] key;
	if (record)
		delete[] record;
}

HashObject::HashObject(HashObject const& obj)
{
	key = strcpy(new char[strlen(obj.key) + 1], obj.key);
	record = obj.record;
}

HashObject& HashObject::operator = (HashObject const& obj)
{
	if (this != &obj)
	{
		if (key)
			delete key;
		key = new char[strlen(obj.key) + 1];
		strcpy(key, obj.key);
		if (record)
			delete record;
		record = obj.record;
	}
	return *this;
}

bool HashObject::operator == (HashObject const& obj)
{
	return (strcmp(this->key, obj.key) == 0) && (this->record == obj.record);
}

void HashObject::deleteRecord() {
	if (record) { delete record; record = NULL; } 
}

void HashObject::print()
{
	if(key!=NULL)
	{ 
		cout << key;
	}
	if (record != NULL)
	{
		cout << "|" << record->i << " " << record->j << " " << record->value;
	}
	cout << endl;
}