//Universidas Atonoma Nacional de Mexico
//FACULTAD DE CONTADURÍA Y ADMINISTRACION
//INFORMATICA A DISTANCIA
//Programa creado por Daniel Hernandez Hernandez el 24/02/2025
//Asignatura: Estructura de Datos 2331
//Profesor: MORALES HERNANDEZ GUSTAVO ARMANDO

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Estructura del nodo
typedef struct Node {
	char op;
	int value;
	struct Node *left, *right;
} Node;

// Funcion para crear un nodo con valor
Node *createValueNode(int value) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->op = '\0';
	node->value = value;
	node->left = node->right = NULL;
	return node;
}

// Funcion para crear un nodo con operador
Node *createOpNode(char op, Node *left, Node *right) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->op = op;
	node->value = 0;
	node->left = left;
	node->right = right;
	return node;
}

// Funcion para verificar si el arbol esta vacio
bool isEmpty(Node *root) {
	return root == NULL;
}

// Funcion para recorrer el arbol en orden 
void printInOrder(Node *root) {
	if (root != NULL) {
		if (root->left != NULL || root->right != NULL) {
			printf("(");
		}
		printInOrder(root->left);
		if (root->op == '\0') {
			printf("%d", root->value);
		} else {
			printf(" %c ", root->op);
		}
		printInOrder(root->right);
		if (root->left != NULL || root->right != NULL) {
			printf(")");
		}
	}
}

// Funcion para evaluar la expresion almacenada en el arbol
int evaluate(Node *root) {
	if (root == NULL) return 0;
	if (root->op == '\0') return root->value;
	
	int leftVal = evaluate(root->left);
	int rightVal = evaluate(root->right);
	
	switch (root->op) {
	case '+': return leftVal + rightVal;
	case '-': return leftVal - rightVal;
	case '*': return leftVal * rightVal;
	case '^': return pow(leftVal, rightVal);
	default: return 0;
	}
}

// Funcion para insertar un nodo en el arbol
Node *insert(Node *root, Node *node) {
	// Implementación específica segun el tipo de árbol
	return root;
}

// Funcion para eliminar un nodo del arbol 
Node *delete(Node *root, int value) {
	// Implementación especifica segun el tipo de arbol
	return root;
}

int main() {
	// Crear el arbol para la expresion 1 * ((3 ^ 4) + 2)
	Node *n1 = createValueNode(1);
	Node *n3 = createValueNode(3);
	Node *n4 = createValueNode(4);
	Node *n2 = createValueNode(2);
	
	Node *exp3_4 = createOpNode('^', n3, n4);
	Node *exp3_4_plus_2 = createOpNode('+', exp3_4, n2);
	Node *root = createOpNode('*', n1, exp3_4_plus_2);
	
	// Imprimir el arbol en orden
	printf("Expresion en orden: ");
	printInOrder(root);
	printf("\n");
	
	// Calcular y mostrar el resultado
	printf("Resultado de la evaluacion: %d\n", evaluate(root));
	
	return 0;
}

//Programador: Daniel Hernandez Hernandez
//Programa para imprimir un arbol binario de una expresion matematica y evaluarla
//Fecha: 19 de marzo de 2025
