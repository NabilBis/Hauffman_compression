#include "hauffman.h"

void ib_signature(int fileDsc)
{
    char i = 'i';
    char b = 'b';
    
    lseek(fileDsc, 0, SEEK_SET);
    write(fileDsc, &i, 1);
    write(fileDsc, &b, 1);
}

void ib_extension(char* extension, int fileDsc)
{
    lseek(fileDsc, 4, SEEK_SET);
    
    for( extensionSize=0; *(extension + extensionSize) != '\0'; extensionSize++)
    {
        write(fileDsc, extension + extensionSize, 1);
    }
    ///////// size = (char *)&extensionSize;
    lseek(fileDsc, 3, SEEK_SET);
    write(fileDsc, (char *)&extensionSize, 1);
}

void ib_tree_depth(int fileDsc)
{
    lseek(fileDsc, 3 + extensionSize + 1, SEEK_SET);
    write(fileDsc, (char *)&treeDepth, 1);
}

void writeLode(struct Lode l, int fileDsc)
{
    write(fileDsc, &l.isLeaf, 1);
    write(fileDsc, &l.cle, 1);
    write(fileDsc, &l.oc, 4);
}



void byte_to_code(int fileDsc, int compressDesc)
{
    //    int size = 0;
    unsigned char buffer;
    
    lseek(compressDesc, 0, SEEK_END);
    lseek(fileDsc, 0, SEEK_SET);
    
    while(read(fileDsc, &buffer, 1)){
        hauffman_write((*(arr_code + buffer)).code,
                       (*(arr_code + buffer)).length,
                       compressDesc);
        //        size++;
    }
    //    printf("Size : %d \n", size);
}
