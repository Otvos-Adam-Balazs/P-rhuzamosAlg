#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv){
    clock_t tStrart = clock();
    int N = 90000;
    double array[N];

    srand(time(NULL));
    for (int i = 0; i <= N; i++) {
     array[i] = (rand() % (100-1)+1)+((float)(rand()%100)/100);

    }
      for(int i = N-1 ; i>0;i--)
      {
          for(int j = 0; j<i;j++){
            if(array[j]>array[j+1]){
                double temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
          }
      }

      for (int i = 0; i <= N; i++) {
      printf("%f, ", array[i]);
      }

        double random;
        random = (rand() % (100-1)+1)+((float)(rand()%100)/100);

      binsearch(array, N, random);
      printf("\nEgéesz Eltelt ido3 %.5fs\n", (double)(clock()-tStrart)/CLOCKS_PER_SEC);
      binsearch2(array, random,N-1,0);
      printf("\nEgéesz Eltelt ido3 %.5fs\n", (double)(clock()-tStrart)/CLOCKS_PER_SEC);
    return 0;
}

void binsearch(double *array,int N, double random){

    clock_t tStrart = clock();

    int bottom = 0;
    int top = N-1;
    int result = 7;

    while(bottom <= top)
    {
        int middle = (bottom + top)/2;

        if(array[middle] == random){
            printf("\nvan egyforma elem %f\n", random);
            printf("\nEltelt ido %.5fs\n", (double)(clock()-tStrart)/CLOCKS_PER_SEC);
            break;
        }
        else if(array[middle] < random){
            bottom = middle+1;
        }
        else{
                top = middle-1;
        }
    }
}
void binsearch2(double *array,double random,int N, int bottom){

    clock_t tStrart = clock();

     while(bottom <= N)
    {
        int middle = (bottom + N)/2;

        if(array[middle] == random){

            printf("\n Rekurzivan van egyforma elem %f\n", random);
            printf("\n Rekurzív Eltelt ido %.5fs\n", (double)(clock()-tStrart)/CLOCKS_PER_SEC);
            break;
        }
        else if(array[middle] < random){
            return binsearch2(array,random,N,middle+1);
        }
        else{
                return binsearch2(array,random,middle-1,bottom);
        }
    }

}
