//
// Created by ajun on 2/29/24.
//

#include <algorithm>
#include "Vector.h"

Vector::Vector() {
    data = nullptr;
    length = 0;
}

Vector::Vector(size_t size) {
    data = new int[size];
    this->length = size;
}

Vector::Vector(const Vector& other) {
    data = new int[other.length];
    this->length = other.length;
    std::copy(other.data, other.data + length, data);
}


size_t Vector::size() const {
    return length;
}

Vector &Vector::operator=(const Vector &other) {
    if(this == &other){return *this;}
    if(other.length != this->length){
        int* tmp = new int[other.length];
        delete[] data;
        data = tmp;
        this->length = other.length;
    }
    std::copy(other.data, other.data + length, this->data);
    return *this;
}

int &Vector::operator[](size_t index) {
        return data[index];
}

Vector::~Vector() {
    delete[] data;
}

