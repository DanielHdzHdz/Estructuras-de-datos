// Universidad Autonoma Nacional de Mexico
// FACULTAD DE CONTADURÍA Y ADMINISTRACION
// INFORMATICA A DISTANCIA
// Programa creado por Daniel Hernandez Hernandez el 07/04/2025
// Asignatura: Estructura de Datos 2331
// Profesor: MORALES HERNANDEZ GUSTAVO ARMANDO

#include <stdio.h>
#include <string.h>

#define NUM_SONGS 10

// Función para intercambiar dos cadenas
void swap(char *a, char *b)
{
    char temp[100];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

// Función para particionar el arreglo
int partition(char arr[][100], int low, int high, int ascending)
{
    char pivot[100];
    strcpy(pivot, arr[high]);
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if ((ascending && strcmp(arr[j], pivot) < 0) || (!ascending && strcmp(arr[j], pivot) > 0))
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Función recursiva de Quick Sort
void quickSort(char arr[][100], int low, int high, int ascending)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, ascending);

        quickSort(arr, low, pi - 1, ascending);
        quickSort(arr, pi + 1, high, ascending);
    }
}

// Función para imprimir el arreglo
void printArray(char arr[][100], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s\n", arr[i]);
    }
}

int main()
{
    char Cancion[NUM_SONGS][100] = {
        "Ante Tus Ojos (feat. Santi Novoa & Warcry)",
        "Hazme un sitio entre tu piel (feat. Víctor G...)",
        "Cabecita Dura",
        "Mi Segunda Vida",
        "Dame Tu Mano",
        "Si Creíste En Mí",
        "Llamada De Mi Ex",
        "Cosas Que Nunca Te Dije",
        "Alebrije",
        "Like A Rolling Stone - Live / Remastered"};

    printf("Arreglo original:\n");
    printArray(Cancion, NUM_SONGS);

    // Ordenar de manera ascendente
    quickSort(Cancion, 0, NUM_SONGS - 1, 1);
    printf("\nArreglo ordenado en orden ascendente:\n");
    printArray(Cancion, NUM_SONGS);

    // Ordenar de manera descendente
    quickSort(Cancion, 0, NUM_SONGS - 1, 0);
    printf("\nArreglo ordenado en orden descendente:\n");
    printArray(Cancion, NUM_SONGS);

    return 0;
}
// Programador: Daniel Hernandez Hernandez
// Programa para ordenar un arreglo de canciones
// Fecha: 07 de abril de 2025
