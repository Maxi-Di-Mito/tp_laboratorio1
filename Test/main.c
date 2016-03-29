#include <stdio.h>
#include <stdlib.h>
#include "../md_lib/md_lib/lib.h"

int main()
{
    int arr[10];
    cleanArray(&arr,10);
    int i;
    for(i=0;i<10;i++)
        printf("%d\n",arr[i]);


    return 0;
}
