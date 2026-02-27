#include <iso646.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int Calc_det_sarus(int s_matrix[5][3]){
    int det=0;
    for (int m=0; m<3; m++){
        int sum=1, dif=1;
        for (int n=0; n<3; n++){
            sum*=s_matrix[m+n][n];
            dif*=s_matrix[m+n][2-n];
        }
        det+=sum-dif;
    }
    return det;
}

int Calc_det_sarus_pointer(int matrix[3][3]){
    int det=0;
    for (int m=0; m<3; m++){
        int sum=1, dif=1;
        for (int n=0; n<3; n++){
            sum *= *(*(matrix + (m + n)%3) + n);
            dif *= *(*(matrix + (m + n)%3) + (2 - n));
        }
        det+=sum-dif;
    }
    return det;
}

//Cílem  počítačového  cvičení  je  seznámit  se  s vytvářením  jednoduchých  konzolových  aplikací, základními typy proměnných a využitím vícerozměrných polí.  Vytvořte program, který  v  konzolovém  okně  vygeneruje  matici  náhodných  celých  čísel v rozsahu <-99; 99> o rozměru 3x3 a uloží ji do dvourozměrného celočíselného pole (3x3). Pro tuto matici vypočtěte determinant aplikací rozloženého vztahu s prvky matice a zobrazte jej.   Determinant  je   pro   matici   indexovanou  podle   (indexování  matice   je   v souladu s indexováním polí v C/C++ - první index je standardně 0):  vyjádřen vztahem: Deklarujte nové dvourozměrné pole (5x3, tj. 5 řádků, 3 sloupce), které bude reprezentovat rozšířenou matici pro Sarrusovu metodu výpočtu determinantu matice 3x3 a pole naplňte hodnotami  prvků  podle  matice  náhodných  čísel  z první  části  úkolu,  „Sarrusovu“  matici zobrazte v konzolovém okně. Sestavte algoritmus ze dvou vnořených cyklů for, pomocí kterého se ze „Sarrusovy“ matice Sarrusovým pravidlem vypočte determinant (obr 1). Obr. 1. Princip Sarrusova pravidla pro výpočet determinantu matice (3x3). Dílčí součiny pro součty i rozdíly (dvě předdeklarované proměnné) počítejte v současně v těle vnořeného cyklu for, po ukončení vnořeného cyklu je připočtěte, resp. odečtěte, k proměnné výsledku determinantu. Nezapomeňte použité proměnné správně inicializovat. Výsledný determinant zobrazte. Úvodní část zdrojového kódu programu je v projektu 2020_CV3_P01, kde je sestaven zdrojový kód pro generování matice náhodných celých čísel. Funkce rand() je součástí knihovny stdlib.h, její popis lze nalézt v helpu, např.: http://www.cplusplus.com/reference/clibrary/cstdlib/.Pro správnou činnost generátoru náhodných čísel je nutno nejprve provést inicializaci generátoru pomocí  funkce  srand(), kde  parametrem je  hodnota  „semínka“  generátoru náhodných  čísel.  Pokud  je  třeba  generovat  při  každém  spuštění  rand() jinou  matici náhodných čísel,  musí  být  inicializační  „semínko“ vždy  jiné,  toho  dosáhneme například dosazením aktuálního systémového času voláním funkce  time z knihovny time.h (musí být  přilinkována): srand(time(NULL)). Funkce  rand() je  volána  v těle  vnitřního cyklu for tak, aby byla vygenerována náhodná hodnota s úpravou celočíselným dělením a rozdílem od konstanty pro každý prvek matice v požadovaném rozsahu. Funkci cyklů for osvětlí cvičící. Do těla vnitřního cyklu for je vhodné po vygenerování náhodné hodnoty prvku provést její tisk na konzolu. Dále postupujte dle zadání. Příklad výstupů v konzolovém okně je uveden na obrázku 2. K dispozici je project s šablonou.
int main(void)
{
    int matrix[3][3];
    int s_matrix[5][3];
    printf("3x3 random matrix:\n\n");

    srand(time(NULL));
    for (int m=0; m<3; m++)
    {
        for (int n=0; n<3; n++)
        {
            matrix[m][n]=rand()%199-99;
            printf("%4d ", matrix[m][n]);
        }
        printf("\n");
    }
printf("\n");
  for (int m=0; m<5; m++){

        for (int n=0; n<3; n++){
            if (m<3) {
                s_matrix[m][n]=matrix[m][n];
            }
            else {
                s_matrix[m][n]=matrix[m-3][n];
            }
            printf("%4d ", s_matrix[m][n]);
        }
        printf("\n");
    }

    printf("Matrix det: %d\n", Calc_det_sarus(s_matrix));


    printf("Matrix det via pointers %d\n", Calc_det_sarus_pointer(matrix));


    return 0;
}