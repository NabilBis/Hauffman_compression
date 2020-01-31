#include "hauffman.h"

char hauffman_byte = 0;

void hauffman_write(int code, int length, int fileDsc){
    
    static int compteur = 0;
    char ele = 1;
    
    for(int l=0; l<length; l++)
    {
        hauffman_byte <<=1;
        ele &= *((char *)&code);
        hauffman_byte |= ele;
        code >>= 1;
        ele = 1;
        compteur++;
        
        if(compteur==8)
        {
            write(fileDsc, &hauffman_byte, 1);
            compteur = 0;
            hauffman_byte = 0;
        }
    }
}

//void byte_to_code(int fileDsc, int compressDesc)
//{
//    char buffer;
//    
//    while(read(fileDsc, &buffer, 1)){
//        hauffman_write(code, length, compressDesc);
//        printf("%d \n", buffer);
//    }
//}
