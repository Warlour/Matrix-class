#include <iostream>
#include <vector>
#include <optional>
#include <cmath>

#include "overloads.h"

class Matrix {
private:
    int _rows = 0;
    int _cols = 0;
    bool _isSquare = false;
    bool _isSingular = false;
    

    float _get_determinant(std::vector<std::vector<float>> m) {
        if (m.size() < 1) {
            throw std::invalid_argument("Matrix is empty");
        }
        else if (m.size() == 1) {
            return m[0][0];
        }
        else if (m.size() == 2) {
            return m[0][0] * m[1][1] - m[0][1] * m[1][0];
        }
        else if (m.size() > 2) {
            float sum = 0;
            for (size_t idx = 0; idx < m.size(); idx++) {
                // Create submatrix
                std::vector<std::vector<float>> submatrix = m;

                // Remove first column
                for (size_t i = 0; i < submatrix.size(); i++)
                    submatrix[i].erase(submatrix[i].begin());
                
                // Remove row at idx
                submatrix.erase(submatrix.begin() + idx);

                sum += pow(-1, idx+1) * m[idx][0] * _get_determinant(submatrix);
                // std::cout << submatrix << std::endl;
                // std::cout << _get_determinant(submatrix);
                // std::cout << submatrix << std::endl << std::endl;
            }
            return sum;
        }
        return 0;
    }

    void _get_data(std::vector<std::vector<float>> v) {
        for (size_t i = 0; i < v.size(); i++) {
            // Add vector for each row
            std::vector<float> vec = {};

            // Add column values to vec
            for (size_t j = 0; j < v[i].size(); j++)
                vec.push_back(v[i][j]);

            // Add to data member
            data.push_back(vec);
        }
    }

public:
    std::vector<std::vector<float>> data = {};
    std::optional<float> determinant = std::nullopt;

    // Constructor
    Matrix(std::vector<std::vector<float>> v) {
        _rows = v.size();
        _cols = v[0].size();

        _isSquare = (_rows == _cols);

        _get_data(v);

        if (_isSquare)
            determinant = _get_determinant(data);
    }

    // Methods
    void info() {
        std::cout << "Rows: " << _rows << std::endl;
        std::cout << "Columns: " << _cols << std::endl;
        std::cout << "Is Square: " << _isSquare << std::endl;
        std::cout << "Determinant: " << determinant << std::endl;
    }

    // Matrix rref() {
    //     std::cout << "Matrix reduced" << std::endl;
    // }

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
    std::vector<std::vector<float>> m = {{1, 2, 3, 4}, 
                                         {5, 6, 7, 8}, 
                                         {9, 10, 10, 12},
                                         {13, 14, 15, 15}};
    
    // std::vector<std::vector<float>> m = {{1, 2, 3},
    //                                      {4, 5, 6},
    //                                      {7, 8, 4}};
    Matrix matrix(m);
    // std::cout << matrix.data << std::endl;
    matrix.info();
    return 0;
}
