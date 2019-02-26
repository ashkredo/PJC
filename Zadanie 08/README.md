# Zadanie 08

Definiujemy jedno wyliczenie i trzy C-struktury:

	enum Banks {PKO, BGZ, BRE, BPH};
	
	struct Account {
	    Banks bank;
	    int balance;
	};
	
	struct Person {
	    char name[20];
	    Account account;
	};
	
	struct Couple {
	    Person he;
	    Person she;
	};

W funkcji main tworzymy tablicę par (Couple) z danymi, na przykład, takimi:

	No         He   	    She
	   Name  Bank Balance Name Bank Balance
	0  Johny PKO   1200   Mary BGZ   1500
	1  Peter BGZ   1400   Suzy BRE   1300
	2  Kevin PKO   1600   Katy BPH   1500
	3  Kenny BPH   1800   Lucy BRE   1700

Zdefiniować funkcję o nagłówku:

	const Couple* bestClient(const Couple* cpls,
				 int size, Banks bank);

która zwraca wskaźnik do tej pary (Couple) z tablicy przekazanej jako pierwszy
argument (o wymiarze size), która ma największą sumę oszczędności jego (he) i jej
(she), ale tylko spośród takich par, w których przynajmniej jedno z małżonków ma
konto w banku bank. Jeśli żadna z osób nie ma konta w banku bank, to funkcja
zwraca nullptr. Nie wolno zakładać, że stan konta jest nieujemny; może być dowolnie
duży dodatni i dowolnie duży ujemny. Jeśli dwie lub więcej par spośród tych, które
spełniają narzucony warunek ma takie same, największe, oszczędności, to funkcja
zwraca wskaźnik do dowolnej z nich.

Przykładowy schemat programu("BanksPersons.cpp"):
	
	#include <iostream>

	enum Banks {PKO, BGZ, BRE, BPH};

	struct Account {
	    Banks bank;
	    int balance;
	};

	struct Person {
	    char name[20];
	    Account account;
	};

	struct Couple {
	    Person he;
	    Person she;
	};

	const Couple* bestClient(const Couple* cpls,
				 int size, Banks bank) {
	    // ...
	}

	int main() {
	    using std::cout; using std::endl;
	    Couple cpls[] = {
		// ...
	    };

	    const Couple* p = bestClient(cpls,4,BGZ);
	    if (p)
		cout << p->he.name << " and " << p->she.name
		     << ": " << p->he.account.balance +
				p->she.account.balance << endl;
		else
		    cout << "No such couple..." << endl;
	}

powinien wypisać coś w rodzaju:

	Peter and Suzy: 2700
