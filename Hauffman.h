#ifndef hauffman_h
#define hauffman_h

#include <stdlib.h>
#include <stdio.h>

struct HauffmanNode
{
    unsigned char key;
    int occurences;
    struct HauffmanNode* left;
    struct HauffmanNode* right;
};

//////// sortNodes
void quickSort(int* arr, int low, int high);
void nodeQuickSort(struct HauffmanNode **arr, int low, int high);
void swapNode(struct HauffmanNode *n1, struct HauffmanNode *n2);

////////

struct HauffmanNode** nodesArray(int *ascii);
int* countOccurence(char* str);
void printNode(struct HauffmanNode node);
void buildTree(struct HauffmanNode** nodesArr, int low, int high);
#endif
