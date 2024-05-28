#include "matrix.h"
#include <iostream>

int main() {
    int size = 3; 

    Matrix A(size, size);
    Matrix B(size, size);

    A.fillRandom();
    B.fillRandom();

    std::cout << "Matrix A:\n";
    A.print();
    std::cout << "\nMatrix B:\n";
    B.print();

    try {
        Matrix C = A.multiply(B);
        std::cout << "\nResultant Matrix C:\n";
        C.print();
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}
