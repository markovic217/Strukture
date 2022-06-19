#pragma once
#include <iostream>
using namespace std;
class HashObject
{
private:
	char* key;
	char* record;
public:
	HashObject();
	HashObject(char* k, char* v);
	HashObject(HashObject const& obj);
	~HashObject();
	HashObject& operator = (HashObject const& obj);
	bool operator == (HashObject const& obj);
	void deleteRecord();
	void deleteKey();
	char* getKey() { return key; }
	char* getRecord() { return record; }
	void setRecord(char* r) {
		record = new char[strlen(r) + 1];
		strcpy(record, r);
	}
	bool isEqualKey(char* k) { return strcmp(key,k)==0; }
	void print();
};