#include <iostream>
using namespace std;

#include "GraphInt.h"

int main(int argc, char* argv[]) 
{
	GraphAsListsInt g;
	g.insertNode(1);
	g.insertNode(2);
	g.insertNode(3);
	g.insertNode(4);
	g.insertNode(5);
	g.insertNode(6);
	g.insertEdge(1, 2, 8);
	g.insertEdge(1, 3, 2);
	g.insertEdge(1, 4, 4);
	g.insertEdge(2, 1, 8);
	g.insertEdge(2, 3, 7);
	g.insertEdge(2, 5, 2);
	g.insertEdge(3, 1, 2);
	g.insertEdge(3, 2, 7);
	g.insertEdge(3, 4, 1);
	g.insertEdge(3, 5, 3);
	g.insertEdge(3, 6, 9);
	g.insertEdge(4, 1, 4);
	g.insertEdge(4, 3, 1);
	g.insertEdge(4, 6, 5);
	g.insertEdge(5, 2, 2);
	g.insertEdge(5, 3, 3);
	g.insertEdge(6, 3, 9);
	g.insertEdge(6, 4, 5);
	g.pathToCloserOfTwoNodes(1, 2, 6);

}

