#include <iostream>
#include <vector>
#include <stdexcept>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    int rows;
    int cols;

public:
    Matrix() {
        rows = 0;
        cols = 0;
    }
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data.resize(rows, std::vector<int>(cols, 0));
    }

    void setData() {
        std::cout << "Enter matrix elements row-wise:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "Enter element at row " << i + 1 << ", column " << j + 1 << ": ";
                std::cin >> data[i][j];
            }
        }
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrix dimensions are not compatible for addition.");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("Matrix dimensions are not compatible for multiplication.");
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }

    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < cols; ++i) {
            for (int j = 0; j < rows; ++j) {
                result.data[i][j] = data[j][i];
            }
        }

        return result;
    }

    void display() const {
        std::cout << "Matrix:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int rows, cols;
    std::cout << "Enter the number of rows in the matrix: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns in the matrix: ";
    std::cin >> cols;

    Matrix matrix1(rows, cols);
    matrix1.setData();

    Matrix matrix2(rows, cols);
    matrix2.setData();

    std::cout << "Matrix 1:" << std::endl;
    matrix1.display();

    std::cout << "Matrix 2:" << std::endl;
    matrix2.display();

    int choice;

    while(true) {
        std::cout << "Matrix Operations Menu:" << std::endl;
        std::cout << "1. Sum" << std::endl;
        std::cout << "2. Product" << std::endl;
            std::cout << "3. Transpose" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        Matrix result;
        try {
            switch (choice) {
                case 1:
                    result = matrix1 + matrix2;
                    std::cout << "Matrix Sum:" << std::endl;
                    result.display();
                    break;
                case 2:
                    result = matrix1 * matrix2;
                    std::cout << "Matrix Product:" << std::endl;
                    result.display();
                    break;
                case 3:
                    result = matrix1.transpose();
                    std::cout << "Matrix Transpose:" << std::endl;
                    result.display();
                    break;
                default:
                    std::cout << "Exiting!" << std::endl;
                    return 0;
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << std::endl;
            return 1;
        }
    }
    return 0;
}
