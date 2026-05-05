#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

#define N 5 
#define M 7 

int main(){
    int i, j; 
    int mt[N][M];
    int *p; 

    p = &mt[0][0]; // apunto al primer elemento

    srand(time(NULL));

    for(i = 0; i < N; i++) 
    {  
        for(j = 0; j < M; j++) 
        { 
            // calculamos la posición lineal en la memoria y accedemos mediante el operador * (puntero que apunta a [0][0] + calculo de filas con cant de columnas + calculo de columna en la fila actual)
            *(p + i * M + j) = 1 + rand() % 100;
            printf("%d   ", *(p + i * M + j)); 
        } 
        printf("\n"); 
    }

    return 0;
}