#pragma once

#include "Operation.hpp"
#include "operations/Addition.hpp"
#include "operations/Multiplication.hpp"
#include "operations/Subtraction.hpp"

#include <random>

/**
 * @brief A class to represent a matrix and perform operations on it
 * @authors Arthur Junod, Samuel Roland, Edwin Haffner
 * @date 2024-02-29
 */
class Matrix {
private:
    unsigned** data;
    size_t m;  // nb ligne
    size_t n;  // nb colonne
    unsigned modulo;

    static const Addition ADD;
    static const Subtraction SUB;
    static const Multiplication MULT;

    /**
     * @brief Apply an operation to two matrices and store the result in a third
     * one
     *
     * @param result the matrix that will contain the result
     * @param first the first matrix
     * @param second the second matrix
     * @param op the operation to apply
     */
    static void applyOperation(Matrix& result,
                               const Matrix& first,
                               const Matrix& second,
                               const Operation& op);

    /**
     * @brief Copy the data of a matrix to another
     *
     * @param m1 the first matrix
     * @param m2 the second matrix
     */
    static void matrixCopyData(const Matrix& m1, const Matrix& m2);

    /**
     * @brief Exchange the data of two matrices, leaving the matrix "other"
     * empty
     *
     * @param other the matrix to exchange with
     */
    void exchangeMatrix(Matrix& other);

    /**
     * @brief Get the maximum number of lines and columns between two matrices
     *
     * @param first
     * @param second
     * @return a pair containing the maximum number of lines and columns
     */
    [[nodiscard]] std::pair<unsigned, unsigned> getMaxLinesColumns(
        const Matrix& first,
        const Matrix& second) const;

    /**
     * @brief Check if the mod is valid (aka > 0)
     * @param mod
     * @return the mod if it is valid, otherwise throw an exception
     */
    unsigned int checkModulo(unsigned int mod);

    /**
     * @brief Initialize the memory of a matrix
     *
     * @param line
     * @param column
     * @return a pointer to the data
     */
    static unsigned** initData(size_t line, size_t column);

    /**
     * @brief Operate on two matrices
     *
     * @param other the other matrix
     * @param function to apply (addition, subtraction, multiplication)
     * @return the result of the operation as a new matrix
     */
    [[nodiscard]] Matrix operateMatrix(const Matrix& other,
                                       const Operation& function) const;

    /**
     * @brief Operate on two matrices and return a pointer to a dynamically
     * allocated matrix
     *
     * @param other matrix
     * @param function to apply (addition, subtraction, multiplication)
     * @return a pointer to the result of the operation
     */
    [[nodiscard]] Matrix* operatePointer(const Matrix& other,
                                         const Operation& function) const;

    /**
     * @brief Operate on two matrices and store the result in this matrix
     * @param other matrix
     * @param function to apply (addition, subtraction, multiplication)
     * @return a reference to this matrix
     */
    Matrix& operateThis(const Matrix& other, const Operation& function);

    /**
     * @brief Create a matrix with or without initialization
     *
     * @param line nb of lines
     * @param column nb of columns
     * @param modulo of the matrix
     * @param init if true, the matrix is initialized with random values
     */
    Matrix(size_t line, size_t column, unsigned modulo, bool init);

    /**
     * @brief Apply the modulo to a value
     *
     * @param value we want to apply the modulo to
     * @param modulo
     * @return the new value after applying the modulo
     */
    static unsigned int applyModulo(long long value, unsigned int modulo);

    /**
     * @brief Delete the data of this matrix
     */
    void deleteData() noexcept;

public:
    /**
     * @brief Get the value at the given position
     *
     * @param i line number
     * @param j column number
     * @return if the value exists in this, return the value, else return 0
     */
    [[nodiscard]] unsigned getValueOrZero(unsigned i, unsigned j) const;

    /**
     * @brief Create a matrix with random values
     *
     * @param line nb of lines
     * @param column nb of columns
     * @param modulo of the matrix
     */
    Matrix(size_t line, size_t column, unsigned modulo);

    /**
     * @brief Copy constructor
     * @param other
     */
    Matrix(const Matrix& other);

    /**
     * @brief Move constructor
     * @param other
     */
    Matrix(Matrix&& other) noexcept;

    /**
     * @brief Copy assignment
     * @param other
     * @return a reference to this matrix
     */
    Matrix& operator=(const Matrix& other);

    /**
     * @brief Move assignment
     * @param other
     * @return a reference to this matrix
     */
    Matrix& operator=(Matrix&& other) noexcept;

    /**
     * @brief Destructor
     */
    ~Matrix() noexcept;

    /**
     * Groups of methods to add, subtract and multiply two matrices, with 3
     * different ways to do it:
     * - All `*Matrix()` return a new statically allocated matrix by value
     * - All `*Pointer()` return a new dynamically allocated matrix by pointer
     * - All `*This()` change the matrix on which we call the method
     */
    [[nodiscard]] Matrix additionMatrix(const Matrix& other) const;
    [[nodiscard]] Matrix* additionPointer(const Matrix& other) const;
    Matrix& additionThis(const Matrix& other);

    [[nodiscard]] Matrix subtractionMatrix(const Matrix& other) const;
    [[nodiscard]] Matrix* subtractionPointer(const Matrix& other) const;
    Matrix& subtractionThis(const Matrix& other);

    [[nodiscard]] Matrix multiplicationMatrix(const Matrix& other) const;
    [[nodiscard]] Matrix* multiplicationPointer(const Matrix& other) const;
    Matrix& multiplicationThis(const Matrix& other);

    [[nodiscard]] std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
};
