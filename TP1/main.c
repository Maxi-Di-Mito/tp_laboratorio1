#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#define OPER1 1
#define OPER2 2
#define SUMA 3
#define RESTA 4
#define DIVISION 5
#define MULTIPLICACION 6
#define FACTORIAL 7
#define TODAS 8
#define SALIR 9

void imprimirMenu();
float pedirNumero();

float x = 0;
float y = 0;

int main()
{
    char opcion = 0;
    float resultado;
    while(opcion != 9)
    {
        imprimirMenu();
        scanf("%d",&opcion);
        system("cls");
        switch(opcion)
        {
            case OPER1:
                printf("Ingrese primer operando : ");
                x = pedirNumero();
                break;
            case OPER2:
                printf("Ingrese segundo operando : ");
                y = pedirNumero();
                break;
            case SUMA:
                resultado = suma(x,y);
                printf("Resultado SUMA: %.2f\n",resultado);
                break;
            case RESTA:
                resultado = resta(x,y);
                printf("Resultado RESTA: %.2f\n",resultado);
                break;
            case DIVISION:
                resultado = division(x,y);
                printf("Resultado DIVISION: %.2f\n",resultado);
                break;
            case MULTIPLICACION:
                resultado = multiplicacion(x,y);
                printf("Resultado MULTIPLICACION: %.2f\n",resultado);
                break;
            case FACTORIAL:
                resultado = factorial(x);
                printf("Resultado FACTORIAL: %.2f\n",resultado);
                break;
            case TODAS:
                resultado = suma(x,y);
                printf("Resultado SUMA: %.2f\n",resultado);
                resultado = resta(x,y);
                printf("Resultado RESTA: %.2f\n",resultado);
                resultado = division(x,y);
                printf("Resultado DIVISION: %.2f\n",resultado);
                resultado = multiplicacion(x,y);
                printf("Resultado MULTIPLICACION: %.2f\n",resultado);
                resultado = factorial(x);
                printf("Resultado FACTORIAL: %.2f\n",resultado);
                break;
        }
    }
    return 0;
}

//FUNCIONES AUXILIARES
void imprimirMenu()
{
    printf("1-Ingresar 1er operando(A=%.2f)\n",x);
    printf("2-Ingresar 2do operando(B=%.2f)\n",y);
    printf("3-Calcular la suma \n");
    printf("4-Calcular la resta\n");
    printf("5-Calcular la division\n");
    printf("6-Calcular la multiplicacion\n");
    printf("7-Calcular el factorial\n");
    printf("8-Calcular todas las operaciones\n");
    printf("9-Salir\n");
}

float pedirNumero()
{
    float numero;
    scanf("%f",&numero);
    return numero;
}


