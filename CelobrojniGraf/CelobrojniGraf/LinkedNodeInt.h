#pragma once

#include "LinkedEdgeInt.h"

class LinkedNodeInt
{
public:
	int node;
	LinkedEdgeInt* adj;
	LinkedNodeInt* next;
	LinkedEdgeInt* parentEdge;
	LinkedNodeInt* parentNode;
	int status;
	int duzina;
	int stepen;
	LinkedNodeInt* prev;

	LinkedNodeInt();
	LinkedNodeInt(int nodeN);
	LinkedNodeInt(int nodeN, LinkedEdgeInt* adjN, LinkedNodeInt* nextN);
	LinkedNodeInt(int nodeN, LinkedEdgeInt* adjN, LinkedNodeInt* nextN, int statusN);
	int getStepen() {
		return stepen;
	}
	void setStepen(int s) {
		stepen = s;
	}
	void visit();
};
