#ifndef OVERLOADS_H
#define OVERLOADS_H

#include <iostream>
#include <optional>

/* cout */
std::ostream& operator<<(std::ostream& os, const std::optional<float>& value) {
    if (value == std::nullopt) {
        os << "None";
    } else {
        os << value.value();
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<float>& v) {
    os << "{";
    for (const auto& element : v) {
        // If last element, don't add comma
        if (&element == &v.back()) os << element;
        else os << element << ", ";
    }
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<float>>& matrix) {
    os << "{";
    for (const auto& row : matrix) {
        os << "{";
        for (const auto& element : row) {
            // If last element, don't add comma
            if (&element == &row.back()) os << element;
            else os << element << ", ";
        }
        // If last row, add closing bracket
        if (&row == &matrix.back()) os << "}}";
        else os << "}, ";
    }
    return os;
}


/* Multiplication */
//// constant times vector
std::vector<float> operator*(float c, const std::vector<float>& v) {
    std::vector<float> result(v.size());
    for (size_t i = 0; i < v.size(); i++) {
        result[i] = c * v[i];
    }
    return result;
}
std::vector<float> operator*(const std::vector<float>& v, float c) {
    return c * v;  // Reuse previous overload
}
// multiplication equals
std::vector<float> operator*=(float c, const std::vector<float>& v) {
    return c * v;  // Reuse previous overload
}
std::vector<float> operator*=(const std::vector<float>& v, float c) {
    return c * v;  // Reuse previous overload
}

//// vector times vector
std::vector<float> operator*(const std::vector<float>& v1, const std::vector<float>& v2) {
    if (v1.size() != v2.size())
        throw std::invalid_argument("Error: vectors must be same size");
    
    std::vector<float> result(v1.size());
    for (size_t i = 0; i < v1.size(); i++) {
        result[i] = v1[i] * v2[i];
    }
    return result;
}
// multiplication equals
std::vector<float> operator*=(const std::vector<float>& v1, const std::vector<float>& v2) {
    return v1 * v2;  // Reuse previous overload
}


/* Division */
//// vector divided by vector
std::vector<float> operator/(const std::vector<float>& v1, const std::vector<float>& v2) {
    if (v1.size() != v2.size())
        throw std::invalid_argument("Error: vectors must be same size");
    
    std::vector<float> result(v1.size());
    for (size_t i = 0; i < v1.size(); i++) {
        result[i] = v1[i] / v2[i];
    }
    return result;
}
// division equals
std::vector<float> operator/=(const std::vector<float>& v1, const std::vector<float>& v2) {
    return v1 / v2;  // Reuse previous overload
}

//// vector divided by constant
std::vector<float> operator/(float c, const std::vector<float>& v) {
    std::vector<float> result(v.size());
    for (size_t i = 0; i < v.size(); i++) {
        result[i] = c / v[i];
    }
    return result;
}
std::vector<float> operator/(const std::vector<float>& v, float c) {
    return c / v;  // Reuse previous overload
}
// division equals
std::vector<float> operator/=(float c, const std::vector<float>& v) {
    return c / v;  // Reuse previous overload
}
std::vector<float> operator/=(const std::vector<float>& v, float c) {
    return c / v;  // Reuse previous overload
}


/* Subtraction */
//// vector minus constant
std::vector<float> operator-(const std::vector<float>& v1, const std::vector<float>& v2) {
    if (v1.size() != v2.size())
        throw std::invalid_argument("Error: vectors must be same size");
    
    std::vector<float> result(v1.size());
    for (size_t i = 0; i < v1.size(); i++) {
        result[i] = v1[i] - v2[i];
    }
    return result;
}
// subtraction equals
std::vector<float> operator-=(const std::vector<float>& v1, const std::vector<float>& v2) {
    return v1 - v2;  // Reuse previous overload
}

#endif // OVERLOADS_H
