#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORDS 93000 //A kigenerált jelszavak száma
#define LENGTH 10 //A kigenerált jelszavak hossza
#define ALPHABET "abcdefghijklmnopqrstuvwxyz0123456789"

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

    printf("Passowrds to crack:\n");
    //Jelszavak generálása
    /*for (i = 0; i < WORDS; i++)
    {
        strcpy(words[i], randomString(LENGTH));
        printf("%s\n", words[i]);
    }*/

    printf("\nCrack:\n");
    start = clock();
    for (i = 0; i < WORDS; i++)
    {
        for (j = 0; j < LENGTH; j++)
        {
           cracked[i][j] = crack(words[i][j]);
        }
        cracked[i][LENGTH] = '\0';
        //printf("%s\n", cracked[i]); //Kiírást nem számoljuk ezért kivesszük!
    }
    end = clock();
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
    for (i = 0; i<36; i++)
    {
        if (letter == ALPHABET[i])
        return ALPHABET[i];
    }
    return '-';
}
