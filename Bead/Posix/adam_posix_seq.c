#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 134217728
char *randomString(int len);
int intN(int n);
int count_letter(char * str, char letter, int start, int end);

int main(int argc, char **argv) {
    srand(time(NULL));
    char *p;
    int count;
    clock_t start, end;
    double time;

    p = randomString(N); //n darab betű generálása
    char letter = 'a';
    start = clock();
    count = count_letter(p, letter, 0, strlen(p));
    end = clock();
    time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("%s\n", p);
    printf("\n\nKiertekeles:\nRandom string hossza: %d\n", strlen(p));
    printf("Eredmeny: %d darab '%c' betut talaltam!\n", count, letter);
    printf("Szamitasi ideje: %f", time);
}

int count_letter(char * str, char letter, int start, int end)
{
    int count = 0;
    for (int i=start; i<end; i++)
    {
        if ((str[i] == letter))
            count++;
    }
    return count;
}

char *randomString(int len) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char *str = malloc((len + 1) * sizeof(char));
    int i;
    for (i = 0; i < len; i++) {
        str[i] = alphabet[intN(strlen(alphabet))];
    }
    str[len] = '\0';
    return str;
}

int intN(int n) {
    return rand() % n;
}
