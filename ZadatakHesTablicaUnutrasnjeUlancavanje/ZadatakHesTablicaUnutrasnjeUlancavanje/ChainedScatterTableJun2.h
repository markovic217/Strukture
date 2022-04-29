#pragma once
#include "ChainedScatterTable.h"
class ChainedScatterTableJun2 : public ChainedScatterTable {
public:
	ChainedScatterObjectJun2* array;
	ChainedScatterTableJun2(unsigned int length);
	void insert2(ChainedScatterObjectJun2 obj);
};