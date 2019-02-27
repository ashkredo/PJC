#include <iostream>
#include <cstring>

class Person {
    char* name;
    friend class Couple;
public:
    explicit Person(const char* n);
    Person(const Person& os);
    Person& operator=(const Person& os);
    ~Person();
    friend std::ostream& operator<<(std::ostream& str,
                                    const Person& os);
};

// implementation

class Couple {
    Person *wife, *husband;
public:
    Couple(const Person& she, const Person& he);
    Couple(const Couple& other);
    Couple& operator=(const Couple& other);
    ~Couple();
    friend std::ostream& operator<<(std::ostream& str,
                                    const Couple& p);
};

// implementation

int main(void) {
    using std::cout; using std::endl;
    Person *pjohn = new Person("John"),
           *pjane = new Person("Jane");
    Person mary("Mary"), mark("Mark");
    Couple *pcouple1 = new Couple(mary, *pjohn);
    Couple couple2(*pjane,mark);
    delete pjohn;
    delete pjane;
    cout << *pcouple1 << endl;
    cout << couple2 << endl;
    couple2 = *pcouple1;
    delete pcouple1;
    cout << couple2 << endl;
}
