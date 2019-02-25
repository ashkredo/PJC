/**
*
*  @author Shkred Artur S15444
*
*/

//#include "stdafx.h" 
#include <iostream>
#include <utility> // you can use std::swap

using namespace std;

//---------------------------------------------------------//
// -- ord3
void ord3(double& a, double& b, double& c) {
   if (c < b) {
	  swap(b, c);
   }
   if (c < a) {
	  swap(a, c);
   }
   if (b < a) {
	  swap(a, b);
   }
};
// -- ord3
void ord3(double* a, double* b, double* c) {
   if (*c < *b) {
	  swap(*b, *c);
   }
   if (*c < *a) {
	  swap(*a, *c);
   }
   if (*b < *a) {
	  swap(*a, *b);
   }
};
// -- getMinMax
void getMinMax(double &a, double& b, double& c, double*& ptrMin, double*& ptrMax) {
	ord3(a, b, c);
	ptrMax = &c;
	ptrMin = &a;
};
// -- getMinMax
void getMinMax(double *a, double* b, double* c, double** ptrMin, double** ptrMax) {
	ord3(a, b, c);
	*ptrMax = c;
	*ptrMin = a;
}
//---------------------------------------------------------//

//........................Zadanie_03........................// 
int main() {
	cout << "Zadanie_03:" << endl;
	cout << "-----------------------------------------" << endl;


	using std::cout; using std::endl;
	double a, b, c, *ptrMin, *ptrMax;

	a = 2; b = 1; c = 3;
	ord3(a, b, c);
	cout << a << " " << b << " " << c << endl;

	a = 3; b = 2; c = 1;
	ord3(&a, &b, &c);
	cout << a << " " << b << " " << c << endl;

	a = 2; b = 3; c = 1;
	ptrMin = ptrMax = nullptr;
	getMinMax(a, b, c, ptrMin, ptrMax);
	std::cout << "Min = " << *ptrMin << "; "
			  << "Max = " << *ptrMax << std::endl;

	a = 3; b = 1; c = 2;
	ptrMin = ptrMax = nullptr;
	getMinMax(&a, &b, &c, &ptrMin, &ptrMax);
	std::cout << "Min = " << *ptrMin << "; "
	          << "Max = " << *ptrMax << std::endl;


	cout << "-----------------------------------------" << endl;
	system("pause");
	return 0; }
//---------------------------------------------------------//