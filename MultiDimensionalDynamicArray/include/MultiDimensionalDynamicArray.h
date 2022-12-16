#pragma once


#include <iostream>
#include <utility>
#include <vector>
#include <string>


class MultiDimensionalDynamicArray {
private:
    unsigned int        mRows;
    unsigned int        mCols;
    int**               mData;

public:
    MultiDimensionalDynamicArray(unsigned int rows, unsigned int cols);
    MultiDimensionalDynamicArray(unsigned int rows, unsigned int cols, int val);
    MultiDimensionalDynamicArray(std::pair<unsigned int, unsigned int> shape);
    MultiDimensionalDynamicArray(std::pair<unsigned int, unsigned int> shape, int val);
    ~MultiDimensionalDynamicArray();

    static void print(MultiDimensionalDynamicArray& arr);  
    
    unsigned int                            getRows() const;
    unsigned int                            getCols() const;
    std::pair<unsigned int, unsigned int>   getShape() const;
    int                                     getCount() const;
    int                                     getSize() const;
    
    int&    operator()(unsigned int r, unsigned int c);
    int&    operator[](std::pair<unsigned int, unsigned int> index);
    int*    operator[](unsigned int r);

    int*                            flatten();
    std::vector<std::vector<int>>   toVector();
    std::string                     toString();

    friend std::ostream& operator<<(std::ostream& os, MultiDimensionalDynamicArray& arr);  
};



