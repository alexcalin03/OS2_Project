#include "matrix.h"
#include <iostream>
#include <random>


Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols), data_(rows, std::vector<int>(cols)) {}

void Matrix::fillRandom() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            data_[i][j] = dis(gen);
        }
    }
}


void Matrix::print() const {
    for (const auto& row : data_) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << "\n";
    }
}