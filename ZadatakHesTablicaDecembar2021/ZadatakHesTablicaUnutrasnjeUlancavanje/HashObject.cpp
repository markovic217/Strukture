#include "HashObject.h"
using namespace std;
HashObject::HashObject()
{
	key = NULL;
	record = NULL;
}

HashObject::HashObject(char* k, char* v, int ko)
{
	key = new char[strlen(k) + 1];
	strcpy(key, k);
	record = new char[strlen(v) + 1];
	strcpy(record, v);
	kolicina = ko;
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
	record = strcpy(new char[strlen(obj.record) + 1], obj.record);
	kolicina = obj.kolicina;
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
		record = new char[strlen(obj.record) + 1];
		strcpy(record, obj.record);
		kolicina = obj.kolicina;
	}
	return *this;
}

bool HashObject::operator == (HashObject const& obj)
{
	return (strcmp(this->key, obj.key) == 0) && (strcmp(this->record, obj.record) == 0) && kolicina == obj.kolicina;
}

void HashObject::deleteRecord() {
	if (record) { delete record; record = NULL; } 
}

void HashObject::deleteKey() {
	if (key) { delete key; key = NULL; }
}

void HashObject::print()
{
	if(key!=NULL)
	{ 
		cout << key;
	}
	if (record != NULL)
	{
		cout << "|" << record;
	}
	cout << "|" << kolicina;
	cout << endl;
}