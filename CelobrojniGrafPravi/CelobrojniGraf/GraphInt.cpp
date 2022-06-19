#include "GraphInt.h"

#include <iostream>
using namespace std;

#include "QueueAsArrayInt.h"
#include "StackAsArrayInt.h"
#include "Stack.h"
GraphAsListsInt::GraphAsListsInt() : start(nullptr), nodeNum()
{
}

GraphAsListsInt::~GraphAsListsInt()
{
	//cout << "Not implemented!" << endl;
}

LinkedNodeInt* GraphAsListsInt::findNode(const int& data) const
{
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr && ptr->node != data)
		ptr = ptr->next;
	return ptr;
}

LinkedEdgeInt* GraphAsListsInt::findEdge(const int& dataSrc, const int& dataDest) const
{
	LinkedNodeInt* ptr = findNode(dataSrc);
	if (ptr == nullptr)
		return nullptr;
	LinkedEdgeInt* pEdge = ptr->adj;
	while (pEdge != nullptr && pEdge->dest->node != dataDest)
		pEdge = pEdge->link;
	return pEdge;
}

void GraphAsListsInt::insertNode(const int& data)
{
	start = new LinkedNodeInt(data, nullptr, start);
	nodeNum++;
}

bool GraphAsListsInt::insertEdge(const int& dataSrc, const int& dataDest, const double& weight /*= 0*/)
{
	LinkedNodeInt* pSrc = nullptr;
	LinkedNodeInt* pDest = nullptr;
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr && (pSrc == nullptr || pDest == nullptr)) {
		if (ptr->node == dataSrc) {
			pSrc = ptr;
		}
		else if (ptr->node == dataDest) {
			pDest = ptr;
		}
		ptr = ptr->next;
	}
	if (pSrc == nullptr || pDest == nullptr)
		return false;
	pSrc->adj = new LinkedEdgeInt(pDest, pSrc->adj);
	return true;
}

bool GraphAsListsInt::deleteEdge(const int& dataSrc, const int& dataDest)
{
	LinkedNodeInt* pSrc = findNode(dataSrc);
	if (pSrc == nullptr)
		return false;

	LinkedEdgeInt* pEdgePrev = nullptr;
	LinkedEdgeInt* pEdge = pSrc->adj;
	while (pEdge != nullptr && pEdge->dest->node != dataDest) {
		pEdgePrev = pEdge;
		pEdge = pEdge->link;
	}
	if (pEdge == nullptr)
		return false;

	if (pEdgePrev == nullptr)
		pSrc->adj = pEdge->link;
	else
		pEdgePrev->link = pEdge->link;

	delete pEdge;

	return true;
}

void GraphAsListsInt::deleteEdgeToNode(const LinkedNodeInt* pDest)
{
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr)
	{
		LinkedEdgeInt* pEdgePrev = nullptr;
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr && pEdge->dest != pDest) {
			pEdgePrev = pEdge;
			pEdge = pEdge->link;
		}
		if (pEdge != nullptr)
		{
			if (pEdgePrev == nullptr)
				ptr->adj = pEdge->link;
			else
				pEdgePrev->link = pEdge->link;
		}
		ptr = ptr->next;
	}
}

bool GraphAsListsInt::deleteNode(const int& data)
{
	LinkedNodeInt* prev = nullptr;
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr && ptr->node != data) {
		prev = ptr;
		ptr = ptr->next;
	}
	if (ptr == nullptr)
		return false;

	LinkedEdgeInt* pEdge = ptr->adj;
	while (pEdge != nullptr) {
		LinkedEdgeInt* pEdgeTmp = pEdge->link;
		delete pEdge;
		pEdge = pEdgeTmp;
	}
	ptr->adj = nullptr;

	deleteEdgeToNode(ptr);

	if (prev == nullptr)
		start = start->next;
	else
		prev->next = ptr->next;

	delete ptr;
	nodeNum--;

	return true;
}

void GraphAsListsInt::print() const
{
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr)
	{
		cout << ptr->node << " -> ";
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			cout << pEdge->dest->node << " | ";
			pEdge = pEdge->link;
		}
		cout << endl;
		ptr = ptr->next;
	}
}

void GraphAsListsInt::setStatusForAllNodes(int status) const
{
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr) {
		ptr->status = status;
		ptr = ptr->next;
	}
}

