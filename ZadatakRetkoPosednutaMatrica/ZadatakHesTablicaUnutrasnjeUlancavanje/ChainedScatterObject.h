#pragma once
#include "ScatterObject.h"
class ChainedScatterObject :
	public ScatterObject
{
public:
	unsigned int next;
public:
	ChainedScatterObject() : ScatterObject() { next = -1; }
	ChainedScatterObject(char *k, SparseMatrixCell *v): ScatterObject(k,v) { next = -1; }
	ChainedScatterObject(char *k, SparseMatrixCell *v, unsigned int n) : ScatterObject(k, v) { next = n; }
	ChainedScatterObject(ChainedScatterObject const& obj);
	ChainedScatterObject& operator = (ChainedScatterObject const& obj);
	void print();
};

