#include "MultiDimensionalDynamicArray.h"

MultiDimensionalDynamicArray::MultiDimensionalDynamicArray(unsigned int rows, unsigned int cols):
    mRows(rows), mCols(cols)
{
    mData = new int*[mRows];
    for (unsigned int i = 0; i < mRows; ++i) {
        mData[i] = new int[mCols];
    }
}

MultiDimensionalDynamicArray::MultiDimensionalDynamicArray(unsigned int rows, unsigned int cols, int val):
    mRows(rows), mCols(cols)
{
    mData = new int*[mRows];
    for (unsigned int i = 0; i < mRows; ++i) {
        mData[i] = new int[mCols];
        for (unsigned int j = 0; j < mCols; ++j) {
            mData[i][j] = val;
        }
    }
}

MultiDimensionalDynamicArray::MultiDimensionalDynamicArray(std::pair<unsigned int, unsigned int> shape):
    mRows(shape.first), mCols(shape.second)
{
    mData = new int*[mRows];
    for (unsigned int i = 0; i < mRows; ++i) {
        mData[i] = new int[mCols];
    }
}

MultiDimensionalDynamicArray::MultiDimensionalDynamicArray(std::pair<unsigned int, unsigned int> shape, int val):
    mRows(shape.first), mCols(shape.second)
{
    mData = new int*[mRows];
    for (unsigned int i = 0; i < mRows; ++i) {
        mData[i] = new int[mCols];
        for (unsigned int j = 0; j < mCols; ++j) {
            mData[i][j] = val;
        }
    }
}

MultiDimensionalDynamicArray::~MultiDimensionalDynamicArray()
{
    for (unsigned int i = 0; i < mRows; ++i) {
        delete[] mData[i];
    }
    delete[] mData;
}


void MultiDimensionalDynamicArray::print(MultiDimensionalDynamicArray& arr) {
    std::cout << "{\n";
    for (unsigned int i = 0; i < arr.getRows(); ++i) {
        for (unsigned int j = 0; j < arr.getCols(); ++j) {
            std::cout << arr[i][j] << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << "}" << std::endl;
}


unsigned int MultiDimensionalDynamicArray::getRows() const {
    return mRows;
}
unsigned int MultiDimensionalDynamicArray::getCols() const {
    return mCols;
}

std::pair<unsigned int, unsigned int> MultiDimensionalDynamicArray::getShape() const {
    return std::make_pair(mRows, mCols);
}

int MultiDimensionalDynamicArray::getCount() const {
    return mRows * mCols;
}

int MultiDimensionalDynamicArray::getSize() const {
    return mRows * mCols * sizeof(int);
}


int& MultiDimensionalDynamicArray::operator()(unsigned int r, unsigned int c) {
    return mData[r][c];
}

int& MultiDimensionalDynamicArray::operator[](std::pair<unsigned int, unsigned int> index) {
    return mData[index.first][index.second];
}

int* MultiDimensionalDynamicArray::operator[](unsigned int r) {
    return mData[r];
}


int* MultiDimensionalDynamicArray::flatten() {
    int* flat = new int[mRows * mCols];
    for (unsigned int i = 0; i < mRows; ++i) {
        for (unsigned int j = 0; j < mCols; ++j) {
            flat[i * mCols + j] = mData[i][j];
        }
    }
    return flat;
}

std::vector<std::vector<int>> MultiDimensionalDynamicArray::toVector() {
    std::vector<std::vector<int>> vec(mRows);
    for (unsigned int i = 0; i < mRows; ++i) {
        vec[i] = std::vector<int>(mData[i], mData[i] + mCols);
    }
    return vec;
}

std::string MultiDimensionalDynamicArray::toString() {
    std::string str = "{\n";
    for (unsigned int i = 0; i < mRows; ++i) {
        for (unsigned int j = 0; j < mCols; ++j) {
            str += std::to_string(mData[i][j]) + ", ";
        }
        str += "\n";
    }
    str += "}";
    return str;
}


std::ostream& operator<<(std::ostream& os, MultiDimensionalDynamicArray& arr) {
    os << "{\n";
    for (unsigned int i = 0; i < arr.getRows(); ++i) {
        for (unsigned int j = 0; j < arr.getCols(); ++j) {
            os << arr[i][j] << ", ";
        }
        os << std::endl;
    }
    os << "}" << std::endl;
    return os;
}