// Universidad Autonoma Nacional de Mexico
// FACULTAD DE CONTADURÍA Y ADMINISTRACION
// INFORMATICA A DISTANCIA
// Programa creado por Daniel Hernandez Hernandez el 23/03/2025
// Asignatura: Estructura de Datos 2331
// Profesor: MORALES HERNANDEZ GUSTAVO ARMANDO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ESTADOS 32

typedef struct
{
	char *nombre;
} Estado;

typedef struct
{
	Estado estados[MAX_ESTADOS];
	int matriz_adyacencia[MAX_ESTADOS][MAX_ESTADOS];
	int num_estados;
} Grafo;

// inicia el grafo estableciendo el número de estados en 0
// y la matriz de adyacencia en 0
void Init(Grafo *g)
{
	g->num_estados = 0;
	for (int i = 0; i < MAX_ESTADOS; i++)
	{
		g->estados[i].nombre = NULL;
		for (int j = 0; j < MAX_ESTADOS; j++)
		{
			g->matriz_adyacencia[i][j] = 0;
		}
	}
}
// encuentra el índice de un estado en el grafo
int encontrarindice(Grafo *g, const char *nombre)
{
	for (int i = 0; i < g->num_estados; i++)
	{
		if (strcmp(g->estados[i].nombre, nombre) == 0)
		{
			return i;
		}
	}
	return -1;
}
// agrega un nodo al grafo
void addNodo(Grafo *g, const char *nombre)
{
	if (g->num_estados >= MAX_ESTADOS)
	{
		printf("No se pueden agregar más estados\n");
		return;
	}
	g->estados[g->num_estados].nombre = strdup(nombre);
	g->num_estados++;
}
// agrega una arista entre dos estados en el grafo
void addEdge(Grafo *g, const char *origen, const char *destino)
{
	int i = encontrarindice(g, origen);
	int j = encontrarindice(g, destino);
	
	if (i == -1 || j == -1)
	{
		printf("No se encontró el estado\n");
		return;
	}
	g->matriz_adyacencia[i][j] = 1;
	g->matriz_adyacencia[j][i] = 1;
}
// imprime los vecinos de un estado según su índice
void imprimirVecinos(Grafo *g, int indice)
{
	for (int i = 0; i < g->num_estados; i++)
	{
		if (g->matriz_adyacencia[indice][i] == 1)
		{
			printf("%s ", g->estados[i].nombre);
		}
	}
	printf("\n");
}
// imprime el grafo completo, mostrando cada estado y sus vecinos
void imprimirGrafo(Grafo *g)
{
	for (int i = 0; i < g->num_estados; i++)
	{
		printf("%s -> ", g->estados[i].nombre);
		imprimirVecinos(g, i);
	}
}

int main()
{
	Grafo g;
	Init(&g);
	
	// Agregar estados
	addNodo(&g, "Ciudad de Mexico");
	addNodo(&g, "Estado de Mexico");
	addNodo(&g, "Morelos");
	addNodo(&g, "Guerrero");
	addNodo(&g, "Puebla");
	addNodo(&g, "Queretaro");
	addNodo(&g, "Hidalgo");
	addNodo(&g, "Tlaxcala");
	
	// Conexiones entre estados
	addEdge(&g, "Ciudad de Mexico", "Estado de Mexico");
	addEdge(&g, "Ciudad de Mexico", "Morelos");
	addEdge(&g, "Estado de Mexico", "Morelos");
	addEdge(&g, "Estado de Mexico", "Guerrero");
	addEdge(&g, "Estado de Mexico", "Queretaro");
	addEdge(&g, "Estado de Mexico", "Hidalgo");
	addEdge(&g, "Morelos", "Guerrero");
	addEdge(&g, "Morelos", "Puebla");
	addEdge(&g, "Morelos", "Estado de Mexico");
	addEdge(&g, "Puebla", "Tlaxcala");
	addEdge(&g, "Puebla", "Estado de Mexico");
	addEdge(&g, "Hidalgo", "Queretaro");
	
	// Imprimir grafo completo
	imprimirGrafo(&g);
	
	// Liberar memoria
	for (int i = 0; i < g.num_estados; i++)
	{
		free(g.estados[i].nombre);
	}
	
	return 0;
}
// Programador: Daniel Hernandez Hernandez
// Programa para imprimir un grafo de estados de la república mexicana y sus conexiones
// Fecha: 23 de marzo de 2025
