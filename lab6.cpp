/*
//plik complex.c

struct complex {  //tworzymy strukture liczb zespolonych
	float real; //czesc rzeczywista
	float imag; //czesc urojona
};

*/
/*

//plik complex.h

#include <stdio.h>
#include <math.h>
#include <cmath>
#include "complex.c" //korzysta z pliku complex.c w ktorym jest zaimplementowana struktura


complex add(const complex a, const complex b) { //dodawanie liczb zespolonych
	complex result;
	result.real = a.real + b.real;
	result.imag = a.imag + b.imag;
	return result;
}
complex subtract(const complex a, const complex b) { //odejmowanie  liczb zespolonych
	complex result;
	result.real = a.real - b.real;
	result.imag = a.imag - b.imag;
	return result;
}
complex multiply(const complex a, const complex b) { //mnożenie  liczb zespolonych
	complex result;
	result.real = (a.real * b.real) - (a.imag * b.imag);
	result.imag = (a.imag * b.real) + (a.real*b.imag);
	return result;
}
int equals(const complex a, const complex b) { // sprawdzanie czy sa równe
	float r = abs(a.real - b.real);
	float i = abs(a.imag - b.imag);
	if (r<0.0000001 && i<0.0000001)
		return 1;
	return 0;
}


*/



// #include "pch.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <random>
#include <stdlib.h>
#include "complex.h" //odwolanie sie do pliku complex.h w celu użycia funkcji na liczbach zespolonych

using namespace std;

int* randomVector() {
	int *tab;
	tab = (int*)calloc(100,sizeof(int)); // utworzenie wektora 100 elementowego
	for (int i = 0;i < 100;i++) {
		tab[i] = rand() % 100; // wpisujemy wartosci losowe do tablicy 
	}
	return tab;
}

void writeVector(const int* vec, const char fileName[]) {
	FILE *file = fopen(fileName, "wt"); //otwieramy plik tekstowy do zapisu
	for (int i = 0;i < 100;i++) {
		printf("%d ", vec[i]); //wypisuje elementy do konsoli zeby je porownac z zapisem w notatniku
		fprintf(file, "%d ", vec[i]); //wpisuje do pliku "file", w formacie "%d " liczbe z wektora "vec[i]"

	}
	fclose(file); //zamkyamy otwarty plik
}

void task1() {
	int *tab = randomVector(); // przypisanie losowego wektora
	writeVector(tab, "zad1.txt"); //zapis tego wektora do pliku
	free(tab); //zwolnienie pamieci wektora
} //jesteśmy w stanie jednoznacznie odczytać zawartość utworzonego pliku.

void print(const int *tab) { //wypisujemy na konsole wektor
	for (int i = 0;i < 100;i++) {
		printf("%d\n", tab[i]);
	}
}

int* readVector(const char fileName[]) {
	FILE *file = fopen(fileName, "rt"); //otwieramy plik tekstowy do odczytu
	int *vector = (int*)calloc(100, sizeof(int)); //tworzymy wektor 100 elementowy

	if (file == NULL) {
		printf("Blad otwarcia pliku\n"); //jesli nie ma owego pliku, nie mozemy przejsc do odczytu
	}
	else {
		int i = 0;
		while (!feof(file)){ //dopoki program nie dojdzie do konca pliku 
			fscanf(file, "%d", &vector[i]); //odczytujemy z pliku "file" liczbe "%d" i zapisujemy ja do wektora
			i++;
		}
	}

	fclose(file); //zamykamy plik

	return vector; //zwracamy wektor
}

void task2() {
	int *tab = readVector("zad1.txt"); //wczytujemy odczytany wektor z pliku 
	print(tab); //nastepnie go wypisujemy
	free(tab); //zwalniamy miejsce wektora w pamieci
}

float random() {  //funkcja losująca liczby zmiennoprzecinkowe
	static default_random_engine e{};
	uniform_real_distribution<float> d;
	return d(e);
}

float* randVec(int n) {  //losujemy i wpisujemy n liczb zmiennoprzecinkowych do wektora
	float* vec = (float*)calloc(n, sizeof(float));
	for (int i = 0;i < n;i++) {
		vec[i] = random();
	}
	return vec;
}

