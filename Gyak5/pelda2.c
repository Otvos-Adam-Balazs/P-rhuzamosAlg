#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <windows.h>
#include <time.h>
const int N_THREADS = 2;
#define M 500000

struct arrays
{
    long array;
};
/**
 * Wait random time.
 */
void wait_random_time(void* _)
{
  int wait_time;

  pthread_t tid = pthread_self();
  wait_time = rand() % (100000 - 6000)+6000;
  printf("[%d] Wait %d seconds ...\n", tid, wait_time/1000);
  Sleep(wait_time);
  printf("[%d] Ready!\n", tid);
}

void arraysum(long *aray)
{
    long sum = 0;
    for(int i = 0;i<M;i++)
    {
        sum+=aray[i];
        printf("\n%d",sum);
    }
}

/**
 * Main
 */
int main(int argc, char* argv[])
{
    clock_t tStrart = clock();
  pthread_t threads[N_THREADS];
  int i;

  struct arrays aray[M];
  srand(time(NULL));
  for(i=0 ;i<M;i++){
    aray[i].array = rand() % (100 - 60)+60;
  }

  printf(":: Start threads ...\n");
  for (i = 0; i < N_THREADS; ++i) {
    pthread_create(&threads[i], NULL, /*ide kell majd a fgv*/arraysum, aray);
  }

  printf(":: Join threads ...\n");
  for (i = 0; i < N_THREADS; ++i) {
    pthread_join(threads[i], NULL);
  }

  printf(":: Ready.\n");
    printf("\nEgéesz Eltelt ido3 %.5fs\n", (double)(clock()-tStrart)/CLOCKS_PER_SEC);
  return 0;
}
