#include "hauffman.h"


int main(int args, char** argv)
{
    int fileDsc = open(argv[1], O_RDWR, 0644);

    if(fileDsc<1){
        printf("Couldnt read nor create file %s\n", argv[1]);
        return 0;
    }
    
    compress(fileDsc);
    close(fileDsc);
    
    return EXIT_SUCCESS;
}
