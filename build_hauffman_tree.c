#include "hauffman.h"

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


void mergeAndTranslate(struct HauffmanNode** nodeTab)
{
    int tabCount=0;
    
    while(*(nodeTab+tabCount)!= NULL) tabCount++;
    
    *(nodeTab+0) = mergeTwoNodes(*nodeTab, *(nodeTab+1));
    
    for(int w=1; w<tabCount-1; w++)
    {
        *(nodeTab+w) = *(nodeTab+w+1);
    }
    
    *(nodeTab+tabCount-1) = NULL;
}

void buildTree(struct HauffmanNode** nodesArr, int low, int high)
{
    if( *(nodesArr+1) == NULL) return;
    
    mergeAndTranslate(nodesArr);
    nodeQuickSort(nodesArr, low, high-1);
    buildTree(nodesArr, low, high-1);
    
}
