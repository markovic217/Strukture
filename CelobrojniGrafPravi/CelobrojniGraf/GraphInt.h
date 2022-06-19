#pragma once

//#include "LinkedEdgeInt.h"
#include "LinkedNodeInt.h"
#include "QueueAsArrayInt.h"
#include "StackAsArrayInt.h"
class GraphAsListsInt
{
protected:
	LinkedNodeInt* start;
	long nodeNum;
public:
	GraphAsListsInt();
	~GraphAsListsInt();

	LinkedNodeInt* findNode(const int& data) const;
	LinkedEdgeInt* findEdge(const int& dataSrc, const int& dataDest) const;

	void insertNode(const int& data);
	//void insertNode(const int& data);
	bool insertEdge(const int& dataSrc, const int& dataDest, const double& weight = 0);

private:
	void deleteEdgeToNode(const LinkedNodeInt* pDest);
public:
	bool deleteEdge(const int& dataSrc, const int& dataDest);
	bool deleteNode(const int& data);

	void print() const;

private:
	void setStatusForAllNodes(int status) const;
public:
	long breadthFirstTraversal(const int& data) const;
	long depthFirstTraversalIterative(const int& data) const;
private:
	long depthFirstTraversalRecursive(LinkedNodeInt* ptr) const;
public:
	long depthFirstTraversalRecursive(const int& data) const;

	long topologicalOrderTravrsal() const;

	bool pathToCloserOfTwoNodes(int dataFirst, int dataLast1, int dataLast2);

	int stanice(int a, int b, int duzina);

	int reachableInNHoops(int, int);
	int najkraciputBFS(int firstData, int secondData);
	void zamak(LinkedNodeInt*);

	int reachableInNHoopsm(LinkedNodeInt* a, int n)
	{
		int num = 0;
		if (start == nullptr)
			return num;
		LinkedNodeInt* tmp = start;
		while (tmp->node != a->node)
			tmp = tmp->next;
		if (tmp == nullptr)
			return num;
		QueueAsArrayLinkedNodeInt* queue = new 	QueueAsArrayLinkedNodeInt(nodeNum * 2);
		queue->enqueue(tmp);
		int i = 0;
		int lim = 1;
		while (i < n)
		{
			int number = 0;
			for (int j = 0; j < lim; j++)
			{
				tmp = queue->dequeue();
				LinkedEdgeInt* edge = tmp->adj;
				while (edge != nullptr)
				{
					queue->enqueue(edge->dest);
					edge = edge->link;
					number++;
				}
			}
			i++;
			lim = number;
		}
		int pos = 0;

		//queue->removeDuplicates();
		while (!queue->isEmpty())
		{
			queue->dequeue();
			num++;
		}

		return num;
	}
};

