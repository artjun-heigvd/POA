#include <gtest/gtest.h>
#include <string>
#include "../src/Matrix.hpp"

using namespace std;

// Macros to do enhance testing readability
#define s(t) to_string(t)
#define defaultModulo 5
#define calc(m1, m2, x, y, sign)                                        \
    (s(((((long)m1.getValueOrZero(x, y) sign m2.getValueOrZero(x, y)) % \
         defaultModulo) +                                               \
        defaultModulo) %                                                \
       defaultModulo))
#define add(m1, m2, x, y) calc(m1, m2, x, y, +)
#define sub(m1, m2, x, y) calc(m1, m2, x, y, -)
#define mul(m1, m2, x, y) calc(m1, m2, x, y, *)

TEST(MatrixTest, CanCreateRandomMatrix) {
    Matrix m(1, 2, 3);
    Matrix m2(4, 10, 2);
    Matrix m3(4, 10, 2);
    cout << m << m2 << m3;
}

TEST(MatrixTest, CanCreateRandomMatrix1x1) {
    Matrix m(1, 1, 3);
    cout << m;
}

TEST(MatrixTest, CanCreateEmptyMatrix) {
    Matrix m(0, 0, 3);
    EXPECT_EQ("", m.toString());
    EXPECT_EQ("", m.multiplicationMatrix(m).toString());
    auto res = m.multiplicationPointer(m);
    EXPECT_EQ("", res->toString());
    delete res;
    EXPECT_EQ("", m.multiplicationThis(m).toString());
}

TEST(MatrixTest, CanCreateRandomMatrixWithModulo1) {
    Matrix m(20, 5, 1);
}

TEST(MatrixTest, CanCreateRandomMatrixWithNullModuloFails) {
    EXPECT_THROW(Matrix m(20, 5, 0), runtime_error);
}

TEST(MatrixTest, MatrixStreamOperatorWorks) {
    Matrix m(2, 3, 1);
    EXPECT_EQ(m.toString(), "0 0 0\n0 0 0\n");
}

TEST(MatrixTest, CanCopyMatrixViaConstructor) {
    Matrix m(2, 3, 2);
    Matrix m2(m);
    EXPECT_EQ(m.toString(), m2.toString());
}

TEST(MatrixTest, CanMoveMatrixAtConstructionOrAffectation) {
    Matrix m(2, 3, 2);
    Matrix m2(2, 3, 2);
    Matrix m3(2, 1, 10);
	m3 = std::move(m);
    Matrix const m4(std::move(m2));
    EXPECT_EQ(m.toString(), m2.toString());
    EXPECT_EQ(m4.toString(), m4.toString());
}

// Testing 3 operations with their 3 variants
TEST(MatrixTest, CanAddition2Matrix) {
#define op add
    // Same dimensions: 1x3, modulo defaultModulo
    Matrix m(1, 3, defaultModulo), m2(1, 3, defaultModulo);

    string expected1 =
        op(m, m2, 0, 0) + " " + op(m, m2, 0, 1) + " " + op(m, m2, 0, 2) + "\n";
    EXPECT_EQ(expected1, m.additionMatrix(m2).toString());
    Matrix* res = m.additionPointer(m2);
    EXPECT_EQ(expected1, res->toString());
    delete res;
    EXPECT_EQ(expected1, m.additionThis(m2).toString());

    // Different dimensions: 1x3 and 2x2 -> 2x3, modulo defaultModulo
    Matrix m4(2, 2, defaultModulo);
    string expected2 = op(m, m4, 0, 0) + " " + op(m, m4, 0, 1) + " " +
                       op(m, m4, 0, 2) + "\n" + op(m, m4, 1, 0) + " " +
                       op(m, m4, 1, 1) + " " + op(m, m4, 1, 2) + "\n";
    EXPECT_EQ(expected2, m.additionMatrix(m4).toString());
    res = m.additionPointer(m4);
    EXPECT_EQ(expected2, res->toString());
    delete res;
    // EXPECT_EQ(m.toString(), m4.toString());	//just to inspect matrix values
    EXPECT_EQ(expected2, m.additionThis(m4).toString());
    EXPECT_EQ(expected2, m.toString());
}

