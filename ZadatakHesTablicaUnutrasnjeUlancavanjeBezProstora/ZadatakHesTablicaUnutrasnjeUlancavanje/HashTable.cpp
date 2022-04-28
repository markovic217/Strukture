#include"HashTable.h"

unsigned int HashTable::h(char* key)
{
	return g(f(key));
}

int toNum(char ch) {
	return ch - '0';
}

unsigned int HashTable::f(char* key)
{
	//TODO:Implementirati funkciju koja prevodi char u unsigned int
	/*unsigned int h = 0;
	for (int i = 0; i < strlen(key); i++)
		h += key[i];
	return h;*/

	//Kolokvijum 2021
	unsigned int a = toNum(key[0]) * 100 + toNum(key[1]) * 10 + toNum(key[2]);
	unsigned int b = toNum(key[3]) * 100 + toNum(key[4]) * 10 + toNum(key[5]);
	return a + b;
}


unsigned int HashTable::g(unsigned int key)
{
	//TODO:Implementirati funkciju koja prevodi unsigned int u [0...M-1]
	return key%m;
}


