#pragma once
#include "SparseMatrixCell.h"
class SparseMatrix {
public:
	int length;
	int count;
	SparseMatrixCell* compactMatrix;
	SparseMatrix() {
		length = 5;
		count = 0;
		compactMatrix = new SparseMatrixCell[length];
	}
	SparseMatrix(int l) {
		count = 0;
		length = l;
		compactMatrix = new SparseMatrixCell[length];
	}
	void addMatrix(int** matrix) {
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (matrix[i][j] != 0) {
					compactMatrix[count] = SparseMatrixCell(i, j, matrix[i][j]);
					count++;
				}
	}
};