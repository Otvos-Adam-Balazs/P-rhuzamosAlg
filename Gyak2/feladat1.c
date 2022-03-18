#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv){
    //clock_t tStrart = clock();

    int meret = 30000;
    int array[meret];

    srand(time(NULL));
    for (int c = 0; c < meret; c++) {
    array[c] = rand()% 100000;
    }

    int Sum = arraySum(array, meret);
    printf("Az ertekuk: %d\n", Sum);
    //printf("Eltelt ido %.5fs\n", (double)(clock()-tStrart)/CLOCKS_PER_SEC);

    int Max = MaxValue(array, meret);
    printf("Legnagyobb ertek: %d\n", Max);
    //printf("Eltelt ido %.5fs\n", (double)(clock()-tStrart)/CLOCKS_PER_SEC);

    int Min = MinValue(array, meret);
    printf("Legkisebb ertek: %d\n", Min);
    //printf("Eltelt ido %.5fs\n", (double)(clock()-tStrart)/CLOCKS_PER_SEC);

    int Sum2 = arraySum2(array, meret);
    printf("Az ertekuk: %d\n", Sum2);
    //printf("Rekurziv Eltelt ido %.5fs\n", (double)(clock()-tStrart)/CLOCKS_PER_SEC);
    return 0;
}

int arraySum(int *array, int meret){
    clock_t tStrart = clock();
    int i;
    int Sum = 0;
    for(i=0;i<meret;i++){
        Sum+= array[i];
    }
    printf("Eltelt ido %.5fs\n", (double)(clock()-tStrart)/CLOCKS_PER_SEC);
    return Sum;
}

int MaxValue(int *array, int meret){
    clock_t tStrart = clock();
    int i;
    int Max = 0;
    for(i=0;i<meret;i++){
        if(array[i] > Max){
            Max = array[i];
        }
    }
    printf("Eltelt ido %.5fs\n", (double)(clock()-tStrart)/CLOCKS_PER_SEC);
    return Max;
}

int MinValue(int *array, int meret){
    clock_t tStrart = clock();
    int i;
    int Min=100000100;
    for(i=0;i<meret;i++){
        if(array[i] < Min){
            Min = array[i];
        }
    }
    printf("Eltelt ido %.5fs\n", (double)(clock()-tStrart)/CLOCKS_PER_SEC);
    return Min;
}

int arraySum2(int *array,int meret){
    clock_t tStrart = clock();
    int sum;
    if(meret == 0){
        printf("Eltelt ido %.5fs\n", (double)(clock()-tStrart)/CLOCKS_PER_SEC);
        return sum;
    }
    else{
        sum=array[meret-1];
        return sum + arraySum2(array, meret-1);
    }
    }


