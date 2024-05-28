#include "matrix.h"
#include <iostream>
#include <random>
#include <stdexcept>
#include <thread>

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

Matrix Matrix::multiply(const Matrix& other) const {
    if (cols_ != other.rows_) {
        throw std::invalid_argument("Matrix dimensions do not match for multiplication.");
    }

    Matrix result(rows_, other.cols_);
    std::vector<std::thread> threads;

    for (int i = 0; i < rows_; ++i) {
        threads.emplace_back(&Matrix::multiplyRow, std::ref(*this), std::ref(other), std::ref(result), i);
    }

    for (auto& t : threads) {
        t.join();
    }

    return result;
}

void Matrix::multiplyRow(const Matrix& A, const Matrix& B, Matrix& result, int row) {
    for (int j = 0; j < B.cols_; ++j) {
        result.data_[row][j] = 0;
        for (int k = 0; k < A.cols_; ++k) {
            result.data_[row][j] += A.data_[row][k] * B.data_[k][j];
        }
    }
}