void vecToTxt(float* vec,int n) {
	FILE* file = fopen("zad3.txt", "wt"); //otwieramy plik tekstowy gotowy do zapisu
	fprintf(file, "%d\n", n); //wpisujemy ilosc liczb, które będą wpisane, aby ułatwić odczyt
	for(int i=0;i<n;i++){
		printf("%f\n", vec[i]);
		fprintf(file, "%f\n", vec[i]); //wpisujemy do pliku file liczby z wektora w formacie "%f\n"
	} //komenda dziala jak print na konsoli, z różnicą, iż zapisuje dane do pliku
	fclose(file); //zamykamy plik
}

void vecToBin(float* vec, int n) {
	FILE* file = fopen("zad3.bin", "wb"); //otwieramy plik binarny do zapisu
	fwrite(&n, sizeof(int), 1, file); //wpisujemy do pliku ilosc liczb, aby ułatwić odczyt
	for (int i = 0;i < n;i++) {
		fwrite(&vec[i], sizeof(float), 1,file); // wpisujemy do pliku "file" jedną "1" wartosc z wektora "&vec[i]"
												//o rozmiarze float "sizeof(float)"
	}
	fclose(file); //zamykami plik
}

void task3() {
	int n;
	float* vec;
	printf("Podaj wielkosc wektora: ");
	scanf("%d", &n);
	vec = randVec(n);
	vecToTxt(vec,n); //utworzony plik tektowy ma 204B przy 20 elementach
	vecToBin(vec,n); //utworzony plik binarny ma tylko 87B przy 20 elementach
	// plik binarny zajmuje mniej miejsca, przy takich samych wartościach wpisanych
	//sa one zakodowane, takze nie widac jego zawartosci przy przegladaniu uzywajac np. notatnika
	//w przeciwienstwie do pliku tekstowego - który można przeglądać

}

int* intVec(const char fileName[]) {
	FILE* file = fopen(fileName, "rb"); //otwieramy plik binarny do odczytu
	int* vec;
	int n;

	if (file == NULL) //sprawdzamy czy dany plik istnieje
		printf("Blad w odczycie pliku\n");
	else {
		fread(&n, sizeof(int), 1, file); //czytamy ile jest liczb, aby moc ustawić wielkość wektora
		printf("%d danych\n", n);

		vec = (int*)calloc(n, sizeof(int)); //tworzymy wektor liczb całkowitych

		for (int i = 1;i <= n;i++) {

			fread(&vec[i-1], sizeof(float), 1, file); //zapisujemy do niego liczby float z pliku binarnego
			printf("%d\t", vec[i-1]);
			if (i % 4 == 0)
				printf("\n"); //co 4 liczbe przechodzimy do drugiej lini
		}

		fclose(file); //zamykamy plik
		return vec; //zwracamy wektor liczb całkowitych

	}
	
}

float* floatVec(const char fileName[]) {
	FILE* file = fopen(fileName, "rb"); //otwieramy plik binarny do odczytu
	float* vec;
	int n;

	if (file == NULL)
		printf("Blad w odczycie pliku\n"); //sprawdzamy czy dany plik istnieje
	else {
		fread(&n, sizeof(int), 1, file); //czytamy ile jest liczb, aby moc ustawić wielkość wektora
		printf("%d danych\n", n);

		vec = (float*)calloc(n, sizeof(float)); //tworzymy wektor liczb zmiennoprzecinkowych

		for (int i = 1;i <= n;i++) {
			fread(&vec[i-1], sizeof(float), 1, file); //zapisujemy do niego liczby float z pliku binarnego
			printf("%f\t", vec[i-1]);
			if (i % 4 == 0)
				printf("\n"); //co 4 liczbe przechodzimy do drugiej lini
		}

		fclose(file); //zamykamy plik
		return vec; //zwracamy wektor liczb całkowitych
	}

}



void task4() {
	printf("\nWektor liczb calkowitych: \n");
	int* ivec = intVec("zad3.bin");
	printf("\nWektor liczb zmiennoprzecinkowych: \n");
	float* fvec = floatVec("zad3.bin");
	// wczytanie licz do wektora liczb całkowitych nie działa poprawnie
	//wyswietlaja sie duze liczby
	//wczytujac plik do wektora float - wszystko dziala poprawnie
	//probujac wczytac dane z pliku tekstowego, program uruchamia sie z bledem
	//nie pozwalajac odczytac prawidlowo danych

}



