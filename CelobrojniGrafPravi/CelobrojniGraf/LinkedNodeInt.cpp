#include <iostream>
using namespace std;

#include "LinkedNodeInt.h"

LinkedNodeInt::LinkedNodeInt()
	: node(), adj(nullptr), next(nullptr), status(), duzina(), prev(nullptr)

{
	ubrojen = false;
	statusRacva = 0;
}

LinkedNodeInt::LinkedNodeInt(int nodeN)
	: node(nodeN), adj(nullptr), next(nullptr), status(), duzina(), prev(nullptr)
{
	ubrojen = false;
	statusRacva = 0;
}

LinkedNodeInt::LinkedNodeInt(int nodeN, LinkedEdgeInt* adjN, LinkedNodeInt* nextN)
	: node(nodeN), adj(adjN), next(nextN), status(), duzina(), prev(nullptr)
{
	ubrojen = false;
	statusRacva = 0;
}

LinkedNodeInt::LinkedNodeInt(int nodeN, LinkedEdgeInt* adjN, LinkedNodeInt* nextN, int statusN)
	: node(nodeN), adj(adjN), next(nextN), status(statusN), duzina(), prev(nullptr)
{
	ubrojen = false;
	statusRacva = 0;
}

void LinkedNodeInt::visit()
{
	cout << node << " ";
}
