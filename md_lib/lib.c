#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int confirmacion(char* mensaje, char op1, char op2,int cantidadIntentos)
{
    char c;
    do
    {
        printf("%s\n",mensaje);
        fflush(stdin);
        scanf("%c",&c);
        cantidadIntentos--;
    }while((tolower(c) != tolower(op1) && tolower(c)!= tolower(op2)) || cantidadIntentos != 0);
    return c == op1;
}

int confirmacionSinReintentos(char* mensaje, char op1, char op2)
{
    confirmacion(mensaje,op1,op2,0);
}
