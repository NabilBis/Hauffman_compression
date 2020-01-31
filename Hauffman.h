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

struct CODE {
    unsigned short code;
    unsigned int length;
};

struct Lode {
    char isLeaf;
    unsigned char cle;
    int oc;
};

struct CODE *arr_code;
int treeDepth, extensionSize;

void nodeQuickSort(struct HauffmanNode **arr, int low, int high);

struct HauffmanNode** nodesArray(int *ascii);
void buildTree(struct HauffmanNode** nodesArr, int low, int high);
char** get_file_nm_ext(char* fileName);
void concactStr(char *first,const char *second,char **result);
void compress(char** file, int fileDsc);
void byte_to_code(int fileDsc, int compressDesc);
void writeLode(struct Lode l, int fileDsc);
void ib_tree_depth(int fileDsc);
void ib_extension(char* extension, int fileDsc);
void ib_signature(int fileDsc);
void hauffman_write(int code, int length, int fileDsc);
#endif
