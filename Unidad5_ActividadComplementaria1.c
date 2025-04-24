// Universidad Autonoma Nacional de Mexico
// FACULTAD DE CONTADURÍA Y ADMINISTRACION
// INFORMATICA A DISTANCIA
// Programa creado por Daniel Hernandez Hernandez el 23/04/2025
// Asignatura: Estructura de Datos 2331
// Profesor: MORALES HERNANDEZ GUSTAVO ARMANDO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para un nodo del arbol binario
typedef struct Nodo
{
    char titulo[100];
    char autor[100];
    struct Nodo *izquierdo;
    struct Nodo *derecho;
} Nodo;

// Funcion para crear un nuevo nodo
Nodo *crearNodo(const char *titulo, const char *autor)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    strcpy(nuevo->titulo, titulo);
    strcpy(nuevo->autor, autor);
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;
    return nuevo;
}

// Funcion para insertar un nodo en el arbol binario (ordenado por titulo)
Nodo *insertarNodo(Nodo *raiz, const char *titulo, const char *autor)
{
    if (raiz == NULL)
    {
        return crearNodo(titulo, autor);
    }
    if (strcmp(titulo, raiz->titulo) < 0)
    {
        raiz->izquierdo = insertarNodo(raiz->izquierdo, titulo, autor);
    }
    else if (strcmp(titulo, raiz->titulo) > 0)
    {
        raiz->derecho = insertarNodo(raiz->derecho, titulo, autor);
    }
    return raiz;
}

// Funcion para buscar un libro por titulo
Nodo *buscarPorTitulo(Nodo *raiz, const char *titulo)
{
    if (raiz == NULL || strcmp(titulo, raiz->titulo) == 0)
    {
        return raiz;
    }
    if (strcmp(titulo, raiz->titulo) < 0)
    {
        return buscarPorTitulo(raiz->izquierdo, titulo);
    }
    return buscarPorTitulo(raiz->derecho, titulo);
}

// Funcion para buscar un libro por autor
void buscarPorAutor(Nodo *raiz, const char *autor)
{
    if (raiz == NULL)
    {
        return;
    }
    buscarPorAutor(raiz->izquierdo, autor);
    if (strcmp(autor, raiz->autor) == 0)
    {
        printf("Titulo: %s, Autor: %s\n", raiz->titulo, raiz->autor);
    }
    buscarPorAutor(raiz->derecho, autor);
}

// Funcion para mostrar el menu
void mostrarMenu()
{
    printf("\n--- Menu ---\n");
    printf("1. Insertar libro\n");
    printf("2. Buscar libro por titulo\n");
    printf("3. Buscar libros por autor\n");
    printf("4. Salir\n");
    printf("Seleccione una opcion: ");
}

// Funcion principal
int main()
{
    Nodo *raiz = NULL;

    // Pre-cargar libros de Harry Potter y Juego de Tronos
    raiz = insertarNodo(raiz, "Harry Potter y la Piedra Filosofal", "J.K. Rowling");
    raiz = insertarNodo(raiz, "Harry Potter y la Camara Secreta", "J.K. Rowling");
    raiz = insertarNodo(raiz, "Harry Potter y el Prisionero de Azkaban", "J.K. Rowling");
    raiz = insertarNodo(raiz, "Juego de Tronos", "George R.R. Martin");
    raiz = insertarNodo(raiz, "Choque de Reyes", "George R.R. Martin");
    raiz = insertarNodo(raiz, "Tormenta de Espadas", "George R.R. Martin");

    int opcion;
    char titulo[100], autor[100];

    do
    {
        mostrarMenu();
        scanf("%d", &opcion);
        getchar(); // Limpiar el buffer

        switch (opcion)
        {
        case 1:
            printf("Ingrese el titulo del libro: ");
            fgets(titulo, 100, stdin);
            titulo[strcspn(titulo, "\n")] = '\0';
            printf("Ingrese el autor del libro: ");
            fgets(autor, 100, stdin);
            autor[strcspn(autor, "\n")] = '\0';
            raiz = insertarNodo(raiz, titulo, autor);
            printf("Libro insertado correctamente.\n");
            break;

        case 2:
            printf("Ingrese el titulo del libro a buscar: ");
            fgets(titulo, 100, stdin);
            titulo[strcspn(titulo, "\n")] = '\0';
            Nodo *resultadoTitulo = buscarPorTitulo(raiz, titulo);
            if (resultadoTitulo)
            {
                printf("Libro encontrado: Titulo: %s, Autor: %s\n", resultadoTitulo->titulo, resultadoTitulo->autor);
            }
            else
            {
                printf("Libro no encontrado.\n");
            }
            break;

        case 3:
            printf("Ingrese el autor a buscar: ");
            fgets(autor, 100, stdin);
            autor[strcspn(autor, "\n")] = '\0';
            printf("Libros encontrados:\n");
            buscarPorAutor(raiz, autor);
            break;

        case 4:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 4);

    return 0;
}
// Programador: Daniel Hernandez Hernandez
// Programa para gestionar una biblioteca de libros
// Fecha: 23 de abril de 2025
