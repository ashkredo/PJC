#include <iostream>
  // you can (but not have to) use std::swap
#include <utility>

void getMinMax(double &a, double& b, double& c,
               double*& ptrMin, double*& ptrMax) {
    // ...
}

void getMinMax(double *a, double* b, double* c,
               double** ptrMin, double** ptrMax) {
    // ...
}

void ord3(double& a, double& b, double& c) {
    // ...
}

void ord3(double* a, double* b, double* c) {
    // ...
}

void printOrd(const double* a, const double* b,
                               const double* c) {
    using std::cout; using std::endl;
    cout << *a << " " << *b << " " << *c << endl;
}
void printMinMax(const double* pmn, const double* pmx) {
    using std::cout; using std::endl;
    std:: cout << "Min = " << *pmn << "; "
               << "Max = " << *pmx << std::endl;
}

int main() {
    double a, b, c, *ptrMin, *ptrMax;

    a = 2; b = 1; c = 3;
    ord3(a,b,c);
    printOrd(&a, &b, &c);
    a = 3; b = 2; c = 1;
    ord3(&a,&b,&c);
    printOrd(&a, &b, &c);
    a = -1; b = -1; c = 1;
    ord3(&a,&b,&c);
    printOrd(&a, &b, &c);

    a = 2; b = 3; c = 1;
    getMinMax(a,b,c,ptrMin,ptrMax);
    printMinMax(ptrMin, ptrMax);
    a = 3; b = 1; c = 2;
    getMinMax(&a,&b,&c,&ptrMin,&ptrMax);
    printMinMax(ptrMin, ptrMax);
    a = 3; b = 3; c = -1;
    getMinMax(&a,&b,&c,&ptrMin,&ptrMax);
    printMinMax(ptrMin, ptrMax);
}
