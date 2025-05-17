// Universidad Autonoma Nacional de Mexico
// FACULTAD DE CONTADURÍA Y ADMINISTRACION
// INFORMATICA A DISTANCIA
// Programa creado por Daniel Hernandez Hernandez el 16/05/2025
// Asignatura: Matematicas Discretas 2333
// Profesor: Karina Torres Reyes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para un nodo del arbol binario
typedef struct Nodo
{
    char titulo[100];
    int calificacion;
    struct Nodo *izquierdo;
    struct Nodo *derecho;
} Nodo;

// Funcion para crear un nuevo nodo
Nodo *crearNodo(const char *titulo, int calificacion)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    strcpy(nuevo->titulo, titulo);
    nuevo->calificacion = calificacion;
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;
    return nuevo;
}

// Funcion para insertar un nodo en el arbol binario
Nodo *insertarNodo(Nodo *raiz, const char *titulo, int calificacion)
{
    if (raiz == NULL)
    {
        return crearNodo(titulo, calificacion);
    }
    if (strcmp(titulo, raiz->titulo) < 0)
    {
        raiz->izquierdo = insertarNodo(raiz->izquierdo, titulo, calificacion);
    }
    else if (strcmp(titulo, raiz->titulo) > 0)
    {
        raiz->derecho = insertarNodo(raiz->derecho, titulo, calificacion);
    }
    return raiz;
}

// Funcion para buscar un nodo por titulo
Nodo *buscarNodo(Nodo *raiz, const char *titulo)
{
    if (raiz == NULL || strcmp(titulo, raiz->titulo) == 0)
    {
        return raiz;
    }
    if (strcmp(titulo, raiz->titulo) < 0)
    {
        return buscarNodo(raiz->izquierdo, titulo);
    }
    return buscarNodo(raiz->derecho, titulo);
}

// Funcion para encontrar el nodo mas pequeño (usado en eliminacion)
Nodo *encontrarMinimo(Nodo *raiz)
{
    while (raiz->izquierdo != NULL)
    {
        raiz = raiz->izquierdo;
    }
    return raiz;
}

// Funcion para eliminar un nodo del arbol
Nodo *eliminarNodo(Nodo *raiz, const char *titulo)
{
    if (raiz == NULL)
    {
        return NULL;
    }
    if (strcmp(titulo, raiz->titulo) < 0)
    {
        raiz->izquierdo = eliminarNodo(raiz->izquierdo, titulo);
    }
    else if (strcmp(titulo, raiz->titulo) > 0)
    {
        raiz->derecho = eliminarNodo(raiz->derecho, titulo);
    }
    else
    {
        if (raiz->izquierdo == NULL)
        {
            Nodo *temp = raiz->derecho;
            free(raiz);
            return temp;
        }
        else if (raiz->derecho == NULL)
        {
            Nodo *temp = raiz->izquierdo;
            free(raiz);
            return temp;
        }
        Nodo *temp = encontrarMinimo(raiz->derecho);
        strcpy(raiz->titulo, temp->titulo);
        raiz->calificacion = temp->calificacion;
        raiz->derecho = eliminarNodo(raiz->derecho, temp->titulo);
    }
    return raiz;
}

// Funcion para mostrar todos los libros en orden alfabetico
void mostrarLibros(Nodo *raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    mostrarLibros(raiz->izquierdo);
    printf("Titulo: %s, Calificacion: %d\n", raiz->titulo, raiz->calificacion);
    mostrarLibros(raiz->derecho);
}

// Funcion para mostrar el menu
void mostrarMenu()
{
    printf("\n--- Menu ---\n");
    printf("1. Ver lista de libros\n");
    printf("2. Agregar nuevo libro\n");
    printf("3. Eliminar libro\n");
    printf("4. Buscar libro\n");
    printf("5. Salir\n");
    printf("Seleccione una opcion: ");
}

// Funcion principal
int main()
{
    Nodo *raiz = NULL;

    // Otros libros añadidos
    raiz = insertarNodo(raiz, "La Comunidad del Anillo", 9);
    raiz = insertarNodo(raiz, "Las Dos Torres", 9);
    raiz = insertarNodo(raiz, "El Retorno del Rey", 9);
    raiz = insertarNodo(raiz, "Harry Potter y el Caliz de Fuego", 10);
    raiz = insertarNodo(raiz, "El Principito", 8);
    raiz = insertarNodo(raiz, "El Psicoanalista", 7);

    int opcion;
    char titulo[100];
    int calificacion;

    do
    {
        mostrarMenu();
        scanf("%d", &opcion);
        getchar();

        switch (opcion)
        {
        case 1:
            printf("\nLista de libros:\n");
            mostrarLibros(raiz);
            break;

        case 2:
            printf("Ingrese el titulo del libro: ");
            fgets(titulo, 100, stdin);
            titulo[strcspn(titulo, "\n")] = '\0';
            printf("Ingrese la calificacion del libro (1-10): ");
            scanf("%d", &calificacion);
            getchar(); // Limpiar el buffer
            raiz = insertarNodo(raiz, titulo, calificacion);
            printf("Libro agregado correctamente.\n");
            break;

        case 3:
            printf("Ingrese el titulo del libro a eliminar: ");
            fgets(titulo, 100, stdin);
            titulo[strcspn(titulo, "\n")] = '\0';
            raiz = eliminarNodo(raiz, titulo);
            printf("Libro eliminado correctamente (si existia).\n");
            break;

        case 4:
            printf("Ingrese el titulo del libro a buscar: ");
            fgets(titulo, 100, stdin);
            titulo[strcspn(titulo, "\n")] = '\0';
            Nodo *resultado = buscarNodo(raiz, titulo);
            if (resultado)
            {
                printf("Libro encontrado: Titulo: %s, Calificacion: %d\n", resultado->titulo, resultado->calificacion);
            }
            else
            {
                printf("Libro no encontrado.\n");
            }
            break;

        case 5:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 5);

    return 0;
}
// Programador: Daniel Hernandez Hernandez
// Programa para gestionar una biblioteca de libros
// Fecha: 16 de mayo de 2025
