#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int confirmacion(char* mensaje, char op1, char op2)
{
    char c;
    do
    {
        printf("%s\n",mensaje);
        fflush(stdin);
        scanf("%c",&c);
    }while(tolower(c) != tolower(op1) && tolower(c)!= tolower(op2));
    return c == op1;
}
