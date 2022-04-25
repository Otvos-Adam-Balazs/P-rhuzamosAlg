#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <omp.h>

#define WORDS 93000 //A kigenerált jelszavak száma
#define LENGTH 10 //A kigenerált jelszavak hossza
#define ALPHABET "abcdefghijklmnopqrstuvwxyz0123456789" //36 karakter
#define THREADS 4 //Hány szálon szeretnénk dolgozni

int intN(int n);
char *randomString(int len);
char crack(char letter);

int main()
{
    clock_t start, end;
    double runtime;
    srand(time(NULL));
    char words[WORDS][LENGTH+1];
    char cracked[WORDS][LENGTH+1];
    int i, j;

    omp_set_dynamic(0);
    omp_set_num_threads(THREADS);

    printf("Passowrds to crack:\n");
    //Jelszavak generálása
    for (i = 0; i < WORDS; i++)
    {
        strcpy(words[i], randomString(LENGTH));
        printf("%s\n", words[i]); //Írjuk ki a generált szót
        cracked[i][LENGTH] = '\0';
    }

    start = clock();
    #pragma omp parallel for collapse(2)
    for (i = 0; i < WORDS; i++)
    {
        for (j = 0; j < LENGTH; j++)
        {
            cracked[i][j] = crack(words[i][j]); //Törjük fel a jelszót betűnként
        }
    }
    end = clock();

    printf("\nCrack:\n");
    for (i = 0; i < WORDS; i++)
    {
        printf("%s\n", cracked[i]);  //Írjuk ki a feltört jelszót!
    }

    runtime = (double) (end - start) / CLOCKS_PER_SEC;
    printf("runtime: %f", runtime);
    return 1;
}

char *randomString(int len) //Random string generálás a Posix feladatból
{
    char *str = malloc((len + 1) * sizeof(char));
    int i;
    for (i = 0; i < len; i++) {
        str[i] = ALPHABET[intN(strlen(ALPHABET))];
    }
    str[len] = '\0';
    return str;
}

int intN(int n)
{
    return rand() % n;
}

char crack(char letter)
{
    int i;
    for (i = 0; i<36; i++) //Végignézzük az összes betűt (brute force)
    {
        if (letter == ALPHABET[i])
        return ALPHABET[i];
    }
    return '-';
}
