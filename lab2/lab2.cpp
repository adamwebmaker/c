#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void task1() {
	printf("char - %d\n",sizeof(char));
	printf("int - %d\n",sizeof(int));
	printf("short - %d\n",sizeof(short));
	printf("long - %d\n",sizeof(long));
	printf("float - %d\n",sizeof(float));
	printf("double - %d\n",sizeof(double));
	printf("long long - %d\n",sizeof(long int));
	printf("short short - %d\n",sizeof(short int));
	printf("unsigned int - %d\n",sizeof(unsigned int));
	printf("signed int - %d\n",sizeof(signed int));
	
}

void task2() {
	float liczba;
	printf("Podaj liczbe zmiennoprzecinkowa\n");
	scanf(" %f", &liczba);
	printf("domyslna dokladnosc %f\n", liczba);
	printf("notacja naukowa %e\n", liczba);
	printf("system szesnastkowy %a\n", liczba);
	printf("dokladnosc do 3 miejsc po przecinku %0.3f", liczba);
	printf("dokladnosc do 3 miejsc po przecinku %0.3e", liczba);
}

void task3() {
	printf("Podaj kierunek konwersji\n");
	printf("d - z decymalnego na hexadecymalny\n");
	printf("h - z hexadecymalnego na decymalny\n");
	char znak;
	scanf(" %c", &znak);
	int wyn;
	if (znak == 'd') {
		printf("Podaj liczbe\n");
		scanf(" %d", &wyn);
		printf("0x%x\n", wyn);
	}
	if (znak == 'h') {
		printf("Podaj liczbe\n");
		scanf(" %x", &wyn);
		printf("%d\n", wyn);
	}
}

void task4() {
	printf("Podaj liczbe\n");
	int liczba;
	scanf(" %d", &liczba);
	if (0xB0000000 == (liczba & 0xB0000000))
		printf("Yes\n");
	else
		printf("No\n");
}

void task5() {
	unsigned int state, mask, res;
	printf("Podaj zmienne state i mask\n");
	scanf("%x%x", &state, &mask);
	res = (~state | mask);
	printf("0x%x\n", ~res);
}

void task6() {
	int i;
	for (i = 1;i < 256;i++) {
		printf("Kod znaku: %d, znak: %c\n", i, i);
		if (i % 40 == 0) {
			system("pause");
		}
	}
}

void task8() {
	int wybor = 1;
	
	do {
		int w;
		float a, b;
		printf("Podaj pierwsza liczbe\n");
		scanf(" %f", &a);
		printf("Podaj druga liczbe\n");
		scanf(" %f", &b);
		printf("\nPodaj ktore dzialanie chcesz wykonac\n");
		printf("1 - dodawanie\n");
		printf("2 - odejmowanie\n");
		printf("3 - mnozenie\n");
		printf("4 - dzielenie\n");
		scanf(" %d", &w);
		if (w > 0 and w < 5) {
			switch (w) {
			case 1:
				printf("%f + %f = %0.2f\n", a, b, a + b);
				break;
			case 2:
				printf("%f - %f = %0.2f\n", a, b, a - b);
				break;
			case 3:
				printf("%f - %f = %0.2f\n", a, b, a * b);
				break;
			case 4:
				printf("%f - %f = %0.2f\n", a, b, a / b);
				break;
			}
			printf("\n\nJesli chcesz zakonczyc dzialanie kalkulatora wpisz 0\n");
			printf("Jesli chcesz ponownie wykonac program wpisz 1\n");
			scanf(" %d", &wybor);
		}
		else
			printf("Podaj poprawna liczbe");
	} while (wybor);
}

void task9(){
	int i = 1;
	for (i;i <= 500;i++) {
		if (i % 7 == 0)
			printf("%d\n", i);
	}
}

void task10() {
	double sum=0;
	//int i = 1;
	for (int i=1;i <= 10000;i++) {
		sum += 1.0/(i * i);
	}
	printf("%lf\n", sum);
	sum = 0;
	for (int i = 10000;i >0;i--) {
		sum += 1.0 / (i * i);
	}
	printf("%lf\n", sum);
}

void task11() {
	long double sum = 0;
	long int n = 0;
	for (n;n < 100000000;n++) {
		if (n%2==1)
			sum += (-1.0) / ((2 * n) + 1);
		else
			sum += 1.0 / ((2 * n) + 1);
	}
	printf("%Lf\n", 4*sum);
}

void task12() {
	float a, b, c, p;
	printf("Podaj dlugosci trojkata\n");
	scanf(" %f %f %f", &a, &b, &c);
	if (a + b > c && b + c > a && a + c > b) {
		printf("Mozna zbudowac trojkat\n");
		p = (a + b + c) / 2;
		printf("Jego pole wynosi %.2f", sqrt( p*(p - a)*(p - b)*(p - c) ) );
	}
	else {
		printf("Nie mozna zbudowac trojkata\n");
	}
}

