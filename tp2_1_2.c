// VERSION CON ARITMETICA DE PUNTEROS
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#define N 20 

int main(){
    int i; 
    double vt[N];
    double *punt;
    
    punt = vt;

    srand(time(NULL));

    for(i = 0;i<N; i++) 
    {  
        punt[i]=1+rand()%100; 
        printf("%f      ", punt[i]); 
    } 

    return 0;
}