void task5() {
	complex cx1, cx2, res_add, res_sub, res_mul;
	//printf("Podaj dwie liczby urojone a + bi, w formacie: a b\n");
	//scanf("%f%f", &cx1.real, &cx1.imag);
	//scanf("%f%f", &cx2.real, &cx2.imag);
	cx1.real = random(); //losujemy dwie liczby zespolone
	cx2.real = random();
	cx1.imag = random();
	cx2.imag = random();
	printf("%.4f + %.4fi\n",cx1.real,cx1.imag);
	printf("%.4f + %.4fi\n",cx2.real,cx2.imag);

	res_add = add(cx1, cx2); //zapisujemy wynik operacji 
	res_sub = subtract(cx1, cx2);
	res_mul = multiply(cx1, cx2);
	if(res_add.imag>=0) //wypisujemy je na ekran używając funkcji z pliku complex.h
		printf("suma: %f + %fi\n", res_add.real, res_add.imag); //sprawdzamy czy liczba ujorona jest ujemna, jeśli tak nie wypisujemy znaku +
	else
		printf("suma: %f %fi\n", res_add.real, res_add.imag);
	if(res_sub.imag>=0)
		printf("roznica: %f + %fi\n", res_sub.real, res_sub.imag);
	else
		printf("roznica: %f %fi\n", res_sub.real, res_sub.imag);
	if (res_mul.imag >= 0)
		printf("iloczyn: %f + %fi\n", res_mul.real, res_mul.imag);
	else
		printf("iloczyn: %f %fi\n", res_mul.real, res_mul.imag);
	if (equals(cx1, cx2))
		printf("Liczby sa sobie rowne\n");
	else
		printf("Liczby nie sa sobie rowne\n");

}

void write_complex(int n) {
	FILE* file = fopen("zad6_complex.bin", "wb"); //otwieramy plik binarny do zapisu
	for (int i = 0;i < n;i++) {  //tworzymy pętle która dodaje n liczb zespolonych do pliku
		complex cx;
		cx.real = random();
		cx.imag = random();
		fwrite(&cx, sizeof(complex), 1, file);  //wpisujemy liczbe zespoloną do pliku
		if (cx.imag >= 0) //wypisujemy ją kontrolnie na ekran
			printf("%f + %fi\n", cx.real, cx.imag);
		else
			printf("%f %fi\n", cx.real, cx.imag);
	}
	fclose(file);
}

void read_complex() {
	FILE* file = fopen("zad6_complex.bin", "rb"); //otwieramy plik binarny gotowy do odczytu
	complex cx; 
	if (file == NULL) //sprawdzamy czy plik istnieje
		printf("Blad odczytu \n");  //jeśli nie wyświetlamy odpowiedni komunikat
	else {
		while (fread(&cx, sizeof(complex), 1, file)) {  //dopóki można coś odczytać z pliku, 
			if (cx.imag >= 0)							//przypisujemy liczbe zespoloną do zmiennej którą wypisujemy na konslę
				printf("%f + %fi\n", cx.real, cx.imag);
			else
				printf("%f %fi\n", cx.real, cx.imag);
		}
	}
}

void task6() {
	int n;
	printf("Podaj ile liczb chcesz wpisac: ");
	scanf("%d", &n); 
	write_complex(n);
	printf("\n\nOdczytane z pliku: \n");
	read_complex();
}

int less_or_equal_1(const complex a, const complex b) {
	if (a.real <= b.real) //sprawdza czy liczba a jest mniejsza rowna wg czesci rzeczywistej
		return 1;
	return 0;
}
int less_or_equal_2(const complex a, const complex b) {
	if (a.imag <= b.imag) //sprawdza czy liczba a jest mniejsza rowna wg czesci urojonej
		return 1;
	return 0;
}
int less_or_equal_3(const complex a, const complex b) {
	float mod_a = sqrt((a.real*a.real)+(a.imag*a.imag));
	float mod_b = sqrt((b.real*b.real)+(b.imag*b.imag));
	if (mod_a <= mod_b) //sprawdza czy liczba a jest mniejsza rowna na podstawie modulu
		return 1;
	return 0;
}

