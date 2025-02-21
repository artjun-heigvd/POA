//
// Created by ajun on 5/13/24.
//

#ifndef EXO_VECTOR_VECTOR_H
#define EXO_VECTOR_VECTOR_H


#include <cstdlib>
#include <algorithm>

class Vector {
private:
    int* collect;
    size_t sz;
public:
    explicit Vector(size_t size);
    Vector();
    Vector(const Vector& other);

    ~Vector();

    size_t size() const;

    int& operator[](size_t ind);
    const int& operator[](size_t ind) const;
    Vector& operator=(Vector other);
};


#endif //EXO_VECTOR_VECTOR_H
