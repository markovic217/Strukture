#include "ChainedScatterTableJun2.h"
#include "ChainedScatterObjectJun2.h"

ChainedScatterTableJun2::ChainedScatterTableJun2(unsigned int length){
	m = length;
	count = 0;
	lrmp = m;
	array = new ChainedScatterObjectJun2[3 * m];
	for (int i = m; i < 3 * m - 1; i++)
	{
		array[i].next = i + 1;
	}
	array[3 * m - 1].next = 0;
}

void ChainedScatterTableJun2::insert2(ChainedScatterObjectJun2 obj)
{
	if (count == m)
		throw new exception("Tablica je puna!");
	unsigned int probe = h(obj.getKey());
	if (array[probe].status == 2)
	{
		while (array[probe].status == 2 && array[probe].next != -1 && array[probe].next != 0)
		{
			probe = array[probe].next;
		}
		if (array[probe].next == 0)
			throw new exception("Izdvojeni prostor za sinonime je pun!");
		array[probe].next = lrmp;
		probe = lrmp;
		lrmp = array[probe].next;
	}
	array[probe] = obj;
	array[probe].status = 2; // zauzet
	array[probe].next = -1;
	count++;
}