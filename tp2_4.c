#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

struct 
{
    int velocidad; // Velocidad de procesamiento en GHz (valor entre 1 y 3) 
    int anio; // Año de fabricación (valor entre 2015 y 2024) 
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8) 
    char *tipo_cpu; // Tipo de procesador (apuntador a cadena de caracteres) 
} typedef compu;

char tipos[6][10] = {
    "Intel", 
    "AMD", 
    "Celeron", 
    "Athlon", 
    "Core", 
    "Pentium"
}; 

void listarPCs(compu pcs[], int cantidad);
void mostrarMasAntigua(compu pcs[], int cantidad);
void mostrarMasVeloz(compu pcs[], int cantidad); 

int main(){
    
    compu arregloCompus[5];
    
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        arregloCompus[i].velocidad = 1 + rand()%3;
        arregloCompus[i].anio = 2015 + rand()%10;
        arregloCompus[i].cantidad_nucleos = 1 + rand()%8;
        arregloCompus[i].tipo_cpu = tipos[rand()%6]; // le mando de la primera letra de la palabra (el inicio del elemento con el indice random), es decir, &tipos[random][0]
    }

    listarPCs(arregloCompus,5);
    mostrarMasAntigua(arregloCompus,5);
    mostrarMasVeloz(arregloCompus,5);
    
    return 0;
}

void listarPCs(compu pcs[], int cantidad){
    printf("\n-------------------------- FUNCION listarPcs() -------------------------- \n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("|--- PC nro %d ---|\n", i+1);
        printf("Velocidad = %d GHz\n", pcs[i].velocidad);
        printf("Anio de fabricacion = %d\n", pcs[i].anio);
        printf("Cantidad de nucleos = %d\n", pcs[i].cantidad_nucleos);
        printf("Tipo de procesador = '%s'\n", pcs[i].tipo_cpu);
        printf("\n");
    }    
}

void mostrarMasAntigua(compu pcs[], int cantidad){
    int indice = 0, masAnt = pcs[0].anio;

    for (int i = 0; i < cantidad; i++)
    {
        if (pcs[i].anio < masAnt)
        {
            masAnt = pcs[i].anio;
            indice = i;
        }
    }
    
    printf("\n-------------------------- FUNCION mostrarMasAntigua() -------------------------- \n");
    printf("| --- PC nro %d (ANIO %d)--- |\n", indice+1, pcs[indice].anio);
    printf("Velocidad = %d GHz\n", pcs[indice].velocidad);
    printf("Cantidad de nucleos = %d\n", pcs[indice].cantidad_nucleos);
    printf("Tipo de procesador = '%s'\n", pcs[indice].tipo_cpu);
    printf("\n");
}

void mostrarMasVeloz(compu pcs[], int cantidad){
    int indice = 0, velMax = pcs[0].velocidad;

    for (int i = 0; i < cantidad; i++)
    {
        if (pcs[i].velocidad > velMax)
        {
            velMax = pcs[i].velocidad;
            indice = i;
        }
    }
    
    printf("\n-------------------------- FUNCION mostrarMasVeloz() -------------------------- \n");
    printf("| --- PC nro %d (%d GHz)--- |\n", indice+1, pcs[indice].velocidad);
    printf("Anio de fabricacion = %d\n", pcs[indice].anio);
    printf("Cantidad de nucleos = %d\n", pcs[indice].cantidad_nucleos);
    printf("Tipo de procesador = '%s'\n", pcs[indice].tipo_cpu);
    printf("\n");
}
