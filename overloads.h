#ifndef OVERLOADS_H
#define OVERLOADS_H

#include <iostream>
#include <optional>

std::ostream& operator<<(std::ostream& os, const std::optional<float>& value) {
    if (value == std::nullopt) {
        os << "None";
    } else {
        os << value.value();
    }
    return os;
}

// std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<float>>& matrix) {
//     os << "{";
//     for (const auto& row : matrix) {
//         os << "{";
//         for (const auto& element : row) {
//             // If last element, don't add comma
//             if (&element == &row.back()) os << element;
//             else os << element << ", ";
//         }
//         // If last row, add closing bracket
//         if (&row == &matrix.back()) os << "}}";
//         else os << "}, ";
//     }
//     return os;
// }

std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<float>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            // If last element, don't add space
            if (&element == &row.back()) os << element;
            else os << element << " ";
        }
        // If not last row, add newline
        if (&row != &matrix.back()) os << std::endl;
    }
    return os;
}


#endif // OVERLOADS_H
