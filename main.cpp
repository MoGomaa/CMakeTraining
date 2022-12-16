#include <iostream>

#include "MultiDimensionalDynamicArray.h"


int main() {
    std::cout << "Hello world!" << std::endl;
    MultiDimensionalDynamicArray mdda(2, 3, 5);
    std::cout << "Rows: " << mdda.getRows() << std::endl;
    std::cout << "Cols: " << mdda.getCols() << std::endl;
    std::cout << "Rows: " << mdda.getShape().first << std::endl;
    std::cout << "Cols: " << mdda.getShape().second << std::endl;
    std::cout << "Size: " << mdda.getSize() << std::endl;

    std::cout << "Element[0][0]: " << mdda(0, 0) << std::endl;
    mdda(0, 0) = 10;
    std::cout << "Element[0][0]: " << mdda(0, 0) << std::endl;
    mdda[{0, 0}] = 20;
    std::cout << "Element[0][0]: " << mdda[{0, 0}] << std::endl;

    int* row = mdda[0];
    for(unsigned int i = 0; i < mdda.getCols(); ++i) {
        std::cout << "Element[0][" << i << "]: " << row[i] << ", ";
    }
    std::cout << std::endl;
    int* flat = mdda.flatten();
    for(unsigned int i = 0; i < mdda.getCount(); ++i) {
        std::cout << "Element[" << i << "]: " << flat[i] << ", ";
    }
    std::cout << std::endl;
    
    std::cout << "Static MultiDimensionalDynamicArray::print: " << std::endl;
    MultiDimensionalDynamicArray::print(mdda);
    std::cout << "ostream operator<<: " << mdda << std::endl;
    std::cout << "toString: " << mdda.toString() << std::endl;
    
    auto vec = mdda.toVector();
    std::cout << "toVector: " << std::endl;
    for (unsigned int i = 0; i < vec.size(); ++i) {
        for (unsigned int j = 0; j < vec[i].size(); ++j) {
            std::cout << "Element[" << i << "][" << j << "]: " << vec[i][j] << ", ";
        }
        std::cout << std::endl;
    }

    return 0;
}