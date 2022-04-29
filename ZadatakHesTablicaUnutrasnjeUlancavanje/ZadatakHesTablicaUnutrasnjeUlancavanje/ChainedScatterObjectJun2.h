#pragma once
#include "ChainedScatterObject.h"
#include "SparseMatrix.h"
class ChainedScatterObjectJun2 : public ChainedScatterObject{
protected:
	SparseMatrixCell* elements;
};