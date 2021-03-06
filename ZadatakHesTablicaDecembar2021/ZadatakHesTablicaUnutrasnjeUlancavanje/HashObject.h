#pragma once
#include <iostream>
using namespace std;
class HashObject
{
private:
	char* key;
	char* record;
	int kolicina;
public:
	HashObject();
	HashObject(char* k, char* v, int ko);
	HashObject(HashObject const& obj);
	~HashObject();
	HashObject& operator = (HashObject const& obj);
	bool operator == (HashObject const& obj);
	void deleteRecord();
	void deleteKey();
	char* getKey() { return key; }
	char* getRecord() { return record; }
	int getKolicna() { return kolicina; }
	bool isEqualKey(char* k) { return strcmp(key,k)==0; }
	void print();
};