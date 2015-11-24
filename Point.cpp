//
// Created by Narayan Ramjali on 9/29/15.
//

#include "Point.h"
#include <cmath>
Clustering::Point::Point(int dimensions) {
    if (dimensions == 0)
        dimensions = 2;
    dim = dimensions;
    values = nullptr;
}

Clustering::Point::Point(const int dims, double *vals) {
    dim = dims;
    values = new double[dim];
    for (int i = 0; i < dims; i++) {
        values[i] = vals[i];
    }
}


Clustering::Point::Point(const Clustering::Point &rhs) {
    dim = rhs.dim;
    values = new double[dim];
    for (int i = 0; i < dim; i++) {
        values[i] = rhs.values[i];
    }
    
}

Clustering::Point &Clustering::Point::operator=(const Clustering::Point &rhs) {
    if (this == &rhs) {
        return *this;
    } else {
        delete[] values;
        
        dim = rhs.dim;
        values = new double[dim];
        for (int i = 0; i < dim; i++)
            values[i] = rhs.values[i];
    }
    return *this;
}

Clustering::Point::~Point() {
    delete[] values;
    
}

void Clustering::Point::setValue(int dimension, double d) {
    if (dimension >= 1 && dimension <= dim)
        values[dimension - 1] = d;
    
}

double Clustering::Point::getValue(int dimension) const {
    if (dimension >= 1 && dimension <= dim)
        return values[dimension - 1];
    return 0;
}

double Clustering::Point::distanceTo(const Clustering::Point &other) const {
    if (other.dim == dim) {
        double sum = 0;
        for (int i = 0; i < dim; i++) {
            double diff = values[i] - other.values[i];
            sum += diff * diff;
        }
        return sqrt(sum);
    }
    return 0;
}

Clustering::Point &Clustering::Point::operator*=(double d) {
    for (int i = 0; i < dim; i++)
        values[i] *= d;
    return *this;
}

Clustering::Point &Clustering::Point::operator/=(double d) {
    for (int i = 0; i < dim; i++)
        values[i] /= d;
    return *this;
    
}

const Clustering::Point Clustering::Point::operator*(double d) const {
    Clustering::Point values(*this);
    values *= d;
    return values;
}

const Clustering::Point Clustering::Point::operator/(double d) const {
    Clustering::Point values(*this);
    values /= d;
    return values;
}

// p1 += p1 is allowed , but different dimentions throws an exceptions
Clustering::Point &Clustering::operator+=(Clustering::Point &lhs, const Clustering::Point &rhs) {
    if (&lhs == &rhs) {
        return lhs *= 2;
    } else if (lhs.dim == rhs.dim) {
        for (int i = 0; i < lhs.dim; i++)
            lhs.values[i] += rhs.values[i];
    }
    return lhs;
}

Clustering::Point &Clustering::operator-=(Clustering::Point &lhs, const Clustering::Point &rhs) {
    if (&lhs == &rhs) {
        return lhs *= 2;
    } else if (lhs.dim == rhs.dim) {
        for (int i = 0; i < lhs.dim; i++)
            lhs.values[i] -= rhs.values[i];
    }
    return lhs;
}

const Clustering::Point Clustering::operator+(const Clustering::Point &lhs, const Clustering::Point &rhs) {
    Point p(lhs);
    return p += rhs;
    
}

const Clustering::Point Clustering::operator-(const Clustering::Point &lhs, const Clustering::Point &rhs) {
    Point p(lhs);
    return p -= rhs;
}

bool Clustering::operator==(const Clustering::Point &one, const Clustering::Point &another) {
    if (one.dim != another.dim)
        return false;
    bool isEqual = true;
    for (int i = 0; i < one.dim; i++) {
        if (one.values[i] != another.values[i]) {
            break;
        }
    }
    return isEqual;
}

bool Clustering::operator!=(const Clustering::Point &one, const Clustering::Point &another) {
    return !(one == another);
}

bool Clustering::operator<(const Clustering::Point &one, const Clustering::Point &another) {
    bool isLess = true;
    for (int i = 0; i < one.dim; i++) {
        if (one.values[i] >= another.values[i]) {
            isLess = false;
            break;
        }
    }
    return isLess;
}

bool Clustering::operator>(const Clustering::Point &one, const Clustering::Point &another) {
    bool isMore = true;
    for (int i = 0; i < one.dim; i++) {
        if (one.values[i] <= another.values[i]) {
            isMore = false;
            break;
        }
    }
    return isMore;
}

//
bool Clustering::operator<=(const Clustering::Point &one, const Clustering::Point &another) {
    bool isLess = true;
    for (int i = 0; i < one.dim; i++) {
        if (one.values[i] > another.values[i]) {
            isLess = false;
            break;
        }
    }
    return isLess;
}

//
bool Clustering::operator>=(const Clustering::Point &one, const Clustering::Point &another) {
    bool isMore = true;
    for (int i = 0; i < one.dim; i++) {
        if (one.values[i] < another.values[i]) {
            isMore = false;
            break;
        }
    }
    return isMore;
}

//
std::ostream &Clustering::operator<<(std::ostream &ostream, const Clustering::Point &out) {
    // (3, 2, 1, 5)
    ostream << "(";
    // for (int i = 0; i < out.getDims() -1; i++) {
    for (int i = 0; i < out.getDims() -1; i++) {
        ostream << out.values[i] << ", ";
    }
    ostream << out.values[out.getDims()-1] << ")";
    return ostream;
    
}

//
std::istream &Clustering::operator>>(std::istream &istream, Clustering::Point &inn) {
    istream >> inn;
    return istream;
}

