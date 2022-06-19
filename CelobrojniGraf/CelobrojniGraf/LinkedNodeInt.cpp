#include <iostream>
using namespace std;

#include "LinkedNodeInt.h"

LinkedNodeInt::LinkedNodeInt()
	: node(), adj(nullptr), next(nullptr), status(), duzina(), prev(nullptr), parentEdge(NULL), parentNode(NULL), stepen()

{

}

LinkedNodeInt::LinkedNodeInt(int nodeN)
	: node(nodeN), adj(nullptr), next(nullptr), status(), duzina(), prev(nullptr), parentEdge(NULL), parentNode(NULL), stepen()
{

}

LinkedNodeInt::LinkedNodeInt(int nodeN, LinkedEdgeInt* adjN, LinkedNodeInt* nextN)
	: node(nodeN), adj(adjN), next(nextN), status(), duzina(), prev(nullptr), parentEdge(NULL), parentNode(NULL), stepen()
{

}

LinkedNodeInt::LinkedNodeInt(int nodeN, LinkedEdgeInt* adjN, LinkedNodeInt* nextN, int statusN)
	: node(nodeN), adj(adjN), next(nextN), status(statusN), duzina(), prev(nullptr), parentEdge(NULL), parentNode(NULL), stepen()
{

}

void LinkedNodeInt::visit()
{
	cout << node << " ";
}
