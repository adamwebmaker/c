#include <iostream>
#include <stdio.h>
#include <conio.h>

int main()
{
	int wybor;
	printf("Podaj numer zadania, ktore zadanie chcesz wykonac:\n");
	scanf(" %d", &wybor);

	switch (wybor) {
	case 2: {
		float liczba;
		printf("Podaj liczbe zmiennoprzecinkowa\n");
		scanf(" %f", &liczba);
		printf("domyslna dokladnosc %f\n", liczba);
		printf("notacja naukowa %e\n", liczba);
		printf("system szesnastkowy %a\n", liczba);
		printf("dokladnosc do 3 miejsc po przecinku %0.3f", liczba);
		printf("dokladnosc do 3 miejsc po przecinku %0.3e", liczba);
		break;

	}
	case 3: {
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
		break;
	}
	case 4: {
		printf("Podaj liczbe\n");
		int liczba;
		scanf(" %d", &liczba);
		if (0xB0000000 == (liczba & 0xB0000000))
			printf("Yes\n");
		else
			printf("No\n");
	}
	case 5: {
		unsigned int state, mask, res;
		printf("Podaj zmienne state i mask\n");
		scanf("%x%x", &state, &mask);
		res = (~state|mask);
		printf("0x%x\n",~res );
	}
	case 6: {
		int i;
		for (i = 1;i < 256;i++) {
			printf("Kod znaku: %d, znak: %c\n", i, i);
			if (i % 40 == 0) {
				while (getch()) {
				
				}
			}
		}
	}
	}
}