long GraphAsListsInt::breadthFirstTraversal(const int& data) const
{
	long retVal = 0;

	LinkedNodeInt* ptr = findNode(data);
	if (ptr == nullptr)
		return 0;

	setStatusForAllNodes(1);

	QueueAsArrayLinkedNodeInt queue(nodeNum);
	queue.enqueue(ptr);
	ptr->status = 2;
	while (!queue.isEmpty()) {
		ptr = queue.dequeue();
		ptr->status = 3;
		ptr->visit();
		retVal += 1;
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			if (pEdge->dest->status == 1) {
				queue.enqueue(pEdge->dest);
				pEdge->dest->status = 2;
			}
			pEdge = pEdge->link;
		}
	}
	cout << endl;
	return retVal;
}

long GraphAsListsInt::depthFirstTraversalIterative(const int& data) const
{
	long retVal = 0;

	LinkedNodeInt* ptr = findNode(data);
	if (ptr == nullptr)
		return 0;

	setStatusForAllNodes(1);

	StackAsArrayLinkedNodeInt stack(nodeNum);
	stack.push(ptr);
	ptr->status = 2;
	while (!stack.isEmpty()) {
		ptr = stack.pop();
		ptr->status = 3;
		ptr->visit();
		retVal += 1;
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			if (pEdge->dest->status == 1) {
				stack.push(pEdge->dest);
				pEdge->dest->status = 2;
			}
			pEdge = pEdge->link;
		}
	}
	cout << endl;
	return retVal;
}

long GraphAsListsInt::depthFirstTraversalRecursive(LinkedNodeInt* ptr) const
{
	int retVal = 0;
	if (ptr->status != 1) {
		ptr->visit();
		ptr->status = 1;
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			retVal += depthFirstTraversalRecursive(pEdge->dest);
			pEdge = pEdge->link;
		}
		retVal++;
	}
	return retVal;
}

long GraphAsListsInt::depthFirstTraversalRecursive(const int& data) const
{
	LinkedNodeInt* pNode = nullptr;
	LinkedNodeInt* ptr = start;
	while (ptr != nullptr) {
		ptr->status = 0;
		if (ptr->node == data) {
			pNode = ptr;
		}
		ptr = ptr->next;
	}

	if (pNode == nullptr)
		return 0;

	return depthFirstTraversalRecursive(pNode);
}

long GraphAsListsInt::topologicalOrderTravrsal() const
{
	int retVal = 0;

	setStatusForAllNodes(0);

	LinkedNodeInt* ptr = start;
	while (ptr != nullptr) {
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			pEdge->dest->status += 1;
			pEdge = pEdge->link;
		}
		ptr = ptr->next;
	}

	QueueAsArrayLinkedNodeInt queue(nodeNum);
	ptr = start;
	while (ptr != nullptr) {
		if (ptr->status == 0)
			queue.enqueue(ptr);
		ptr = ptr->next;
	}

	while (!queue.isEmpty()) {
		ptr = queue.dequeue();
		ptr->visit();
		retVal += 1;
		LinkedEdgeInt* pEdge = ptr->adj;
		while (pEdge != nullptr) {
			pEdge->dest->status--;
			if (pEdge->dest->status == 0)
				queue.enqueue(pEdge->dest);
			pEdge = pEdge->link;
		}
	}
	cout << endl;
	return retVal;
}

// TODO: Realizovati metod koji vraca da li postoji i odredjuje put u grafu od zadatog pocetnog cvora do blizeg (broj potega na putu) od dva zadata krajnja cvora.
bool GraphAsListsInt::pathToCloserOfTwoNodes(int dataFirst, int dataLast1, int dataLast2)
{
	LinkedNodeInt* first= NULL, * last1, * last2, *s = start;
	while (s != NULL) {
		if (s->node == dataFirst)
			first = s;
		if (s->node == dataLast1)
			last1 = s;
		if (s->node == dataLast2)
			last2 = s;
		s = s->next;
	}
	setStatusForAllNodes(1);
	QueueAsArrayLinkedNodeInt queue(nodeNum);
	LinkedEdgeInt* edge;
	int sused = 1;
	int put1 = 0, put2 = 0;
	queue.enqueue(first);
	while (!queue.isEmpty()) {
		s = queue.dequeue();
		edge = s->adj;
		s->status = 3;
		sused--;
		while (edge != NULL) {
			if (sused == 0) {
				put1++;
			}
			if (edge->dest->status == 1)
			{
				queue.enqueue(edge->dest);
				edge->dest->status = 2;
				sused++;
			}
			edge = edge->link;
		}
	}
	return false;
}

//Kolokvijum 2

