#include"ChainedScatterTable.h"

void main()
{
	ChainedScatterTable tablica(64);
	ChainedScatterObject o("290792051", "Nikola Davidovic");
	//tablica.insert(o);
	ChainedScatterObject o1("270698051", "Pera Peric");
	ChainedScatterObject o2("290792051", "Nikola Davidovic");
	tablica.insert(o2);
	tablica.insert(ChainedScatterObject("290792053", "asdfg"));
	tablica.insert(o1);
	tablica.insert(o1);
	tablica.insert(ChainedScatterObject("290792052", "asd"));
	tablica.print();
	//ChainedScatterObject o3 = tablica.withdraw("290792051");
	//o3.print();
	//o3 = tablica.withdraw("290792051");
	//o3.print();
	//o3 = tablica.withdraw("290792051");
	//o3.print();
	ChainedScatterObject pom;
	ChainedScatterObject c1 = tablica.find("290792053");
	ChainedScatterObject c2 =tablica.find("290792052");
	cout << c1.getRecord() << endl;
	cout << c2.getRecord() << endl;
	pom.setRecord(c1.getRecord());
	c1.setRecord(c2.getRecord());
	c2.setRecord(pom.getRecord());
	cout << c1.getRecord() << endl;
	cout << c2.getRecord() << endl;

	//tablica.print();
}