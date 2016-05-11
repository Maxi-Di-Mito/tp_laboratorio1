#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "../md_lib/lib.h"


int main()
{
    char texto[50];
    pedirString(texto,"Mete algo\n",0,1,"ERROR\n");

    return 0;
}
