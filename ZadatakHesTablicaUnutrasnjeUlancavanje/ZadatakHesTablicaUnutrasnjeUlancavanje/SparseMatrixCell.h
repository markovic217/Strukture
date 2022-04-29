#pragma once

class SparseMatrixCell {
public:
	int i;
	int j;
	int value;
	SparseMatrixCell(int i, int j, int value) {
		this->i = i;
		this->j = j;
		this->value = value;
	}
	SparseMatrixCell() {

	}
};