void task7() {
	complex cx1,cx2;
	cx1.real = random();
	cx1.imag = random();
	cx2.real = random();
	cx2.imag = random();
	printf("liczba 1: %.4f %.4f\n", cx1.real, cx1.imag);
	printf("liczba 2: %.4f %.4f\n", cx2.real, cx2.imag);
	printf("porownanie czesci rzeczywistych: %d\n", less_or_equal_1(cx1, cx2));
	printf("porownanie czesci urojonych: %d\n", less_or_equal_2(cx1, cx2));
	printf("porownanie modulu: %d\n", less_or_equal_3(cx1, cx2));

}

struct linked {  //tworzymy strukturę listy jednokierunkowej
	complex val; //liczba urojona 
	linked* next; //wskaźnik do następnego elementu
};


linked* createList(int n) { //tworzymy funkcję która zwraca wstaźnik do listy n elementowej
	complex cx;
	struct linked* list = NULL; // inicjujemy listę zmienną "list"
	for (int i = 0;i < n;i++) {
	struct linked* temp = (struct linked*)malloc(sizeof(struct linked)); //tworzymy pomocniczą strukturę
	cx.real = random() * ((rand() % 201) - 100);		// którą będziemy pushować na początek poprzedniej
	cx.imag = random() * ((rand() % 201) - 100); //losujemy liczbę zespoloną typu float z zakresu od -100 do 100
	temp->val = cx; //przypisujemy liczbę zespoloną do wartości w tymczasowej strukturze
	temp->next = list; //jako następnik, przypisujemy jej całą poprzednią listę
	list = temp; // ustawiamy początek tej listy na zmienną strukturalną "list"
	}
	return list; //zwracamy gotową listę

}

void printList(struct linked* node) {
	while (node != NULL) { //dopóki element listy nie jest pusty wypisujemy je
		if (node->val.imag >= 0) //sprawdzamy czy część urojona jest dodatnia czy ujemna i odpowiednio wypisujemy
			printf("%.2f +%.2f\n", node->val.real, node->val.imag);
		else
			printf("%.2f %.2f\n", node->val.real, node->val.imag);
		node = node->next; //przechodzimy do kolejnego elemetu listy
	}
}

void sort_list(linked* list,int n, int(*sort)(complex, complex)) { //funkcja do sortowania elementów listy jednokierunkowej
	linked* a; //tworzymy tymczasowe struktury a i b
	linked* b;
	complex temp; //tworzymy tymczasową zmienną przechowującą liczbe zepoloną
	for (int i = 0;i < n;i++) { //bubbleSort
		a = list;
		b = list->next;
		for (int j = 1;j < n - i;j++) {
			if (!sort(a->val, b->val)) { // sprawdzamy czy wartosc a jest wieksza od b, używając funkcji porównawczej podanej jako argument
				temp = a->val;		//jeśli tak zamieniamy je
				a->val = b->val;
				b->val = temp;
			} //przechodzimy do kolejnych wartości
			a = b;
			b = b->next;
		}
	}
}

void task8() {
	int n;
	printf("Podaj dlugosc listy jednokierunkowej liczb zespolonych: ");
	scanf("%d", &n);
	linked* list = createList(n); //przypisujemy wskaźnik utworzonej n elementowej listy to "list"
	printf("Lista: \n");
	printList(list); //wypisujemy te liste 

	//sortowanie według wybranego porządku
	printf("\nLista posortowana wedlug czesci rzeczywistej: \n");
	sort_list(list,n,less_or_equal_1); 
	printList(list);

	printf("\nLista posortowana wedlug czesci urojonej: \n");
	sort_list(list, n, less_or_equal_2);
	printList(list);

	printf("\nLista posortowana wedlug modulu: \n");
	sort_list(list, n, less_or_equal_3);
	printList(list);
}

typedef struct Student { //tworzymy strukturę studenta zawierającą odpowienie elementy
	int index; 
	char name[30];
	char surname[30];
	float points;
	float  procenty;
}Student;

int marksToBinary(const char fileName[]) {
	FILE *pliktxt, *plikbin;
	pliktxt = fopen(fileName, "rt"); //otwieramy plik tekstowy do oczytu
	plikbin = fopen("marks.bin", "wb"); //otwieramy plik binarny, w którym będziemy zapisywać

	int n;
	fscanf(pliktxt, "%d", &n); //pobieramy liczbę studentów
	Student student; //tworzymy strukturę studenta o nazwie student
	for (int i = 0; i < n; i++) { 
		//następnie dla każdego studenta pobieramy z pliku dane do struktury
		fscanf(pliktxt, "%d %s %s %f", &student.index, &student.name, &student.surname, &student.points);
		//wypisujemy je kontrolnie na ekran
		printf("%d %s %s %f \n", student.index, student.name, student.surname, student.points);
		//zapisujemy do pliku biarnego całą strukturę
		fwrite(&student, sizeof(student), 1, plikbin);
	}
	fclose(pliktxt); //zamykamy wykorzystane pliki
	fclose(plikbin);
	return n; //zwracamy ilość studentów
}

