#pragma once
#include "ScatterObject.h"
class ChainedScatterObject :
	public ScatterObject
{
public:
	int next;
public:
	ChainedScatterObject() : ScatterObject() { next = -1; }
	ChainedScatterObject(char *k, char *v, int ko): ScatterObject(k,v, ko) { next = -1; }
	ChainedScatterObject(char *k, char *v, int ko, unsigned int n) : ScatterObject(k, v, ko) { next = n; }
	ChainedScatterObject(ChainedScatterObject const& obj);
	ChainedScatterObject& operator = (ChainedScatterObject const& obj);
	void print();
};

