#include <iostream>
#include <vector>
#include "overloads.h"

int main(int argc, char const *argv[])
{
    // std::vector<std::vector<float>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // std::cout << vec << std::endl << std::endl;
    
    // size_t idx = 2;
    // // Remove first column
    // for (size_t i = 0; i < vec.size(); i++)
    //     vec[i].erase(vec[i].begin());
    
    // // Remove row at idx
    // vec.erase(vec.begin() + idx);

    // std::cout << vec << std::endl;

    std::vector<std::vector<float>> vec = {{1, 2, 3}, 
                                           {4, 5, 6}, 
                                           {7, 8, 9}};
    std::vector<std::vector<float>> newvec = {};
    // std::cout << vec.size() << std::endl;
    // size_t idx = 1;
    // for (size_t i = 0; i < vec.size(); i++) {
    //     for (size_t j = 1; j < vec[i].size(); j++) {
    //         if (i == idx) continue;
    //         std::cout << vec[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << newvec << std::endl << std::endl;
    std::cout << vec[0][0] << std::endl;
    return 0;
}
