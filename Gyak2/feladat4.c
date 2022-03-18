#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv){
    int RANDOM_STRING_LENGTH =31950;
    char buf[RANDOM_STRING_LENGTH+1];
    int sum_A = 0;


    for (size_t i = 0; i < RANDOM_STRING_LENGTH; i++) {
        buf[i]     = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 \n"[rand() %38];
    }

    buf[RANDOM_STRING_LENGTH] = '\0';

    puts(buf);

    int sum = sumsor(buf,RANDOM_STRING_LENGTH,sum_A);
    printf("\nA szoveg %d sorbol all\n ", sum+1);

    int sum2 = sumsor2(buf,RANDOM_STRING_LENGTH,sum_A);
    printf("\nA szoveg %d sorbol all rekurziv\n ", sum2+1);

}

int sumsor(char *buf,int RANDOM_STRING_LENGTH, int sum_A){
    clock_t tStrart = clock();
    for(int i=RANDOM_STRING_LENGTH-1; i>-1;i--){
        if(buf[i] == '\n'){
            sum_A++;
        }
    }
    printf("Eltelt ido %.10fs\n", (double)(clock()-tStrart)/CLOCKS_PER_SEC);
    return sum_A;

}

int sumsor2(char *buf,int RANDOM_STRING_LENGTH, int sum_A){
   clock_t tStrart = clock();
   if(RANDOM_STRING_LENGTH == 0){
        printf("\nEltelt ido %.10fs\n", (double)(clock()-tStrart)/CLOCKS_PER_SEC);
        return sum_A;
   }else if(buf[RANDOM_STRING_LENGTH] == '\n'){
        sum_A++;
        return sumsor2(buf,RANDOM_STRING_LENGTH-1,sum_A);
   }
   else{
      return sumsor2(buf,RANDOM_STRING_LENGTH-1,sum_A);
   }
}
