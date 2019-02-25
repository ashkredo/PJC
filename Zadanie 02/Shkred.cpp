/**
*
*  @author Shkred Artur S15444
*
*/

//#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

//........................Zadanie_02........................// 
int main() {
	cout << "Zadanie_02:" << endl;
	cout << "-----------------------------------------" << endl;
	int nowaLiczba, liczba;
	int ilosc = 0, maxIlosc = 0;
	int nLiczbaS = 0;
	cout << "Podaj liczbe (0 jesli zrobione): ";
	if (cin >> liczba) {
		ilosc = 1;
		cout << "Podaj liczbe (0 jesli zrobione): ";
		while (cin >> nowaLiczba) {
			cout << "Podaj liczbe (0 jesli zrobione): ";
			if (nowaLiczba == 0) {
				break;
			}
			else if (!cin) {
				cin.clear();
				while (cin.get() != '\n');
			}
			if (liczba == nowaLiczba) {
				ilosc++;
				if (ilosc > maxIlosc) {
					maxIlosc = ilosc;
					nLiczbaS = nowaLiczba;
				}
			}
			else {
				liczba = nowaLiczba;
				ilosc = 1;
			}
		}
	}  system("cls");
	cout << "Zadanie_02:" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Podana liczba: '0', koniec wykonywania programu!" << endl;
	cout << "Najdluzsza sekwencja: " << maxIlosc << " razy liczba " << nLiczbaS << endl;
	cout << "-----------------------------------------" << endl;
	_getch(); return 0;
}
//---------------------------------------------------------//