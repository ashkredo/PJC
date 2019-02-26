/**
*
*  @author Shkred Artur S15444
*
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <functional>

using namespace std;

//---------------------------------------------------------//
template <typename T, typename FUN>
size_t part(T* arr, size_t size, FUN f) {
	size_t returnSize = 0, length = 0;
	while(length < size) {
		if (f(arr[length])) {
			swap(arr[returnSize++], arr[length]);
		} length++;
	} return returnSize;
}

template <typename T>
void printTab(const T* t, size_t size) {
	cout << "[ "; size_t length = 0;
	while (length < size) {
		cout << t[length] << " "; 
		length++;
	} cout << "]" << endl;
}

bool isEven(int e) { return e % 2 == 0; }
bool isDzieli(int e) { return e % 7 == 0; }
bool isParzysta(int e) { return e % 2 == 1; }
//---------------------------------------------------------//

//........................Zadanie_06........................// 
int main() {
	size_t ind = 0;

	int a1[] = { 1,2,3,4,5,6 };
	ind = part(a1, 6, isEven);
	cout << "ind = " << ind << " ";
	printTab(a1, 6);

	int a2[] = { 1,2,3,4,5,6 };
	// lambda as argument: a predicate checking
	// if the given number is odd
	ind = part(a2, 6, isParzysta);
	cout << "ind = " << ind << " ";
	printTab(a2, 6);

	double a3[] = { -1.5,2.5,3.5,6.5,4.5,0 };
	double mn = 2.0;
	double mx = 5.0;
	// lambda as argument: a predicate checking
	// if the given number is in the range [mn,mx]
	auto isInTheRange = [&mn, &mx] (double e) -> bool { return e >= mn && e <= mx; };
	ind = part(a3, 6, isInTheRange);
	cout << "ind = " << ind << " ";
	printTab(a3, 6);

	constexpr size_t DIM = 500000;
	int* a4 = new int[DIM];
	srand(unsigned(time(0)));
	for (size_t i = 0; i < DIM; ++i) a4[i] = rand() % 21 + 1;
	// lambda as argument: a predicate checking
	// if the given number is divisible by 7
	ind = part(a4, DIM, isDzieli);
	cout << "ind = " << ind << endl;
	delete[] a4;

	system("pause");
	return 0; }
//---------------------------------------------------------//