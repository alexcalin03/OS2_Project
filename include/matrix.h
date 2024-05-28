#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <thread>

class Matrix {
public:
    Matrix(int rows, int cols);
    void fillRandom();
    Matrix multiply(const Matrix& other) const;
    Matrix add(const Matrix& other) const;
    Matrix subtract(const Matrix& other) const;

    void print() const;

    int getRows() const { return rows_; }
    int getCols() const { return cols_; }

   

private:
    int rows_;
    int cols_;
    std::vector<std::vector<int>> data_;

    static void multiplyRow(const Matrix& A, const Matrix& B, Matrix& result, int row);
};

#endif 
