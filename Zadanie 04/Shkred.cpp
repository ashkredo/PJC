/**
*
*  @author Shkred Artur S15444
*
*/

//#include "stdafx.h" 
#include <iostream>

using namespace std;

//----------------------------------------------------------//
// -- length
size_t length(const char* cstr) {
	int length = 0;
	while (*cstr++ != '\0') {
		length++;
	} return length;
};
// -- reverse
char* reverse(char* cstr) {
	for (int i = 0; i < ((length(cstr) - 1) / 2); i++) {
		char next = *(cstr + i);
		*(cstr + i) = cstr[((length(cstr) - 1) - i)];
		cstr[((length(cstr) - 1) - i)] = next;
	}	return cstr;
};
// -- isLetter
bool isLetter(char c) {
	if ((c >= 'a') && (c <= 'z')) { // -- islower(c)
		cout << "isLetter : \'" << c << "\' - mala" << endl;
		return true; 
	} else if ((c >= 'A') && (c <= 'Z')) { // -- isupper(c)
		cout << "isLetter : \'" << c << "\' - duza" << endl;
		return true; 
	} cout << "Exception, write the letter!" << endl;
	return false;
};
// -- words
size_t words(const char* cstr) {  // " ... for (int i = 0; i < n; ++i){...} ...";
	int words = 0, next = 0;
	for (int i = 0; i < length(cstr); i++) {
		if (((cstr[i] >= 'a') && (cstr[i] <= 'z')) || ((cstr[i] >= 'A') && (cstr[i] <= 'Z'))) {
			next = i + 1;
			if (((cstr[next] < 'A') || (cstr[next] > 'z')) || ((cstr[next] < 'a') && (cstr[next] > 'Z'))) { words++; }
		}
	} return words;
};
// -- words2
size_t words2(const char* cstr) { // " ... for (int i = 0; i < n; ++i){...} ..."
	int words = 0, next = 0;
	for (int i = 0; i < length(cstr); i++) {
		if (((cstr[i] >= 'a') && (cstr[i] <= 'z')) || ((cstr[i] >= 'A') && (cstr[i] <= 'Z'))) {
			next = i + 1;
			if (((cstr[next] >= 'a') && (cstr[next] <= 'z')) || ((cstr[next] >= 'A') && (cstr[next] <= 'Z'))) {
				next += 1;
				if (((cstr[next] < 'A') || (cstr[next] > 'z')) || ((cstr[next] < 'a') && (cstr[next] > 'Z'))) { words++; }
			}
		}
	} return words;
};
// -- concat 
char* concat(char* t, const char* s) {
	int next = 0;
	for (int i = length(t); i < (length(s) + length(t)); i++) {
		t[i] += s[next++];
	} return t;
};
//----------------------------------------------------------//	

//........................Zadanie_04........................// 
int main() {
	cout << "Zadanie_04:" << endl;
	cout << "-----------------------------------------" << endl;
	//cout << isLetter('A') << endl;


	using std::cout; using std::endl;
	char s1[] = "Alice in Wonderland";
	cout << "reverse: " << reverse(s1) << endl;
	cout << "length : " << length(s1) << endl;

	char s2[] = " ... for (int i = 0; i < n; ++i){...} ...";
	cout << "words : " << words(s2) << endl;
	cout << "words2 : " << words2(s2) << endl;

	char s3[100] = "Hello";
	cout << "concat : "
		<< concat(concat(s3, ", world"), "!") << endl;


	cout << "-----------------------------------------" << endl;
	system("pause");
	return 0; }
//---------------------------------------------------------//