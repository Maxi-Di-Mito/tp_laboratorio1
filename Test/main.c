#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../md_lib/lib.h"
#define MAX_INPUT 51
int main()
{
    char s1[10] = "perro";
    char s2[10] = "perros";

    int a = confirmacion("QUE ONDA?",'s','n');
    printf("%d",a);

}

