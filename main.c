#include "hauffman.h"

void preOrder(struct HauffmanNode *head){
    if(head == NULL)
        return;
    printf("%c %d \n", head->key, head->occurences);
    
    preOrder(head->left);
    preOrder(head->right);
}
int main(int args, char** argv)
{
    char* phrase = "Angel giwgiwwwww HadidiH always and foreverzz";
    char* hadid = "Nabiliwww";
    int *ascii = countOccurence(hadid);
    struct HauffmanNode **nodeTab = nodesArray(ascii);
    int f=0;
    int u=0;
    
    do {
        printNode(**(nodeTab+f));
        f++;
        
    } while (*(nodeTab+f)!= NULL);
    
    printf("\n\n------SORT-------\n\n\n");
    
    nodeQuickSort(nodeTab, 0, f-1);
    
    while(*(nodeTab+u)!= NULL)
    {
        printNode(**(nodeTab+u));
        u++;
    }
    
    printf("\n\n\n");
    buildTree(nodeTab, 0,f-1);
    preOrder(*(nodeTab+0));
//    printNode(*(*nodeTab+0));//->right->right->right->right->right));
    return EXIT_SUCCESS;
}
