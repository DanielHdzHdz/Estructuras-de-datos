// Funcion para recorrer el arbol en orden (in-order) con paréntesis
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
