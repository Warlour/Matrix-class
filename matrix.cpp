#include <iostream>
#include <vector>
#include <optional>
#include <cmath>
#include <string>
#include <algorithm>

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
            }
            return sum;
        } else {
            return 0;
        }
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
    float determinant;

    // Constructor
    Matrix(std::vector<std::vector<float>> v) {
        _rows = v.size();
        _cols = v[0].size();

        _isSquare = (_rows == _cols);

        _get_data(v);

        if (_isSquare)
            determinant = _get_determinant(data);
            if (determinant == 0) _isSingular = true;
    }

    // Methods
    void info() {
        std::cout << "Rows: " << std::to_string(_rows) << std::endl;
        std::cout << "Columns: " << std::to_string(_cols) << std::endl;
        std::cout << "Is Square: " << _isSquare << std::endl;
        std::cout << "Determinant: " << determinant << std::endl;
    }

    Matrix rref(bool show_steps = false) {
        // Create a copy of current matrix

        Matrix mat(data);

        /* https://stackoverflow.com/a/31761026 
           CC BY-SA 3.0 DEED | Attribution-ShareAlike 3.0 Unported
           I have changed the variable names.

           (I tried doing it by myself, okay?)
        */
        // Variables
        const size_t rows = mat.data.size();
        const size_t cols = mat.data[0].size();

        int lead = 0;

        while (lead < rows) {
            float d, m;

            for (int r = 0; r < rows; r++) {
                d = mat.data[lead][lead];
                m = mat.data[r][lead] / mat.data[lead][lead];

                for (int c = 0; c < cols; c++) {
                    if (r == lead)
                        mat.data[r][c] /= d;
                    else
                        mat.data[r][c] -= mat.data[lead][c] * m;
                }
            }

            lead++;
            if (show_steps) {
                mat.print();
                std::cout << std::endl;
            }
        }

        return mat;
    }

    Matrix inverse() {
        if (_isSingular) throw std::invalid_argument("Matrix is singular");
        std::vector<std::vector<float>> m = data;

        // Append identity matrix
        size_t newcols = 0;
        for (size_t i = 0; i < data.size(); i++) {
            for (size_t j = 0; j < data[i].size(); j++) {
                m[i].push_back(i == j ? 1 : 0);
            }
            newcols++;
        }

        // Perform row operations
        Matrix reduced = Matrix(m).rref();

        // Remove identity matrix
        for (size_t i = 0; i < newcols; i++) {
            for (size_t j = 0; j < reduced.data[i].size(); j++) {
                reduced.data[i].erase(reduced.data[i].begin());
            }
        }

        return reduced;
    }

    Matrix transpose() {
        std::vector<std::vector<float>> m = data;

        for (size_t r = 0; r < data.size(); r++) {
            for (size_t c = 0; c < data[r].size(); c++) {
                m[c][r] = data[r][c];
            }
        }

        return Matrix(m);
    }

    void print() {
        std::string out;
        for (const auto& row : data) {
            for (const auto& element : row) {
                // If last element, don't add space
                if (&element == &row.back()) out += std::to_string(element);
                else out += std::to_string(element) + " ";
            }
            // If not last row, add newline
            if (&row != &data.back()) out += "\n";
        }
        std::cout << out << std::endl;
    }

    void round() {
        for (size_t i = 0; i < data.size(); i++) {
            for (size_t j = 0; j < data[i].size(); j++)
                data[i][j] = std::round(data[i][j]);
        }
    }

    

    // ~Matrix() {
    //     std::cout << "Matrix destroyed" << std::endl;
    // }
};

int main(int argc, char const *argv[]) {
    // std::vector<std::vector<float>> m = {{5, -6, -7,   7}, 
    //                                      {3, -2,  5, -17}, 
    //                                      {2,  4, -3,  29}};
    
    // std::vector<std::vector<float>> m = {{1, 2, 3},
    //                                      {4, 5, 6},
    //                                      {7, 8, 4}};

    std::vector<std::vector<float>> m = {{-3, 7}, 
                                         {-5, 9}};
    Matrix matrix(m);
    // std::cout << matrix.data << std::endl;
    // matrix.info();
    // Matrix inversed = matrix.inverse();
    // inversed.print();
    matrix.print();
    std::cout << std::endl;
    Matrix transposed = matrix.transpose();
    transposed.print();

    // matrix.info();

    // matrix.inverse().print();

    // inversed.round();
    // inversed.print();
    return 0;
}
