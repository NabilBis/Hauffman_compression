#include "hauffman.h"
    //// Hauffman STEPS:
        //// Count the occurences of a "Byte"
        //// Sort the occurences in an ascending order
        //// Merge two nodes (the head of the tree contains the sum of the merged nodes)
        //// Repeat step 2 and 3
    //// String

void addLeftNode(struct HauffmanNode *node, struct HauffmanNode *left)
{
    node->left = left;
}

void addRightNode(struct HauffmanNode *node, struct HauffmanNode *right)
{
    node->right = right;
}


struct HauffmanNode* mergeTwoNodes(struct HauffmanNode *right, struct HauffmanNode *left)
{
    struct HauffmanNode *node = malloc(sizeof(struct HauffmanNode));
    
    node->key = 48;
    node->occurences = right->occurences + left->occurences;
    addRightNode(node, right);
    addLeftNode(node, left);
    
    return node;
}

struct HauffmanNode* newNode(unsigned char key, int occ)
{
    struct HauffmanNode *node = malloc(sizeof(struct HauffmanNode));
    
    node->key = key;
    node->occurences = occ;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct HauffmanNode** nodesArray(int *ascii)
{
    struct HauffmanNode **nodeArr;
    int j=0;
    int n=0;
    unsigned char index = 0;
    
    for(int l=0; l<256; l++)
    {
        if(*(ascii+l))
        {
            j++;
        }
    }

    nodeArr = malloc((j+1)*sizeof(struct HauffmanNode*));
    for(int u=0; u<=255; u++)
    {
        if(*(ascii+u))
        {
            *(nodeArr+n) = newNode(index, *(ascii+u));
            n++;
        }
        index++;
    }
    
    *(nodeArr+n) = NULL;
    
    return nodeArr;
}


int* countOccurence(char* str)
{
    int *ascii = malloc(256*sizeof(int));
    int i=0;
    unsigned char index;
    
    for(int f=0; f<256; f++)
        *(ascii+f) = 0;
    
    while(*(str + i) != '\0')
    {
        index = *(str+i);
        (*(ascii+index))++;
        i++;
    }
    
    return ascii;
}

void printNode(struct HauffmanNode node)
{
//    printf("Hauffman Node :\n  char = %c\n    ascii code = %u\n      occurences = %d\n\n", (char)node.key, node.key, node.occurences);
    printf("(%c , %d)    \n", (char)node.key, node.occurences);
}

void mergeAndTranslate(struct HauffmanNode** nodeTab)
{
    int tabCount=0;
//    printf("\n++++++\n");printNode(**(nodeTab+1));printf("-----\n");
    while(*(nodeTab+tabCount)!= NULL) tabCount++;
    
    *(nodeTab+0) = mergeTwoNodes(*nodeTab, *(nodeTab+1));
    
    for(int w=1; w<tabCount-1; w++)
    {
        *(nodeTab+w) = *(nodeTab+w+1);
    }
//    printf("\n--%d--\n", tabCount);printNode(**(nodeTab+1));printf("-----\n");
    *(nodeTab+tabCount-1) = NULL;
}
void buildTree(struct HauffmanNode** nodesArr, int low, int high)
{
//    if((*nodesArr+0)->left != NULL)
//        printNode(*(*nodesArr+0)->left);
    if( *(nodesArr+1) == NULL) return;
    
    mergeAndTranslate(nodesArr);
    nodeQuickSort(nodesArr, low, high-1);
    buildTree(nodesArr, low, high-1);

}


