#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define N 134217728//2 valamilyen hatványa az effektivitás megnöveléséhez
#define THREADS 8
#define LOOKING_FOR 'c'

typedef struct args{
    char str[N+1];
    char letter;
    int start, end;
    int thread_id;
}args;

char *randomString(int len);
int intN(int n);
void * count_letter(void * arg);
void inc_count();
void printTime(int thread_id, double time);
int count = 0; //GLobális: Minden szál érje el

pthread_mutex_t value_mutex = PTHREAD_MUTEX_INITIALIZER;
args param[THREADS];

int main(int argc, char **argv) {
    srand(time(NULL));
    pthread_t thread[THREADS];
    char *random_string = randomString(N); //n darab betű generálása

    printf("RANDOM GENERATED STRING:\n%s\n", random_string);
    for(int i=0; i<THREADS; i++)
    {
        param[i].letter = LOOKING_FOR;
        strcpy(param[i].str, random_string);//Átadjuk a generált szöveget a struktúrának
        param[i].start = N/THREADS*i;
        param[i].end = N/THREADS*(i+1);
        param[i].thread_id = i;
        pthread_create(&thread[i], NULL, count_letter, (void*)&param[i]);
    }

    for (int i=0; i<THREADS; i++)
    {
        pthread_join(thread[i], NULL);
    }
    printf("\n\nKiertekeles:\nRandom string hossza: %d\n", strlen(random_string));
    printf("Eredmeny: %d darab '%c' betut talaltunk!\n",count, LOOKING_FOR);
    //Számítás vége
}

void * count_letter(void * arg)
{
    clock_t start, end;
    double time;
    start = clock();
    args * param = (args*)arg;
    for (int i=param->start; i<param->end; i++)
    {
        if (param->str[i] == param->letter)
            inc_count();
    }
    end = clock();
    time = (double) (end - start) / CLOCKS_PER_SEC;
    printTime(param->thread_id, time);
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

void inc_count(){
    pthread_mutex_lock(&value_mutex);
    count++;
    pthread_mutex_unlock(&value_mutex);
}

void printTime(int thread_id, double time)
{
    pthread_mutex_lock(&value_mutex);
    printf("[thread %d] Ennyi idot dolgoztam: %f\n", thread_id, time);
    pthread_mutex_unlock(&value_mutex);
}