void task13() {
	printf("Podaj miare kata w radianach\n");
	float radian,st;
	scanf(" %f", &radian);
	st = radian * (180 / 3.1415);
	printf("Stopnie: %f", st);
}

void task14() {
	printf("Podaj napis\n");
	char string[30];
	scanf(" %[^\n]s\n", string);
	
	int i = 0;
	while (i<30) {
		if (string[i] > 64 && string[i] < 91)
			string[i] += 32;
		else if (string[i] > 96 && string[i] < 123)
			string[i] -= 32;
		i++;
	}
	printf("%s", string);
}

void task15() {
	printf("Podaj slowo\n");
	char slowo[20];
	scanf(" %s", slowo);
	int x = 1;
	for (int i = 0;i < strlen(slowo) / 2;i++) {
		if (slowo[i] != slowo[strlen(slowo) - 1 - i])
			x = 0;
	}
	if (x==1 && strlen(slowo) % 2 == 0) {
		for (int i = 0;i < strlen(slowo) / 2;i++) {
			printf("%c", slowo[i]);
		}
	}
	else if(x==1 && strlen(slowo) % 2 == 1){
		for (int i = 0;i < (strlen(slowo) / 2 )+1;i++) {
			printf("%c ", slowo[i]);
		}
	}
	
}

int isTriangleTrojkat(float a, float b, float c) {
	if (a + b > c && b + c > a && a + c > b)
		return 1;
	else return 0;
}

float calculateArea(float a, float b, float c) {
	float p;
	p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

void task16() {
	printf("Podaj dlugosci bokow trojkata\n");
	float a, b, c;
	scanf(" %f%f%f", &a, &b, &c);
	if (isTriangleTrojkat(a, b, c))
		printf("Pole trojkata wynosi: %f\n", calculateArea(a, b, c));
	else
		printf("Nie mozesz zbudowac trojaka z tych bokow");
}

float toDegree(float rad) {
	return rad * (180 / 3.1415);
}

void task17() {
	printf("Podaj w radianach miare kata\n");
	float rad;
	scanf(" %f", &rad);
	printf("%f",toDegree(rad));
}

int isPalindrome(char slowo[]) {
	int x = 1;
	for (int i = 0;i < strlen(slowo) / 2;i++) {
		if (slowo[i] != slowo[strlen(slowo) - 1 - i])
			x = 0;
	}
	return x;
}

void halfPalindrome(char slowo[]) {
	if (strlen(slowo) % 2 == 0) {
		for (int i = 0;i < strlen(slowo) / 2;i++) {
			printf("%c", slowo[i]);
		}
	}
	else
		for (int i = 0;i < (strlen(slowo) / 2) + 1;i++) {
			printf("%c", slowo[i]);
		}
	
}

void task18() {
	printf("Podaj slowo\n");
	char slowo[20];
	scanf(" %s", slowo);
	if (isPalindrome(slowo))
		halfPalindrome(slowo);
}

int iterativeFibb(int n) {
	int x0 = 0;
	int x1 = 1;

	for (int i = 0; i < n; ++i) {
		int temp = x0 + x1;
		x0 = x1;
		x1 = temp;
	}

	return x0;
}

int recursiveFibb(int n) {
	if (n == 0)
		return 0;
	else if (n == 0 || n == 1)
		return 1;
	else
		return recursiveFibb(n - 1) + recursiveFibb(n - 2);
}


void task19() {
	int n;
	printf("Podaj n\n");
	scanf(" %d", &n);

	clock_t t = clock();
	printf("iteracyjnie - %d\n", iterativeFibb(n));
	t = clock() - t;
	printf("Czas to %f\n", ((float)t) / CLOCKS_PER_SEC);

	clock_t t = clock();
	printf("relkurencyjnie - %d\n", recursiveFibb(n));
	t = clock() - t;
	printf("Czas to %f\n", ((float)t) / CLOCKS_PER_SEC);

}

int main()
{
	int b;
	do {
		system("cls");
		int wybor;
		printf("Podaj numer zadania, ktore zadanie chcesz wykonac:\n");
		scanf(" %d", &wybor);
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

		case 12:
			task12();
			break;

		case 13:
			task13();
			break;

		case 14:
			task14();
			break;

		case 15:
			task15();
			break;

		case 16:
			task16();
			break;

		case 17:
			task17();
			break;

		case 18:
			task18();
			break;

		case 19:
			task19();
			break;

		}
		printf("\n\nJesli chcesz zakonczyc dzialanie programu wpisz 0\n");
		printf("Jesli chcesz ponownie wykonac program wpisz 1\n");
		scanf(" %d", &b);
	} while (b);
}

