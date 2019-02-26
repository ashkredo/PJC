#include <iostream>

enum Banks {PKO, BGZ, BRE, BPH};

struct Account {
    Banks   bank;
    int  balance;
};

struct Person {
    char   name[20];
    Account account;
};

struct Couple {
    Person  he;
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
