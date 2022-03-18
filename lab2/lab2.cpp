#include <iostream>
#include <stdio.h>
#include <conio.h>

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
	printf("%Lf\n", sum);
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

		}
		printf("\n\nJesli chcesz zakonczyc dzialanie programu wpisz 0\n");
		printf("Jesli chcesz ponownie wykonac program wpisz 1\n");
		scanf(" %d", &b);
	} while (b);
}

