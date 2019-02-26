/**
*
*  @author Shkred Artur S15444
*
*/

#include <iostream>

using namespace std;

//---------------------------------------------------------//
enum Banks { PKO, BGZ, BRE, BPH };

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

	int value1, value2;
	bool trueOrFalse = false;

	if (0 == size) {
		return nullptr;
	} else {
		for (int i = 0; i < size; i++) {
			if ((bank == cpls[i].she.account.bank) || (bank == cpls[i].he.account.bank)) {
				if (!trueOrFalse) {
					value1 = (cpls[i].she.account.balance + cpls[i].he.account.balance);
					value2 = i;
				} else {
					if ((cpls[i].she.account.balance + cpls[i].he.account.balance) >= value1) {
						value1 = (cpls[i].she.account.balance + cpls[i].he.account.balance);
						value2 = i;
					}
				} trueOrFalse = true;
			}
		}
	}
	if (trueOrFalse) {
		return &cpls[value2];
	} else {
		return nullptr;
	}
}
//---------------------------------------------------------//

//........................Zadanie_08.......................// 
int main() {
	using std::cout; using std::endl;
	Couple cpls[] = {
		{ {"Johny", {PKO, 1200}}, {"Mary", {BGZ, 1500}} },
		{ {"Peter", {BGZ, 1400}}, {"Suzy", {BRE, 1300}} },
		{ {"Kevin", {PKO, 1600}}, {"Katy", {BPH, 1500}} },
		{ {"Kenny", {BPH, 1800}}, {"Lucy", {BRE, 1700}} }
	};

	const Couple* p = bestClient(cpls, 4, BGZ);
	if (p)
		cout << p->he.name << " and " << p->she.name
		<< ": " << p->he.account.balance +
		p->she.account.balance << endl;
	else
		cout << "No such couple..." << endl;

	system("pause");
	return 0; }
//---------------------------------------------------------//