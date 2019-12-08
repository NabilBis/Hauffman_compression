#include "hauffman.h"


///////////////////////////////
void preOrder(struct HauffmanNode *head){
    if(head == NULL)
        return;
    printf("%c %d \n", head->key, head->occurences);
    
    preOrder(head->left);
    preOrder(head->right);
}
///////////////////////////////

int main(int args, char** argv)
{
    int f=0;
    char* input = "Nabiliwww";
    int *ascii = countOccurence(input);
    struct HauffmanNode **nodeTab = nodesArray(ascii);
    
    while(*(nodeTab+f) != NULL)
        f++;
    
    nodeQuickSort(nodeTab, 0, f-1);
    buildTree(nodeTab, 0,f-1);
    preOrder(*(nodeTab+0));
    
    return EXIT_SUCCESS;
}
