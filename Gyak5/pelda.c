#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <string.h>
#include <pthread.h>


pthread_t tid[2];

void* Function(void *arg)
{
    unsigned long i = 0;
    pthread_t id = pthread_self();

    if(pthread_equal(id,tid[0]))
    {
        printf("\n Elso szal elindult\n");
    }
    else
    {
        printf("\n Masodik szal elindult\n");
    }

    for(i=0; i<(0xFFFFFFFF);i++);

    return NULL;
}

int main(void)
{
    int i =0;
    int hiba;

    while(i<2)
    {
        hiba = pthread_create(&(tid[i]),0,&Function,NULL);
        if(hiba!=0)
        {
            printf("\n nem sikerult letrehozni a szalat [%s]", strerror(hiba));
        }
        else
        {
            printf("\n Sikerult letrehozni a szalat [%s]");
        }
        i++;
    }
    sleep(5);
    return 0;
}
