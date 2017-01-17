#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct lista {
	int dana;
	struct lista *nastepna;                      //wskaznik na nastepny element
}list;

 list *dodaj (list* poczatek, int wartosc) {        //utworz, potem wsp
        list *nowa = (list*)malloc(sizeof(list));   //zasada dzia³ania jak "new" w c++
        nowa->dana = wartosc;
        nowa->nastepna = NULL;
		if (poczatek != NULL) {
			list *temp = poczatek;                //pomocnicza do przemieszczania sie po liscie
			while (temp->nastepna) {                      //przesuniecie na ostatni element
            	temp = temp->nastepna;
    		}
			temp->nastepna = nowa;                        //przypisanie wartosci
			return poczatek;
		}
		return nowa;
};

list *usunwszystkie (list* poczatek, int wartosc) {
    list *t = poczatek;                      //pomocnicza 1.
    int licznik = 1;                                 //numeracja elementu
	while (t) {
		if (t->dana == wartosc) {
    		if (licznik == 1) {                      //jesli to pierwszy element
       			list *temp = poczatek;
        		poczatek = temp->nastepna;
        		t= t->nastepna;                     //przesuwam wskaznik na kolejny element
   			}

    		if (licznik > 1) {
        		list *temp = poczatek;

        		while (temp) {                      //przesuniecie na element przed "usuwanym"
            		if (temp->nastepna == t) break;
            		temp = temp->nastepna;
        		}
            	temp->nastepna = temp->nastepna->nastepna;
				free(t);
				t = temp;
    			licznik++;
    			
    		}
		}else {
			t = t->nastepna;
			licznik++;
		}
	}
	return poczatek;
};

int wyswietlliste(poczatek) {
	list *tmp;
	tmp = poczatek;
	
	if (poczatek == NULL) {
		printf("[pusto]\n\n");
	}
	int licznik = 1;
	
	while (tmp!=NULL) {
		printf("%d. Dana: %d\n", licznik, tmp->dana);
		tmp = tmp->nastepna;
		licznik++;
	}
	return licznik;
};


int main(int argc, char *argv[]) {
	int wybor;
	int wartoscdanej;
	list *pierwszy = NULL;                   //wskaznik na poczatek listy
	int licznik = 0;
	
	do {
			printf("LISTA:\n");
			licznik = wyswietlliste(pierwszy);
			puts("");
			if (licznik > 10) {
				printf("lista jest pelna!\n\n");
			}
		
		printf("MENU:\n1. Dodaj.\n2. Usun.\n3. Wyjdz\n");
		scanf(" %d", &wybor);
		switch (wybor) {
			case 1:
				if (licznik <= 10) {
					printf("Podaj dana: "); 
					scanf("%d", &wartoscdanej);
					pierwszy = dodaj(pierwszy, wartoscdanej);
				}
				break;
			
			case 2:
				printf("Ktory usunac?");
				scanf(" %d", &wartoscdanej);
				pierwszy = usunwszystkie(pierwszy, wartoscdanej);
				break;
			case 3:
				return 0;
				break;
			default:
				break;
		}
		system("cls");    //czysci ekran
	}while (1);
}