TEST(MatrixTest, CanSubtract2Matrix) {
#define op sub
#define defaultModulo 10
    // Same dimensions: 1x3, modulo defaultModulo
    Matrix m(1, 3, defaultModulo), m2(1, 3, defaultModulo);

    string expected1 =
        op(m, m2, 0, 0) + " " + op(m, m2, 0, 1) + " " + op(m, m2, 0, 2) + "\n";
    EXPECT_EQ(expected1, m.subtractionMatrix(m2).toString());
    Matrix* res = m.subtractionPointer(m2);
    EXPECT_EQ(expected1, res->toString());
    delete res;
    EXPECT_EQ(expected1, m.subtractionThis(m2).toString());

    // Different dimensions: 1x3 and 2x2 -> 2x3, modulo defaultModulo
    Matrix m4(2, 2, defaultModulo);
    string expected2 = op(m, m4, 0, 0) + " " + op(m, m4, 0, 1) + " " +
                       op(m, m4, 0, 2) + "\n" + op(m, m4, 1, 0) + " " +
                       op(m, m4, 1, 1) + " " + op(m, m4, 1, 2) + "\n";
    EXPECT_EQ(expected2, m.subtractionMatrix(m4).toString());
    res = m.subtractionPointer(m4);
    EXPECT_EQ(expected2, res->toString());
    delete res;
    // EXPECT_EQ(m.toString(), m4.toString());	//just to inspect matrix values
    EXPECT_EQ(expected2, m.subtractionThis(m4).toString());
    EXPECT_EQ(expected2, m.toString());
}

TEST(MatrixTest, CanMultiply2Matrix) {
#define op mul
#define defaultModulo 20

    // Same dimensions: 1x3, modulo defaultModulo
    Matrix m(1, 3, defaultModulo), m2(1, 3, defaultModulo);

    string expected1 =
        op(m, m2, 0, 0) + " " + op(m, m2, 0, 1) + " " + op(m, m2, 0, 2) + "\n";
    EXPECT_EQ(expected1, m.multiplicationMatrix(m2).toString());
    Matrix* res = m.multiplicationPointer(m2);
    EXPECT_EQ(expected1, res->toString());
    delete res;
    EXPECT_EQ(expected1, m.multiplicationThis(m2).toString());

    // Different dimensions: 1x3 and 2x2 -> 2x3, modulo defaultModulo
    Matrix m4(2, 2, defaultModulo);
    string expected2 = op(m, m4, 0, 0) + " " + op(m, m4, 0, 1) + " " +
                       op(m, m4, 0, 2) + "\n" + op(m, m4, 1, 0) + " " +
                       op(m, m4, 1, 1) + " " + op(m, m4, 1, 2) + "\n";
    EXPECT_EQ(expected2, m.multiplicationMatrix(m4).toString());
    res = m.multiplicationPointer(m4);
    EXPECT_EQ(expected2, res->toString());
    delete res;
    // EXPECT_EQ(m.toString(), m4.toString());	//just to inspect matrix values
    EXPECT_EQ(expected2, m.multiplicationThis(m4).toString());
    EXPECT_EQ(expected2, m.toString());
}

TEST(MatrixTest, MatrixCanBeCalculatedWithThemselves) {
    Matrix m(2, 2, defaultModulo);
#define op add
    string expected = op(m, m, 0, 0) + " " + op(m, m, 0, 1) + "\n" +
                      op(m, m, 1, 0) + " " + op(m, m, 1, 1) + "\n";
    EXPECT_EQ(expected, m.additionMatrix(m).toString());
#define op sub
    string expected2 = op(m, m, 0, 0) + " " + op(m, m, 0, 1) + "\n" +
                       op(m, m, 1, 0) + " " + op(m, m, 1, 1) + "\n";
    EXPECT_EQ(expected2, m.subtractionMatrix(m).toString());
#define op mul
    string expected3 = op(m, m, 0, 0) + " " + op(m, m, 0, 1) + "\n" +
                       op(m, m, 1, 0) + " " + op(m, m, 1, 1) + "\n";
    EXPECT_EQ(expected3, m.multiplicationMatrix(m).toString());
}

TEST(MatrixTest, MatrixSubtractedWithItselfIsFullOfZero) {
    Matrix m(4, 2, 10);
    EXPECT_EQ("0 0\n0 0\n0 0\n0 0\n", m.subtractionMatrix(m).toString());
}

TEST(MatrixTest, OperationsWithNonEqualModulosFail) {
    Matrix m(3, 5, 10), m2(3, 5, 12);

    EXPECT_THROW(m.additionMatrix(m2), invalid_argument);
    EXPECT_THROW(m2.additionMatrix(m), invalid_argument);
    EXPECT_THROW(m.subtractionMatrix(m2), invalid_argument);
    EXPECT_THROW(m2.subtractionMatrix(m), invalid_argument);
    EXPECT_THROW(m.multiplicationMatrix(m2), invalid_argument);
    EXPECT_THROW(m2.multiplicationMatrix(m), invalid_argument);
}