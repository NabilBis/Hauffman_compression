#include "hauffman.h"


int length = -1;
unsigned short code = 0;

//void preOrder(struct HauffmanNode *head){
//    if(head == NULL)
//        return;
//    printf("%c %d \n", head->key, head->occurences);
//    
//    preOrder(head->left);
//    preOrder(head->right);
//}

int* countOccurence(int fileDescriptor)
{
    int *ascii = malloc(256*sizeof(int));
    unsigned char *buffer= malloc(sizeof(char));
    int i=0;
    unsigned char index;
    
    for(int f=0; f<256; f++)
        *(ascii+f) = 0;
    
    while(read(fileDescriptor, buffer, 1))
    {
        index = *buffer;
        (*(ascii+index))++;
        i++;
    }
    free(buffer);
    return ascii;
}

void preOrderCode(struct HauffmanNode *head, int direc){

    length++;

    if(direc){
        code <<= 1;
        code |= 1;
    } else {
        code <<= 1;
    }

    if(head->left == NULL && head->right == NULL){
        printf(" %c code -> %d ,  lenght %d \n", head->key, code, length);
        code >>= 1;
        length--;
        return;
    }

    preOrderCode(head->left, 0);
    preOrderCode(head->right, 1);
    length--;
    code >>= 1;
}

void compress(int fileDsc){

    int *ascii;
    struct HauffmanNode **nodeTab;
    int f = 0;
    
    ascii = countOccurence(fileDsc);
    nodeTab = nodesArray(ascii);
    
    while(*(nodeTab+f) != NULL)  f++;
    
    nodeQuickSort(nodeTab, 0, f-1);
    buildTree(nodeTab, 0, f-1);
    preOrderCode(*(nodeTab+0), 0);
    
    
    ///////////// Write time

}




