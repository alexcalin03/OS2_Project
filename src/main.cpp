#include "matrix.h"
#include <iostream>

void displayMenu(const Matrix& A, const Matrix& B) {
    while (true) {
        std::cout << "\nChoose an operation:\n";
        std::cout << "1. Add\n";
        std::cout << "2. Subtract\n";
        std::cout << "3. Multiply\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        try {
            if (choice == 1) {
                if (A.getRows() != B.getRows() || A.getCols() != B.getCols()) {
                    std::cerr << "Error: The dimensions of Matrix A and Matrix B must match for addition.\n";
                } else {
                    Matrix C = A.add(B);
                    std::cout << "\nResultant Matrix C (Addition):\n";
                    C.print();
                }
            } else if (choice == 2) {
                if (A.getRows() != B.getRows() || A.getCols() != B.getCols()) {
                    std::cerr << "Error: The dimensions of Matrix A and Matrix B must match for subtraction.\n";
                } else {
                    Matrix C = A.subtract(B);
                    std::cout << "\nResultant Matrix C (Subtraction):\n";
                    C.print();
                }
            } else if (choice == 3) {
                if (A.getCols() != B.getRows()) {
                    std::cerr << "Error: The number of columns in Matrix A must equal the number of rows in Matrix B for multiplication.\n";
                } else {
                    Matrix C = A.multiply(B);
                    std::cout << "\nResultant Matrix C (Multiplication):\n";
                    C.print();
                }
            } else if (choice == 4) {
                std::cout << "Exiting application...\n";
                break;
            } else {
                std::cerr << "Invalid choice. Please enter 1, 2, 3, or 4.\n";
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << '\n';
        }
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    std::cout << "Enter the number of rows for Matrix A: ";
    std::cin >> rowsA;
    std::cout << "Enter the number of columns for Matrix A: ";
    std::cin >> colsA;

    std::cout << "Enter the number of rows for Matrix B: ";
    std::cin >> rowsB;
    std::cout << "Enter the number of columns for Matrix B: ";
    std::cin >> colsB;

    Matrix A(rowsA, colsA);
    Matrix B(rowsB, colsB);

    A.fillRandom();
    B.fillRandom();

    std::cout << "Matrix A:\n";
    A.print();
    std::cout << "\nMatrix B:\n";
    B.print();

    displayMenu(A, B);

    return 0;
}