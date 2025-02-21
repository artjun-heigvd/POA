#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Matrix.hpp"

/**
 * @brief The main function of the program, the arguments are the size of the
 * first matrix, the size of the second matrix and the modulo of the matrices
 * @authors Arthur Junod, Samuel Roland, Edwin Haffner
 * @date 2024-02-29
 */
using namespace std;
#define EXPECTED_ARGS_NB 6
int main(const int argc, char** argv) {
    // Printing help
    if (argc == 0) {
        cout << "Usage:" << endl
             << "Use the following arguments to define the size of 2 matrixes "
                "and a modulo"
             << endl
             << "matrix <M1> <N1> <M2> <M2>" << endl
             << "Example: matrix 2 3 1 4 5" << endl;
        return EXIT_SUCCESS;
    }

    // Checking args number
    if (argc < EXPECTED_ARGS_NB) {
        cout << "Expected " << EXPECTED_ARGS_NB << " positive integer args!"
             << endl;
        return EXIT_FAILURE;
    }

    // Parsing string to integers and checking > 1
    unsigned values[EXPECTED_ARGS_NB - 1]{};
    for (unsigned i = 0; i < EXPECTED_ARGS_NB - 1; i++) {
        try {
            int val = stoi(argv[i + 1]);
            if (val < 1) {
                cout << "Error: Argument " << val << " should be >= 1" << endl;
                return EXIT_FAILURE;
            }
            values[i] = static_cast<unsigned>(val);
        } catch (logic_error&) {
            cout << "Error parsing " << argv[i + 1] << " as integer " << endl;
            return EXIT_FAILURE;
        }
    }

    // Creating matrixes
    Matrix m1(values[0], values[1], values[4]),
        m2(values[2], values[3], values[4]);

    // Doing operations and printing results
    cout << "The modulus is " << values[4] << endl << endl;
    cout << "one" << endl << m1 << endl << "two" << endl << m2 << endl;

    cout << "one + two" << endl << m1.additionMatrix(m2) << endl;

    cout << "one - two" << endl << m1.subtractionMatrix(m2) << endl;

    cout << "one x two" << endl << m1.multiplicationMatrix(m2) << endl;
}
