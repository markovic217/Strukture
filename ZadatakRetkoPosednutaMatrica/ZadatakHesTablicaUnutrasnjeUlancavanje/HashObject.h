#pragma once
#include <iostream>
#include "SparseMatrixCell.h"
using namespace std;
class HashObject
{
protected:
	char* key;
	SparseMatrixCell* record;
public:
	HashObject();
	HashObject(char* k, SparseMatrixCell* v);
	HashObject(HashObject const& obj);
	~HashObject();
	HashObject& operator = (HashObject const& obj);
	bool operator == (HashObject const& obj);
	void deleteRecord();
	char* getKey() { return key; }
	SparseMatrixCell* getRecord() { return record; }
	bool isEqualKey(char* k) { return strcmp(key,k)==0; }
	void print();
};