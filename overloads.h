#ifndef OVERLOADS_H
#define OVERLOADS_H

#include <iostream>
#include <optional>

std::ostream& operator<<(std::ostream& os, const std::optional<float>& value) {
    if (value.has_value()) {
        os << value.value();
    } else {
        os << "std::nullopt";
    }
    return os;
}

#endif // OVERLOADS_H
