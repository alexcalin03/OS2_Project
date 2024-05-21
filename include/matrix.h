#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <thread>

class Matrix {
public:
    Matrix(int rows, int cols);
    void fillRandom();
    Matrix multiply(const Matrix& other);
    void print() const;

private:
    int rows_;
    int cols_;
    std::vector<std::vector<int>> data_;

    static void multiplyRow(const Matrix& A, const Matrix& B, Matrix& result, int row);
};

#endif 
