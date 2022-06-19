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
	g.insertNode(7);
	g.insertNode(8);
	g.insertNode(9);
	g.insertNode(10);
	g.insertNode(11);
	g.insertNode(12);
	g.insertEdge(1, 2);
	g.insertEdge(1, 3);
	g.insertEdge(1, 4);
	g.insertEdge(2, 8);
	g.insertEdge(3, 5);
	g.insertEdge(4, 6);
	g.insertEdge(6, 5);
	g.insertEdge(6, 7);
	g.insertEdge(6, 9);
	g.insertEdge(7, 10);
	g.insertEdge(9, 10);
	g.insertEdge(5, 11);
	g.insertEdge(8, 11);
	g.insertEdge(11, 7);
	g.insertEdge(11, 12);
	g.insertEdge(6, 3);
	g.insertEdge(5, 2);
	//cout << g.stanice(1, 11, 100) << endl;
	cout << g.reachableInNHoops(1, 5) << endl;
	GraphAsListsInt zamak;
	zamak.insertNode(1);
	zamak.insertNode(2);
	zamak.insertNode(3);
	zamak.insertNode(4);
	zamak.insertNode(5);
	zamak.insertNode(6);
	zamak.insertNode(7);
	zamak.insertNode(8);
	zamak.insertNode(9);
	zamak.insertEdge(1, 2);
	zamak.insertEdge(1, 3);
	zamak.insertEdge(2, 4);
	zamak.insertEdge(2, 3);
	zamak.insertEdge(3, 9);
	zamak.insertEdge(4, 5);
	zamak.insertEdge(5, 6);
	zamak.insertEdge(5, 7);
	zamak.insertEdge(6, 8);
	zamak.zamak(new LinkedNodeInt(1));
	GraphAsListsInt r;
	r.insertNode(1);
	r.insertNode(2);
	r.insertNode(3);
	r.insertNode(4);
	r.insertEdge(1,3);
	r.insertEdge(1, 2);
	r.insertEdge(3, 2);
	r.insertEdge(2, 4);
	cout << endl;
	cout << r.reachableInNHoops(1, 2);
}

