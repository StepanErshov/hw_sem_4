#include <iostream>
#include <cstdlib>
#include <ctime>

class Matrix {
private:
    int** data;
    unsigned int m;
    unsigned int n;

public:
    Matrix(unsigned int m, unsigned int n);
    ~Matrix();

    int& operator[](int i);

    void fillRandom();
    void fillRandom1();

    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);

    Matrix& operator+=(const Matrix& matrix);
    Matrix operator+(const Matrix& matrix) const;
    Matrix& operator-=(const Matrix& matrix);
    Matrix operator-(const Matrix& matrix) const;
    Matrix& operator*=(const Matrix& matrix);
    Matrix operator*(const Matrix& matrix) const;

    bool operator!=(const Matrix& matrix) const;
    bool operator==(const Matrix& matrix) const;
};
