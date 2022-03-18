#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(int argc, char** argv){


    int Array[N] = {2,6,7,8,9,8,5,3,5,6};

    int sum[N] = CREW_PREFIX(Array,N);

    for(int i=0;i<N;i++){
    printf("%d ",sum[i]);
    }
}

int CREW_PREFIX(int *Array, int N){
        int Y[N];
    if(N=1){
        Y[N]=Array[N];
        return Y;
    }
    else if(N>1){
        int K=N/2;
        for(int i = 0; i<K;i++){
            Y = Y + Array[N];
        }

        CREW_PREFIC(Array,K+1)
    }
    return Y;


}
