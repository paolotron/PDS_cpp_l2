//
// Created by paolo on 21/04/2021.
//

#ifndef LAB2_MATRIX_H
#define LAB2_MATRIX_H

#include "vector.h"

template <typename T>
class Matrix {
private:
    int dimx, dimy;
    Vector<Vector<T>*> matrix;
public:
    Matrix<T>(int x, int y){
        dimx = x;
        dimy = y;
        matrix = Vector<Vector<T>*>(dimy);
        for(int i=0; i<dimy; i++){
            matrix[i] = new Vector<T>(dimx);
        }
    }

    Vector<T> &operator[](int i){
        return *matrix[i];
    }
/*
    Matrix(Matrix<T> &m1){
        dimx = m1.dimx;
        dimy = m1.dimy;
        for(int i=0; i<dimy; i++){
            matrix[i] = m1.matrix[i];
        }
    }

    Matrix(Matrix<T> &&m1) noexcept {
        dimx = m1.dimx;
        dimy = m1.dimy;
        matrix = m1.matrix;
        m1.matrix = nullptr;
        m1.dimx = 0;
        m1.dimy = 0;
    }

    Matrix<T>& operator=(Matrix<T> const &m1){
        delete[] matrix;
        matrix = m1.matrix;
        dimx = m1.dimx;
        dimy = m1.dimy;
        return *this;
    }

    ~Matrix(){
        dimx = dimy = 0;
    }
*/
};


#endif //LAB2_MATRIX_H
