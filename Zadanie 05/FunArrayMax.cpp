#include <functional>
#include <iostream>

double f1(double x) { return  x/4; }
double f2(double x) { return -2*x; }

using D2D = std::function<double(double)>;

D2D maxfun(D2D funs[], size_t size,
           double a, double b, double* pxmax) {
    static constexpr double eps = 1e-6;
    // ...
}

int main() {
    D2D funcs[]{
        f1,
        // lambda expression here
        f2
    };
    double xmax;
    D2D pf = maxfun(funcs, 3, 0, 3, &xmax);
    std::cout << "xmax = " << xmax << "; f(xmax) = "
              << pf(xmax)  << std::endl;
}
