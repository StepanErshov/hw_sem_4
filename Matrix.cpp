#include "Matrix.h"

Matrix::Matrix(unsigned int m, unsigned int n) {
    this->m = m;
    this->n = n;
    data = new int*[m];
    for (unsigned int i = 0; i < m; i++) {
        data[i] = new int[n];
    }
}

Matrix::~Matrix() {
    for (unsigned int i = 0; i < m; i++) {
        delete[] data[i];
    }
    delete[] data;
}

int& Matrix::operator[](int i) {
    return data[i / n][i % n];
}

void Matrix::fillRandom() {
    srand(time(0));
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            data[i][j] = rand() % 10;
        }
    }
}
void Matrix::fillRandom1() {
    srand(time(0));
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            data[i][j] = rand() % 11;
        }
    }
}


std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
    for (unsigned int i = 0; i < matrix.m; i++) {
        for (unsigned int j = 0; j < matrix.n; j++) {
            out << matrix.data[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}

Matrix& Matrix::operator+=(const Matrix& matrix) {
    if (m != matrix.m || n != matrix.n) {
        std::cerr << "Matrices must have the same dimensions" << std::endl;
        return *this;
    }
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            data[i][j] += matrix.data[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& matrix) const {
    Matrix result(m, n);
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            result.data[i][j] = data[i][j] + matrix.data[i][j];
        }
    }
    return result;
}

Matrix& Matrix::operator-=(const Matrix& matrix) {
    if (m != matrix.m || n != matrix.n) {
        std::cerr << "Matrices must have the same dimensions" << std::endl;
        return *this;
    }
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            data[i][j] -= matrix.data[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator-(const Matrix& matrix) const {
    Matrix result(m, n);
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            result.data[i][j] = data[i][j] - matrix.data[i][j];
        }
    }
    return result;
}

Matrix& Matrix::operator*=(const Matrix& matrix) {
    if (n != matrix.m) {
        std::cerr << "Matrices must have compatible dimensions for multiplication" << std::endl;
        return *this;
    }
    Matrix result(m, matrix.n);
    for (unsigned int i =  0; i < m; i++) {
        for (unsigned int j =  0; j < matrix.n; j++) {
            result.data[i][j] =  0;
            for (unsigned int k =  0; k < n; k++) {
                result.data[i][j] += data[i][k] * matrix.data[k][j];
            }
        }
    }
    *this = result;
    return *this;
}

Matrix Matrix::operator*(const Matrix& matrix) const {
    if (n != matrix.m) {
        std::cerr << "Matrices must have compatible dimensions for multiplication" << std::endl;
        return Matrix(0,  0);
    }
    Matrix result(m, matrix.n);
    for (unsigned int i =  0; i < m; i++) {
        for (unsigned int j =  0; j < matrix.n; j++) {
            result.data[i][j] =  0; 
            for (unsigned int k =  0; k < n; k++) {
                result.data[i][j] += data[i][k] * matrix.data[k][j];
            }
        }
    }
    return result;
}

bool Matrix::operator!=(const Matrix& matrix) const {
    if (m != matrix.m || n != matrix.n) {
        return true;
    }
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            if (data[i][j] != matrix.data[i][j]) {
                return true;
            }
        }
    }
    return false;
}

bool Matrix::operator==(const Matrix& matrix) const {
    return !(*this != matrix);
}

