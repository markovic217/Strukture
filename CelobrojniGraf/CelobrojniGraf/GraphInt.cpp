#include "GraphInt.h"

#include <iostream>
using namespace std;

#include "QueueAsArrayInt.h"
#include "StackAsArrayInt.h"

GraphAsListsInt::GraphAsListsInt() : start(nullptr), nodeNum()
{
}

GraphAsListsInt::~GraphAsListsInt()
{
	cout << "Not implemented!" << endl;
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
	pSrc->adj = new LinkedEdgeInt(pDest, weight, pSrc->adj);
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
	LinkedNodeInt* node = start;
	LinkedNodeInt* s = NULL, * l1 = NULL, * l2 = NULL;
	LinkedNodeInt* st = NULL;
	bool postoji1 = false, postoji2 = false;
	int duzina1, duzina2;
	setStatusForAllNodes(1);
	QueueAsArrayLinkedNodeInt queue(nodeNum);
	while (node != NULL) {
		node->setStepen(100);
		if (dataFirst == node->node)
			st = node;
		if (dataLast1 == node->node)
			l1 = node;
		if (dataLast2 == node->node)
			l2 = node;
		node = node->next;
	}
	if (st == NULL or l1 == NULL or l2 == NULL)
		return false;
	LinkedEdgeInt* edge;
	st->stepen = 0;
	queue.enqueue(st);
	while (!queue.isEmpty()) {
		node = queue.dequeue();
		edge = node->adj;
		node->status = 3;
		while (edge != NULL) {
			if ((edge->weight + node->stepen) <= edge->dest->stepen) {
				edge->dest->stepen = edge->weight + node->stepen;
				edge->dest->parentEdge = edge;
				edge->dest->parentNode = node;
			}
			if (edge->dest->status == 1)
			{
				edge->dest->status = 2;
				queue.enqueue(edge->dest);
			}
			edge = edge->link;
		}
	}
	LinkedNodeInt* pom = l1->parentNode;
	while(pom != NULL){
		if (pom->parentNode == st) {
			postoji1 = true; 
			break;
		}
			pom = pom->parentNode;
		}
	pom = l2->parentNode;
	while (pom != NULL){
		if (pom->parentNode == st) {
			postoji2 = true;
			break;
		}
			pom = pom->parentNode;
		}
	cout << endl;
	return true;
}

void GraphAsListsInt::Dijsktra(int data)
{
	LinkedNodeInt* node = start, *n = NULL;
	while (node != NULL) {
		node->setStepen(100);
		if (data == node->node)
			n = node;
		node = node->next;
	}
	if (n == NULL)
		return;
	n->setStepen(0);
	LinkedEdgeInt* edge = n->adj;
	while (edge != NULL) {
		edge->dest->setStepen(edge->weight + n->getStepen());
		edge = edge->link;
	}
	n = n->next;
	edge = n->adj;
	while (n != NULL) {
		while (edge != NULL)
			if ((edge->weight + n->getStepen()) <= edge->dest->getStepen()) {
				edge->dest->setStepen(edge->weight+ n->getStepen());
				edge = edge->link;
			}
		n = n->next;
		if(n!=NULL)
		edge = n->adj;
	}
}

void GraphAsListsInt::Dijsktra(LinkedNodeInt* s)
{
	QueueAsArrayLinkedNodeInt queue(nodeNum);
	LinkedNodeInt* node = start, * n = NULL;
	while (node != NULL) {
		if (s == node)
			node->setStepen(0);
		else
			node->setStepen(100);
		node = node->next;
	}
	if (n == NULL)
		return;
	n->setStepen(0);
	LinkedEdgeInt* edge = n->adj;
	while (edge != NULL) {
		edge->dest->setStepen(edge->weight + n->getStepen());
		edge = edge->link;
	}
	n = n->next;
	edge = n->adj;
	while (n != NULL) {
		while (edge != NULL)
			if ((edge->weight + n->getStepen()) <= edge->dest->getStepen()) {
				edge->dest->setStepen(edge->weight + n->getStepen());
				edge = edge->link;
			}
		n = n->next;
		if (n != NULL)
			edge = n->adj;
	}
}