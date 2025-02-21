//
// Created by ajun on 2/29/24.
//

#ifndef EX01_VECTOR_VECTOR_H
#define EX01_VECTOR_VECTOR_H

class Vector{
private:
    int* data;
    size_t length;

public:
    Vector();
    explicit Vector(size_t size);
    Vector(const Vector& other);

    Vector& operator=(const Vector& other);
    int& operator[](size_t index);
    size_t size() const;

    ~Vector();
};

#endif //EX01_VECTOR_VECTOR_H
