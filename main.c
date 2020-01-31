#include "hauffman.h"


int main(int args, char** argv)
{
    int fileDsc = open(argv[1], O_RDWR, 0644);
    char** file;
    
    if(fileDsc<1){
        printf("Couldnt read nor create file %s\n", argv[1]);
        return 0;
    }
    
    file = get_file_nm_ext(argv[1]);
//    printf("%s\n%s\n", *(t+0), *(t+1));
    compress(file, fileDsc);
    close(fileDsc);
    
    return EXIT_SUCCESS;
}
