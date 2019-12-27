//#include "hauffman.h";
#include <stdio.h>
#include <stdlib.h>


struct Node
{
    unsigned char key;
    int occ;
    struct Node* left;
    struct Node* right;
};

struct Lode {
    int isLeaf;
    unsigned char cle;
    int oc;
};

int current = -1;
struct Lode** array;

struct Node* buildTree(){
    
    struct Node* node = malloc(sizeof(struct Node));
    current++;

    if((*(array+current))->isLeaf){
        node->key = (*(array+current))->cle;
        node->occ = (*(array+current))->oc;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    
    node->key = (*(array+current))->cle;
    node->occ = (*(array+current))->oc;
    node->left = buildTree();
    node->right = buildTree();

    return node;
}


void preOrder(struct Node *head){
    if(head == NULL)
        return;
    printf("(%c, %d) ", head->key, head->occ);
    
    preOrder(head->left);
    preOrder(head->right);
}

int main(int args, char** argv){
    
    struct Node* head = malloc(sizeof(struct Node));
    
    struct Lode uno = {.isLeaf = 0, .cle = 48, .oc = 9};
    struct Lode dos = {.isLeaf = 0, .cle = 48, .oc = 5};
    struct Lode tres = {.isL eaf = 1, .cle = 119, .oc = 3};
    struct Lode cuatro = {.isLeaf = 1, .cle = 105, .oc = 2};
    struct Lode cinco = {.isLeaf = 0, .cle = 48, .oc = 4};
    struct Lode seis = {.isLeaf = 0, .cle = 48, .oc = 2};
    struct Lode seite = {.isLeaf = 1, .cle = 97, .oc = 1};
    struct Lode ocho = {.isLeaf = 1, .cle = 78, .oc = 1};
    struct Lode nueve = {.isLeaf = 0, .cle = 48, .oc = 2};
    struct Lode diez = {.isLeaf = 1, .cle = 108, .oc = 1};
    struct Lode once = {.isLeaf = 1, .cle = 98, .oc = 1};
    
    array = malloc(11 * sizeof(struct Lode*));
    
    *(array + 0) = &uno;
    *(array + 1) = &dos;
    *(array + 2) = &tres;
    *(array + 3) = &cuatro;
    *(array + 4) = &cinco;
    *(array + 5) = &seis;
    *(array + 6) = &seite;
    *(array + 7) = &ocho;
    *(array + 8) = &nueve;
    *(array + 9) = &diez;
    *(array + 10) = &once;
    
    head = buildTree();
    
    preOrder(head);
    printf("Test\n");
    
    return EXIT_SUCCESS;
}
