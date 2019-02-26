#include <iostream>
#include <utility>   // std::swap may be useful

template <typename T, typename FUN>
size_t part(T* arr, size_t size, FUN f) {
    // ...
}

template <typename T>
void printTab(const T* t, size_t size) {
    // ...
}

bool isEven(int e) { return e%2 == 0; }

int main() {
    size_t ind = 0;

    int a1[] = {1,2,3,4,5,6};
    ind = part(a1,6,isEven);
    std::cout << "ind = " << ind << " ";
    printTab(a1,6);

    int a2[] = {1,2,3,4,5,6};
      // lambda as argument: a predicate checking
      // if the given number is odd
    ind = part(a2, std::size(a2), /* ... */);
    std::cout << "ind = " << ind << " ";
    printTab(a2,std::size(a2));

    std::string a3[] = {"Ala", "Ula", "Ela", "Ola", "Maja"};
    std::string mn = "Bea";
    std::string mx = "Sue";
      // lambda as argument: a predicate checking
      // if the given name is in the range [mn,mx]
    ind = part(a3, std::size(a3), /* ... */);
    std::cout << "ind = " << ind << " ";
    printTab(a3,std::size(a3));

    constexpr size_t DIM = 500000;
    int* a4 = new int[DIM];
    srand(unsigned(time(0)));
    for (size_t i = 0; i < DIM; ++i) a4[i] = rand()%21+1;
      // lambda as argument: a predicate checking
      // if the given number is divisible by 7
    ind = part(a4, DIM, /* ... */);
    std::cout << "ind = " << ind << std::endl;
    delete [] a4;
}
