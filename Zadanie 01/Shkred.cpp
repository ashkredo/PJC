/**
*
*  @author Shkred Artur S15444
*
*/

#include "stdafx.h"
#include <iostream>
#include <conio.h>

#define ANG

//---------------------------------------------------------//
#if  defined(ANG) && defined(POL)
    #error Please define only one country
#elif !(defined(ANG) || defined(POL))
    #error Please define a country
#endif
//---------------------------------------------------------//

using namespace std;

//---------------------------------------------------------//
unsigned int suma;
unsigned int sumaLiczb(int liczba) {
	suma = 0;
	do {
		suma += (liczba % 10);
		liczba /= 10;
	} while (liczba != 0);
  return suma; }
//---------------------------------------------------------//

//........................Zadanie_01........................// 
int main() {
	cout << "-----------------------------------------" << endl;
	cout << "Zadanie_01:" << endl;
//-- POL
#if defined(POL) && !defined(ANG)
	unsigned int liczba = 0;
	unsigned int nowaLiczba = 0;
	unsigned int suma = 0;
	unsigned int nowaSuma = 0;
	do {
	  while (true) {
		cout << "Podaj liczbe naturalna (0 jesli zrobione): ";
		cin >> nowaLiczba;
		if (!cin) {
			cin.clear();
			while (cin.get() != '\n');
		} else break;
	  }
		nowaSuma = sumaLiczb(nowaLiczba);
		if (nowaSuma > suma) {
			suma = nowaSuma;
			liczba = nowaLiczba;
		}
	} while (nowaLiczba != 0);
	cout << "Najwieksza suma liczb to: " << suma << " dla: " << liczba << endl;
//-- ANG	
#elif defined(ANG) && !defined(POL)
	unsigned int liczba = 0;
	unsigned int nowaLiczba = 0;
	unsigned int suma = 0;
	unsigned int nowaSuma = 0;
	do {
		while (true) {
			cout << "Enter a natural number (0 if done): ";
			cin >> nowaLiczba;
			if (!cin) {
				cin.clear();
				while (cin.get() != '\n');
			} else break;
		}
		nowaSuma = sumaLiczb(nowaLiczba);
		if (nowaSuma > suma) {
			suma = nowaSuma;
			liczba = nowaLiczba;
		}
	} while (nowaLiczba != 0);
	cout << "Max sum of digits was: " << suma << " for: " << liczba << endl;
#endif 
cout << "-----------------------------------------" << endl;
_getch(); return 0; }
//---------------------------------------------------------//
