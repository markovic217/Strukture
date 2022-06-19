#pragma once

#include "LinkedEdgeInt.h"

class LinkedNodeInt
{
public:
	int node;
	LinkedEdgeInt* adj;
	LinkedNodeInt* next;
	int status;
	bool ubrojen;
	int duzina;
	int statusRacva;
	bool stanica;
	LinkedNodeInt* prev;

	LinkedNodeInt();
	LinkedNodeInt(int nodeN);
	LinkedNodeInt(int nodeN, LinkedEdgeInt* adjN, LinkedNodeInt* nextN);
	LinkedNodeInt(int nodeN, LinkedEdgeInt* adjN, LinkedNodeInt* nextN, int statusN);

	void visit();
};
