//
// Created by ajun on 5/13/24.
//

#include "Vector.h"


Vector::~Vector(){
    delete[] collect;
}

Vector::Vector(const Vector& other) : collect(new int[other.sz]), sz(other.sz){
    std::copy(other.collect, other.collect + other.sz, collect);
}

Vector::Vector() : collect(nullptr), sz(0){}

Vector::Vector(size_t size) : collect(new int[size]), sz(size){}

int& Vector::operator[](size_t ind){
    return collect[ind];
}

const int &Vector::operator[](size_t ind) const {
    return collect[ind];
}

size_t Vector::size() const {
    return sz;
}

Vector &Vector::operator=(Vector other) {
    std::swap(other.collect, collect);
    std::swap(other.sz, sz);
    return *this;
}
