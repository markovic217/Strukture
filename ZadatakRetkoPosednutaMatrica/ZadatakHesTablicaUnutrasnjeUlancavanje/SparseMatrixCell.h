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
		i = 0;
		j = 0;
		value = 0;
	}
};