int GraphAsListsInt::stanice(int a, int b, int duzina){
	LinkedNodeInt* start, *finish, *node;
	LinkedEdgeInt* edge;
	start = findNode(a);
	finish = findNode(b);
	setStatusForAllNodes(1);
	node = start;
	QueueAsArrayLinkedNodeInt q(nodeNum);
	q.enqueue(start);
	int num = 0;
	while (!q.isEmpty()) {
		node = q.dequeue();
		node->status = 3;
		edge = node->adj;
		if (node == finish)
			break;
		while (edge != NULL) {
			if (edge->dest->status == 1) {
				edge->dest->prev = node;
				edge->dest->status = 2;
				q.enqueue(edge->dest);
			}
			edge = edge->link;
		}
	}
	if (node != finish)
		return 0;
	while (node != start) {
		node->visit();
		node = node->prev;
		num++;
	}
	return num;
}

int GraphAsListsInt::najkraciputBFS(int firstData, int secondData)
{
	LinkedNodeInt* tmpNode = start;
	LinkedNodeInt* firstNode = nullptr, * secondNode = nullptr;
	while (tmpNode != nullptr)
	{
		//da ne bi koristili find node i prolazili vise nego sto treba
		if (firstNode == nullptr && tmpNode->node == firstData)  //ako je nullptr i info trenutnog odgovara
			firstNode = tmpNode;
		if (secondNode == nullptr && tmpNode->node == secondData)
			secondNode = tmpNode;
		tmpNode->status = 0;//neobradjen;
		tmpNode->prev = nullptr;
		tmpNode = tmpNode->next;
	}
	if (firstNode == nullptr || secondNode == nullptr)
		return 0;
	tmpNode = firstNode;
	QueueAsArrayLinkedNodeInt queue(nodeNum);
	queue.enqueue(tmpNode);
	tmpNode->status = 1;//obradjuje se
	while (!queue.isEmpty())
	{
		tmpNode = queue.dequeue();
		tmpNode->status = 2;//obradjen 
		if (tmpNode == secondNode) //nadjen je i izlazi
			break;
		LinkedEdgeInt* pot = tmpNode->adj;
		while (pot != nullptr)
		{
			if (pot->dest->status == 0)
			{
				queue.enqueue(pot->dest);
				pot->dest->status = 1;
				pot->dest->prev = tmpNode; //!!!!!!!!!!!!!!!!!!!!!!!!
			}
			pot = pot->link;
		}
	}
	if (tmpNode != secondNode)
		return -1;//nije nadjen put

	int length = 0;
	while (tmpNode != nullptr)
	{
		tmpNode->visit();
		tmpNode = tmpNode->prev;
		length++;
	}
	return length;
}


int GraphAsListsInt::reachableInNHoops(int node, int num) {
	setStatusForAllNodes(0);
	LinkedNodeInt* n = start;
	while (n != NULL) {
		if (n->node == node)
			break;
		n = n->next;
	}
	LinkedNodeInt* pom = n;
	LinkedEdgeInt* edge;
	StackAsArrayLinkedNodeInt q(nodeNum*3);
	Stack s(nodeNum*3);
	int br = 0;
	int nums = 0;
	q.push(n);
	s.push(br);
	while (!q.isEmpty()) {
		n = q.pop();
		br = s.pop();
		edge = n->adj;
		while (edge != NULL) {
			if ((br + 1) == num && !edge->dest->ubrojen)
			{
				edge->dest->ubrojen = true;
				cout << edge->dest->node << " ";
				nums++;
			}
			else {
				q.push(edge->dest);
				s.push(br+1);
			}
			edge = edge->link;
		}
		br++;
	}
	cout << endl;
	return nums;
}

void GraphAsListsInt::zamak(LinkedNodeInt* start)
{
	StackAsArrayLinkedNodeInt s(nodeNum);
	setStatusForAllNodes(0);
	LinkedNodeInt* node = this->start;
	LinkedEdgeInt* edge;
	int br = 0;
	while (node != NULL) {
		edge = node->adj;
		while (edge != NULL) {
			edge->dest->status++;
			edge = edge->link;
			br++;
		}
		if(br != 0)
			node->statusRacva = br - 1;
		node = node->next;
		br = 0;
	}

	s.push(findNode(start->node));
	bool prazan = false;
	while (!s.isEmpty()) {
		if (s.getTop()->adj == NULL)
			prazan = true;
		else
			prazan = false;
		node = s.pop();
		node->visit();
		edge = node->adj;
		if (prazan && !s.isEmpty())
		{
			while (node->statusRacva == 0)
			{
				node = node->prev;
				node->visit();
			}
			node->statusRacva--;
		}		
		while (edge != NULL) {
			if (--edge->dest->status == 0) {
				edge->dest->prev = node;
				s.push(edge->dest);
			}
			edge = edge->link;
		}
	}
}