void task9() {

	marksToBinary("marks.txt");
	//utworzony plik binarny jest większy zamując 360B
	//gdy plik tekstowy zajmuje 161

}
void modifymarks(const char fileName[], int n) {
	FILE *plik;
	plik = fopen(fileName, "rb"); //otwieramy plik binarny do odczytu

	Student *tablica = (Student*)malloc(n * sizeof(Student)); //tworzymy tablice struktur dla n studentów
	for (int i = 0;i < n;i++) {
		fread(&tablica[i], sizeof(tablica[i]), 1, plik); //wczytujemy dane każdego studenta do tablicy
		tablica[i].procenty = tablica[i].points / 20 * 100; //następnie obliczamy procenty i wpisujemy je do stuktury
	}
	fclose(plik); //zamykamy plik do oczytu
	plik = fopen(fileName, "wb"); //otwieramy plik do zapisu
	for (int i = 0;i < n;i++) { //wpisujemy n studentów do pliku binarnego uwzględniająć procenty
		fwrite(&tablica[i], sizeof(tablica[i]), 1, plik);
	}
	fclose(plik);
	printf("\n\n");
	plik = fopen(fileName, "rb"); //otwieramy ponownie plik aby odczytać wprowadzone zmiany
	for (int i = 0;i < n;i++) {
		fread(&tablica[i], sizeof(tablica[i]), 1, plik);
		printf("%d %s %s %f %f\n", tablica[i].index, tablica[i].name, tablica[i].surname, tablica[i].points, tablica[i].procenty);
	}

	fclose(plik);
}


void task10() {
	modifymarks("marks.bin", marksToBinary("marks.txt"));
}


struct dict { //tworzymy strukturę słownika
	char val; //charakter [a-z] [A-Z] [0-9]
	int count; //liczbę występowań w zdaniu
	dict* next; //wskaźnik na kolejny znak
};

dict* createDict(char tekst[]) { //tworzymy słownik dla liter w zmiennej "tekst"
	int n = strlen(tekst); //sprawdzamy długość zdania
	int isIn; //inicjujemy zmienną sprawdzającą, czy litera nie była już wpisana 
	dict* d = (dict*)malloc(sizeof(dict)); //tworzymy pomocniczy wskaźnik na listę
	dict* node = (dict*)malloc(sizeof(dict)); //tworzymy początek listy
	d->next = node; //ustawiamy wskaźnik na początek naszej listy
	//printf("%d\n", n);
	

	//wpisujemy pierwszą wartość do listy
	node->val = tekst[0];
	node->count = 1; //ustawiamy ilość na 1
	node->next = NULL; //następnik jest pusty

	for (int i=0;i < n;i++) { //dla każdego elementu w tablicy
		isIn = 0; //ustawiamy zmienną sprawdzająca czy litera juz była zapisana na 0 
		node = d->next; //zaczynamy sprawdzanie od początku naszej listy
		while (1){ 
			if (node->val == tekst[i]) { //jeśli znak jest już w tablicy 
				node->count++; //inkrementujemy jego wartość o 1
				isIn = 1; //ustawiamy zmienną sprawdzającą na 1
				break; //wychodzimy z pętli, ponieważ znak już się nie pojawi 
			}
			if (node->next == NULL) { //jeśli nie znaleźliśmy znaku w liście i doszliśmy do jej końca
				break; //wychodzimy z pętli, nie zmieniając wartości zmiennej sprawdzającej "isIn"
			}
			node=node->next; //jeśli nie wyszliśmy z pętli wcześniej, przechodzimy do kolejnego znaku
		} 
		if (!isIn && (      (tekst[i] > 64 && tekst[i] < 91)    ||    (tekst[i] > 96 && tekst[i] < 123)   ||   (tekst[i] > 47 && tekst[i] < 58)     )  ) {
			//sprawdzamy czy dany zmienna sprawdzająca isIn ma wartość 0 - nie znaleźliśmy znaku w liście
			//oraz czy znak jest literą [a-z], [A-Z], bądz cyfrą [0-9]
			dict* temp = (dict*)malloc(sizeof(dict)); //tworzymy tymczasową strukturę
			temp->val = tekst[i]; //przypisujemy jej owy znak
			temp->count = 1; //ustawiamy ilość występowań na 1
			temp->next = NULL; //ustawiamy jego następnika na pustego 
			node->next=temp; //dopisujemy go na koniec naszej listy
		}
	}
	
	return d->next; //zwracamy początek listy
}

