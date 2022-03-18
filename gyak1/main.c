#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{

    int c, n;
    float m;

  printf("Ten random numbers in [1,100]\n");
    srand(time(NULL));
  for (c = 1; c <= 10; c++) {
    n = rand()%(1000-500)+500;
    printf("%d\n", n);
  }

  printf("Ten random numbers in [1,100]\n");
  for (c = 1; c <= 10; c++) {
     m = (rand() % (1000-500)+500) +((float)(rand()%100)/100);
    printf("%f\n", m);
  }
    return 0;
}
