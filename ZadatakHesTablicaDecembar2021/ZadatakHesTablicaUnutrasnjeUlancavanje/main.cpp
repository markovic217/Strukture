#include"ChainedScatterTable.h"

void main()
{
	ChainedScatterTable tablica(64);
	ChainedScatterObject o("290792051", "Nikola Davidovic");
	tablica.insert(o);
	ChainedScatterObject o1("270698051", "Pera Peric");
	ChainedScatterObject o2("290792051", "Nikola Davidovic");
	tablica.insert(o2);
	tablica.insert(o2);
	tablica.insert(o1);
	tablica.insert(o1);
	tablica.insert(o2);
	tablica.print();
	ChainedScatterObject o3 = tablica.withdraw("290792051");
	o3.print();
	o3 = tablica.withdraw("290792051");
	o3.print();
	o3 = tablica.withdraw("290792051");
	o3.print();
	tablica.print();
}