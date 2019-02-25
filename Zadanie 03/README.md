# Zadanie 03

Napisz przeciążone funkcje

	void ord3(double& a, double& b, double& c);
	void ord3(double* a, double* b, double* c);
	
które pobierają trzy liczby typu double odpowiednio przez referencje i przez wskaźniki i 
porządkują je w kolejności wzrastającej (tak, że po wyjściu z funkcji ich wartości są zmienione).

Napisz przeciążone funkcje

	void getMinMax(double &a, double& b, double& c, 
				   double*& ptrMin, double*& ptrMax);
	void getMinMax(double *a, double* b, double* c,
				   double** ptrMin, double** ptrMax);

które pobierają trzy liczby typu double odpowiednio przez referencje i przez wskaźniki i do 
wskaźników ptrMin i ptrMax przekazanych przez, odpowiednio, referencje
i wskaźniki, wstawiają adresy zmiennych odpowiadających najmniejszej i największej z przekazanych liczb. 
Wartości przekazanych liczb nie ulegają zmianie.
	
UWAGA: Nie uzywac tablic, napisów ani zadnych innych kolekcji. Funkcje nie mogą niczego
pisać na ekran- wszystkie wyniki są drukowane w funkcji main.

powinien wypisać:

	1 2 3
	1 2 3
	Min = 1; Max = 3
	Min = 1; Max = 3
	
Sprawdź program również dla innych danych; w szczególności dla sytuacji, gdy niektóre lub wszystkie wartości są równe.