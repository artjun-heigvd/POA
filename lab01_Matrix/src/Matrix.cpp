#include "Matrix.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

/**
 * @brief A class to represent a matrix and perform operations on it
 * @authors Arthur Junod, Samuel Roland, Edwin Haffner
 * @date 2024-02-29
 */

const Addition Matrix::ADD{};
const Subtraction Matrix::SUB{};
const Multiplication Matrix::MULT{};

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    os << matrix.toString();
    return os;
}

unsigned** Matrix::initData(const size_t line, const size_t column) {
    unsigned** newData = nullptr;
    try {
        newData = new unsigned*[line];
        for (size_t i = 0; i < line; ++i) {
            newData[i] = new unsigned[column];
        }
    } catch (const std::bad_alloc&) {
        for (size_t i = 0; i < line; i++) {
            delete[] newData[i];
        }
        delete[] newData;
        throw;
    }
    return newData;
}

unsigned Matrix::checkModulo(const unsigned mod) {
    if (mod == 0) {
        if (data != nullptr) {
            deleteData();
        }
        throw std::runtime_error("Modulo must be greater than zero");
    }
    return mod;
}

Matrix::Matrix(const size_t line,
               const size_t column,
               const unsigned modulo,
               const bool init)
    : data(initData(line, column)),
      m(line),
      n(column),
      modulo(checkModulo(modulo)) {
    if (init && data!= nullptr) {
        // Initialise the data to random numbers
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0,
                                                static_cast<int>(modulo) - 1);

        for (unsigned i = 0; i < m; ++i) {
            for (unsigned j = 0; j < n; ++j) {
                data[i][j] = static_cast<unsigned int>(distrib(gen));
            }
        }
    }
}

Matrix::Matrix(const size_t line, const size_t column, const unsigned modulo)
    : Matrix(line, column, modulo, true) {}

Matrix::Matrix(const Matrix& other)
    : data(initData(other.m, other.n)),
      m(other.m),
      n(other.n),
      modulo(other.modulo) {
    matrixCopyData(*this, other);
}

Matrix::Matrix(Matrix&& other) noexcept
    : data(nullptr), m(0), n(0), modulo(1) {
    exchangeMatrix(other);
}

Matrix& Matrix::operator=(const Matrix& other) {
    // Check for self-assignment
    if (this != &other) {
        if (m != other.m || n != other.n) {
            deleteData();
        }
        matrixCopyData(*this, other);
    }
    return *this;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept {
    if (this != &other) {
        deleteData();
        exchangeMatrix(other);
    }
    return *this;
}

void Matrix::deleteData() noexcept{
    if (data != nullptr) {
        for (size_t i = 0; i < m; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
    data = nullptr;
}

void Matrix::matrixCopyData(const Matrix& m1, const Matrix& m2) {
    if (m1.m == m2.m && m1.n == m2.n) {
        for (size_t i = 0; i < m1.m; ++i) {
            for (size_t j = 0; j < m1.n; ++j) {
                m1.data[i][j] = m2.data[i][j];
            }
        }
    } else {
        throw std::runtime_error(
            "Matrix dimensions are not compatible for copying data");
    }
}

Matrix::~Matrix() noexcept{
    deleteData();
}

void Matrix::applyOperation(Matrix& result,
                            const Matrix& first,
                            const Matrix& second,
                            const Operation& op) {
    for (unsigned i = 0; i < result.m; i++) {
        for (unsigned j = 0; j < result.n; j++) {
            // Put the unsigned here to remove a warning...
            unsigned op1 = first.getValueOrZero(i, j);
            unsigned op2 = second.getValueOrZero(i, j);
            result.data[i][j] = applyModulo(op.operate(op1, op2), first.modulo);
        }
    }
}

unsigned Matrix::applyModulo(long long value, unsigned modulo) {
    return static_cast<unsigned>((value % modulo + modulo) % modulo);
}

std::pair<unsigned, unsigned> Matrix::getMaxLinesColumns(
    const Matrix& first,
    const Matrix& second) const {
    if (modulo != second.modulo) {
        throw std::invalid_argument(
            "Matrices do not have the same modulo values");
    }

    auto maxLines = static_cast<unsigned int>(std::max(first.m, second.m));
    auto maxColumns = static_cast<unsigned int>(std::max(first.n, second.n));

    return std::pair{maxLines, maxColumns};
}

Matrix Matrix::operateMatrix(const Matrix& other,
                             const Operation& function) const {
    auto [maxLines, maxColumns] = getMaxLinesColumns(*this, other);
    Matrix res{maxLines, maxColumns, modulo, false};
    applyOperation(res, *this, other, function);
    return res;
}

Matrix* Matrix::operatePointer(const Matrix& other,
                               const Operation& function) const {
    auto [maxLines, maxColumns] = getMaxLinesColumns(*this, other);
    auto* res = new Matrix{maxLines, maxColumns, modulo, false};
    applyOperation(*res, *this, other, function);
    return res;
}

Matrix& Matrix::operateThis(const Matrix& other, const Operation& function) {
    if (other.m > m || other.n > n) {
        // Resize the matrix
        Matrix tmp{*this};
        deleteData();

        auto [maxLines, maxColumns] = getMaxLinesColumns(*this, other);
        data = initData(maxLines, maxColumns);
        m = maxLines;
        n = maxColumns;
        applyOperation(*this, tmp, other, function);

    } else {
        applyOperation(*this, *this, other, function);
    }
    return *this;
}

Matrix Matrix::additionMatrix(const Matrix& other) const {
    return operateMatrix(other, ADD);
}

Matrix* Matrix::additionPointer(const Matrix& other) const {
    return operatePointer(other, ADD);
}

Matrix& Matrix::additionThis(const Matrix& other) {
    return operateThis(other, ADD);
}

Matrix Matrix::subtractionMatrix(const Matrix& other) const {
    return operateMatrix(other, SUB);
}

Matrix* Matrix::subtractionPointer(const Matrix& other) const {
    return operatePointer(other, SUB);
}

Matrix& Matrix::subtractionThis(const Matrix& other) {
    return operateThis(other, SUB);
}

Matrix Matrix::multiplicationMatrix(const Matrix& other) const {
    return operateMatrix(other, MULT);
}

Matrix* Matrix::multiplicationPointer(const Matrix& other) const {
    return operatePointer(other, MULT);
}

Matrix& Matrix::multiplicationThis(const Matrix& other) {
    return operateThis(other, MULT);
}

unsigned Matrix::getValueOrZero(const unsigned i, const unsigned j) const {
    if (m <= i || n <= j) {
        return 0;
    }
    return data[i][j];
}

std::string Matrix::toString() const {
    std::ostringstream os;
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (j > 0) {
                os << " ";
            }
            os << data[i][j];
        }
        os << std::endl;
    }
    return os.str();
}

void Matrix::exchangeMatrix(Matrix& other) {
    data = std::exchange(other.data, nullptr);
    m = std::exchange(other.m, 0);
    n = std::exchange(other.n, 0);
    modulo = std::exchange(other.modulo, 1);
}