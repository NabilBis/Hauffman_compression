#include "hauffman.h"


char** get_file_nm_ext(char* fileName)
{
    int strSize, extension, i;
    char* file_nam;
    char* file_ext;
    char** str_arr = malloc(2*sizeof(char*));
    
    strSize = extension = i =0;
    // i used both strSize and i so i can later be able to identify the lenght of string + extension
    while (*(fileName+i) != '\0') {
        if(*(fileName+i)=='.' && strSize == i){
            extension=1;
        }
        if(!extension){
            strSize++;
        }
        i++;
    }
    
    file_nam = (char*) malloc((strSize+1)*sizeof(char));
    file_ext = (char*) malloc((i-strSize-1)*sizeof(char));
    
    ////// fill file's name
    for(int u=0;u<strSize;u++)
    {
        *(file_nam + u)= *(fileName+u);
    }
   
    /////// fill file's extension
    for(int b=strSize+1; b<i; b++)
    {
        *(file_ext + b-strSize-1)= *(fileName+b);
    }
    
    *(file_nam + strSize) = '\0';
    *(file_ext + i-strSize) = '\0';
    
    
    *(str_arr+0) = file_nam;
    *(str_arr+1) = file_ext;
    
    return str_arr;
}

//int main(int args, char** argv)
//{
//    char** t = substractExtension("bli bli bli.pdf");
//    printf("%s\n%s\n", *(t+0), *(t+1));
//    return EXIT_SUCCESS;
//}

void concactStr(char *first,const char *second,char **result)
{
    char *new=NULL;
    int fl,sL;
    int length;
    
    fl=sL=0;
    while(*(first+fl)!='\0'){
        fl++;
    }
   	while(*(second+sL)!='\0'){
        sL++;
    }
    
    length= sL+fl;
    new = malloc((32)*sizeof(char));
    
    for(int i=0;i<(length);i++){
        if(i<fl){
            *(new+i) = *(first+i);
        }else {
            *(new+i) = *(second+(i+sL-length));
        }	
    }
    
    *(new+length)='\0';
    *result = new;
    
}