void pList(struct dict* node) {
	while (1) { //jeśli element nie ma następnika, wypisujemy go bez zbędnej strzałki, przerywając pętle wypisywania
		if (node->next == NULL) {
			printf("%c/%d\n", node->val, node->count);
			break;
		}
		else //dopóki następnik nie jest pusty wypisujemy listę
			printf("%c/%d -> ", node->val, node->count);
		node = node->next; //przechodzimy do kolejnego elementu
	}
}

struct bst { //tworzymy strukturę drzewa binarnego 
	char key;
	int count;
	struct bst* left;
	struct bst* right;
};

struct bst* newNode(char n_key,int n_count){ //tworzymy funkcję inicjalizującą drzewo
	struct bst* temp = (struct bst*)malloc(sizeof(struct bst)); //zajmujemy obszar pamięci wielkości struktury
	temp->key = n_key; //przypisujemy do niego znak
	temp->count = n_count; //oraz ilość jego wystąpień 
	temp->left = temp->right = NULL; //jako iż to jest pierwszy znak, nie posiada on dzieci, także ustawiamy je jako NNULL
	return temp; //zwracamy korzeń drzewa
}

struct bst* insertBST(struct bst* node, char n_key,int n_count) {
	if (node == NULL)
		return newNode(n_key,n_count); //jesli drzewo jest puste, stworz węzeł

	//jesli nie jest puste, idz rekurencyjnie wedlug zasad BST
	if (n_key < node->key)
		node->left = insertBST(node->left, n_key, n_count);
	else if (n_key > node->key)
		node->right = insertBST(node->right, n_key, n_count);
	//jeśli element nie ma mniejszych, ani większych elementów zwracamy go, jako odpowiednie dziecko
	return node;
}

void printBST(struct bst* root) { //wypisywanie drzewa inorder LKP
	if (root->left != NULL)
		printBST(root->left);

	printf("%c:\t%d\n", root->key, root->count);

	if (root->right != NULL)
		printBST(root->right);
}

void task11() {
	char tekst[200];
	printf("Podaj tekst do slownika: ");
	scanf(" %[^\n]s", tekst); //podajemy tekst dopóki nie wpiszemy znaku nowej linii
	//pozwala nam to na dopisanie spacji
	dict* d = createDict(tekst); //tworzymy słownik jako listę jednokierunkową
	pList(d);

	struct bst* root = NULL;
	root = insertBST(root, d->val, d->count); //tworzymy drzewo BST
	d = d->next; //pierwszy element wykorzystaliśmy aby zainicjalizować drzewo, dlatego zaczynamy od jego następnika
	while (d != NULL) { //dodajemy elementy do drzewa, dopóki nie dojdziemy do końca listy
		insertBST(root, d->val, d->count);
		d = d->next; //przechodzimy do kolejnego elementu
	}
	printBST(root); //wypisujemy drzewo

}

int main()
{	
	
	srand(time(NULL));  
	int x = 1,wybor;
	while (x) {
		printf("Podaj numer zadania: ");
		scanf("%d", &wybor);
		switch (wybor) {
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
		case 3:
			task3();
			break;
		case 4:
			task4();
			break;
		case 5:
			task5();
			break;
		case 6:
			task6();
			break;
		case 7:
			task7();
			break;
		case 8:
			task8();
			break;
		case 9:
			task9();
			break;
		case 10:
			task10();
			break;
		case 11:
			task11();
			break;
		default:
			printf("Error :( \n");

		}

		printf("\n\n0 - jesli chcesz zakonczyc program\n");
		printf("1 - jesli chcesz wykonac program ponownie\n");
		scanf("%d", &x);
	}

}
