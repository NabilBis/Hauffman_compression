#include "hauffman.h"


int length = -1;
int compress_file;
unsigned short code = 0;


int* countOccurence(int fileDescriptor)
{
    int *ascii = malloc(256*sizeof(int));
    unsigned char *buffer = malloc(sizeof(char));
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

void preOrderCode(struct HauffmanNode *head, int direc, int compress_file)
{
    
    struct Lode lode;
    
          lode.isLeaf = 0;
          lode.cle = head->key;
          lode.oc = head->occurences;
    
    treeDepth++;
    length++;

    if(direc){
        code <<= 1;
        code |= 1;
    } else {
        code <<= 1;
    }

    if(head->left == NULL && head->right == NULL)
    {
//        printf(" (%c, %d )\n", head->key, head->occurences);
        lode.isLeaf = 1;
        (*(arr_code+(head->key))).code = code;
        (*(arr_code+(head->key))).length = length;
        code >>= 1;
//        printf(" (%d, %d )\n", code, length);
        length--;
        writeLode(lode, compress_file);
        return;
    }
    
    writeLode(lode, compress_file);
    preOrderCode(head->left, 0, compress_file);
    preOrderCode(head->right, 1, compress_file);
    length--;
    code >>= 1;
}


void compress(char** file, int fileDsc)
{
    char i = 'o';
    int *ascii;
    struct HauffmanNode **nodeTab;
    int f = 0;
    
    char *compress_name;
    
    arr_code = malloc(256*sizeof(struct CODE));
    
    ascii = countOccurence(fileDsc);
    nodeTab = nodesArray(ascii);
    
    while(*(nodeTab+f) != NULL)  f++;
    
    nodeQuickSort(nodeTab, 0, f-1);
    buildTree(nodeTab, 0, f-1);
    
    /////////////////////////////////////////////
    
    concactStr(*(file+0), "_comp.ib", &compress_name);
    compress_file = open(compress_name, O_CREAT | O_RDWR, 0644);
    
    ib_signature(compress_file);
    ib_extension(*(file+1), compress_file);
    
    lseek(compress_file, 3 + extensionSize + 2, SEEK_SET);
    preOrderCode(*(nodeTab+0), 0, compress_file);
    
    
    ib_tree_depth(compress_file);
    
    ///////////  write bytes
    printf("Tree length = %d\n", treeDepth);
    
    byte_to_code(fileDsc, compress_file);
    printf("Okey dokey\n");
    close(compress_file);
}






