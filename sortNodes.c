#include "hauffman.h"

void swapNode(struct HauffmanNode *n1, struct HauffmanNode *n2)
{
    struct HauffmanNode t;

    t = *n1;
    *n1 = *n2;
    *n2 = t;
}


int partition(struct HauffmanNode** nodeArr, int low, int high)
{
    int pivot = (**(nodeArr+high)).occurences;
    int i = low-1;
    
    for(int l=low; l<high; l++)
    {
        if((**(nodeArr+l)).occurences>=pivot)
        {
            i++;
            swapNode(*(nodeArr+i), *(nodeArr+l));
        }
    }
    
    swapNode(*(nodeArr+i+1), *(nodeArr+high));

    return (i+1);
}


void nodeQuickSort(struct HauffmanNode **arr,int low, int high)
{
    int partitionReturn;
    if (low < high)
    {
        partitionReturn = partition(arr, 0, high);
        nodeQuickSort(arr, 0, partitionReturn-1);
        nodeQuickSort(arr, partitionReturn+1, high);
    }
}
