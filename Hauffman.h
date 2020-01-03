#ifndef hauffman_h
#define hauffman_h

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

struct HauffmanNode
{
    unsigned char key;
    int occurences;
    struct HauffmanNode* left;
    struct HauffmanNode* right;
};

//////// sortNodes
void nodeQuickSort(struct HauffmanNode **arr, int low, int high);
////////

struct HauffmanNode** nodesArray(int *ascii);
void buildTree(struct HauffmanNode** nodesArr, int low, int high);
void compress(int);
#endif
