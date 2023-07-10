#include "malloc.h"

void    BestFit(int BlockSize[], int block, int ProcessSize[], int processes)
{
    int     allocation[processes];
    int     occupied[block];

    int     i = 0;

    while (i < processes)
    {
        allocation[i] = -1;
        i++;
    }

    i = 0;
    while (i < block)
    {
        occupied[i] = 0;
        i++;
    }
    i = 0;

    while (i < processes)
    {
        int indexPlaced = -1;
        int j = 0;
        while (j < block)
        {
            if (BlockSize[j] >= ProcessSize[i] && !occupied[j])
            {
                indexPlaced = j;
            }
            else if (BlockSize[j] < BlockSize[indexPlaced]) {
                indexPlaced = j;
            }
            j++;
        }
        if (indexPlaced != -1)
        {
            allocation[i] = indexPlaced;
            occupied[indexPlaced] = 1;
        }
    i++;
    }
}
