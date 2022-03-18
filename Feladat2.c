#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv){

    clock_t tStrart = clock();

    int meret = 5000;
    int array [meret];
    srand(time(NULL));

    for(int i =0 ; i<meret;i++){
        array[i] = rand()%(2000000-0)+0;
        }
    printf("Eltelt ido %.5fs\n", (double)(clock()-tStrart)/CLOCKS_PER_SEC);

    egyedseg(array,meret);
}

void egyedseg(int *array,int meret){
    clock_t tStrart = clock();
    int i,j, k;
    for(i=0;i<meret-1;i++){
        for(j=i+1;j<meret;j++){
            if(array[i]==array[j]){
              k=1;
              break;
            }
        }
    }
    if(k==1){
        printf("nem egyedi minden elem\n");
    }
    else{
        printf("minden elem egyedi\n");
    }
    printf("Eltelt ido %.5fs\n", (double)(clock()-tStrart)/CLOCKS_PER_SEC);
}

