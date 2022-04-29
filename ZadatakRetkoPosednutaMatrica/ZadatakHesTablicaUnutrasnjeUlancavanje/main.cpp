#include"ChainedScatterTable.h"

void main()
{
	ChainedScatterTable tablica(64);
	ChainedScatterObject o("Nikola Davidovic", new SparseMatrixCell(0,0,10));
	tablica.insert(o);
	ChainedScatterObject o1("Nikola Davidovic", new SparseMatrixCell(1, 0, 12));
	ChainedScatterObject o2("Nikola Davidovic", new SparseMatrixCell(2, 0, 11));
	tablica.insert(o2);
	tablica.insert(o2);
	tablica.insert(o1);
	tablica.insert(o1);
	tablica.insert(o2);
	tablica.print();
}