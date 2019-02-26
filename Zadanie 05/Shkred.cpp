/**
*
*  @author Shkred Artur S15444
*
*/

#include <functional>
#include "iostream"

using namespace std;

//----------------------------------------------------------//
double f1(double x) { return x / 4; } 
double f2(double x) { return -2 * x; } 

using D2D = std::function<double(double)>;

D2D maxfun(D2D funs[], size_t size, double a, double b, double* pxmax) {
	static constexpr double eps = 1e-6;
	D2D maxF = funs[0];
	double max = a, maxV = maxF(a);

	for (int i = 0; i < size; i++) {
		for (double y = a; y < b; y += eps) {
			if (maxV < funs[i](y)) {
				maxV = funs[i](y);
				max = y; maxF = funs[i];
			}
		}
	} *pxmax = max;

	return maxF;
}
//----------------------------------------------------------//	

//........................Zadanie_05........................// 
int main() {
	cout << "Zadanie_05:" << endl;
	D2D funcs[]{
		f1,
		[](double f) -> double { return f * f; },
		f2
	};
	double xmax;
	D2D pf = maxfun(funcs, 3, 0, 3, &xmax);
	std::cout << "xmax = " << xmax << "; f(xmax) = "
		      << pf(xmax) << std::endl;

	system("pause");
	return 0; }
//---------------------------------------------------------//