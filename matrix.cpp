#include <iostream>
#include <vector>
#include <optional>

#include "overloads.h"

class Matrix {
private:
    int rows = 0;
    int cols = 0;
    bool isSquare = false;
    std::optional<float> determinant = std::nullopt;
    bool isSingular = false;
    std::vector<std::vector<float>> data = {{}};

    // void determinant() {
        

    //     Matrix extended(ext);
    // }

public:
    Matrix(std::vector<std::vector<float>> v) {
        rows = v.size();
        cols = v[0].size();

        isSquare = (rows == cols);

        for (size_t i = 0; i < v.size(); i++) {
            // Add vector for each row
            std::vector<float> vec = {};

            for (size_t j = 0; j < v[i].size(); j++) {
                // Add column values to vec
                vec.push_back(v[i][j]);
            }

            // Add to data member
            data.push_back(vec);
        }
    }

    // Methods
    void info() {
        std::cout << "Rows: " << rows << std::endl;
        std::cout << "Columns: " << cols << std::endl;
        std::cout << "Is Square: " << isSquare << std::endl;
        std::cout << "Determinant: " << determinant << std::endl;
    }
    // Matrix inverse() {
    //     // Append identity matrix
        

    //     std::cout << "Matrix inverted" << std::endl;
    // }

    // Matrix transpose() {
    //     std::cout << "Matrix transposed" << std::endl;
    // }

    // ~Matrix() {
    //     std::cout << "Matrix destroyed" << std::endl;
    // }
};


int main(int argc, char const *argv[]) {
    std::vector<std::vector<float>> m = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix matrix(m);
    matrix.info();
    return 0;
}
