/**
*
*  @author Shkred Artur S15444
*
*/

#include <iostream>
#include <cstring>

using namespace std;

//---------------------------------------------------------//
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
Person::Person(const char * n) {
	name = new char[strlen(n) + 1];
	strcpy(name, n);
}

Person& Person:: operator=(const Person& os) {
	delete (this -> name);
	this -> name = new char[strlen(os.name) + 1];
	strcpy(this -> name, os.name);
}

Person::Person(const Person& os) {
	this -> name = new char[strlen(os.name) + 1];
	strcpy(name, os.name);
}

Person::~Person() {
	cout << "DEL " << name << endl;
	delete name;
}

ostream& operator<<(ostream& str, const Person& os) {
	return str << os.name;
}

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
Couple::Couple(const Person& she, const Person& he) {
	this -> wife = new Person(she);
	this -> husband = new Person(he);
}

Couple& Couple::operator=(const Couple& other) {
	delete this -> wife;
	this -> wife = new Person(*other.wife);
	delete this -> husband;
	this -> husband = new Person(*other.husband);
}

Couple::Couple(const Couple& other) {
	wife = new Person(*other.wife);
	husband = new Person(*other.husband);
}

Couple::~Couple() {
	delete wife;
	delete husband;
}

ostream& operator<<(ostream& str, const Couple& p) {
	return str << "Couple: he " << *p.husband << ", she " << *p.wife;
}
//---------------------------------------------------------//

//........................Zadanie_10.......................// 
int main(void) {
	using std::cout; using std::endl;
	Person *pjohn = new Person("John"),
		*pjane = new Person("Jane");
	Person mary("Mary"), mark("Mark");
	Couple *pcouple1 = new Couple(mary, *pjohn);
	Couple couple2(*pjane, mark);
	delete pjohn;
	delete pjane;
	cout << *pcouple1 << endl;
	cout << couple2 << endl;
	couple2 = *pcouple1;
	delete pcouple1;
	cout << couple2 << endl;

	system("pause");
	return 0; }
//---------------------------------------------------------//