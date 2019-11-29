#include "hauffman.h"


int main(int args, char** argv)
{
    char* phrase = "Angel giwgiwwwww HadidiH always and foreverzz";
    char* hadid = "Nabiliwww";
    int *ascii = countOccurence(phrase);
    struct HauffmanNode **nodeTab = nodesArray(ascii);
    int f=0;
    
    do {
        printNode(**(nodeTab+f));
        f++;
        
    } while (*(nodeTab+f)!= NULL);
    
    printf("\n\n------SORT-------\n\n\n");
    
    nodeQuickSort(nodeTab, 0, f-1);
    f=0;
    
    while(*(nodeTab+f)!= NULL)
    {
        printNode(**(nodeTab+f));
        f++;
    }
    
    printf("\n\n\n");
    return EXIT_SUCCESS;
}
