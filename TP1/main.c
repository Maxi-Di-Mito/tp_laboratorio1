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
#define MENSAJE_DIVISION_CERO printf("Resultado DIVISION: No se puede dividir por cero\n")

void imprimirMenu(float x, float y);
float pedirNumero();


int main()
{
    float x = 0;
    float y = 0;
    float resultado;
    int opcion = 0;
    while(opcion != 9)
    {
        imprimirMenu(x,y);
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
                resultado = sumar(x,y);
                printf("Resultado SUMA: %.2f\n",resultado);
                break;
            case RESTA:
                resultado = restar(x,y);
                printf("Resultado RESTA: %.2f\n",resultado);
                break;
            case DIVISION:
                if(validarYDividir(x,y,&resultado))
                    printf("Resultado DIVISION: %.2f\n",resultado);
                else
                    MENSAJE_DIVISION_CERO;
                break;
            case MULTIPLICACION:
                resultado = multiplicar(x,y);
                printf("Resultado MULTIPLICACION: %.2f\n",resultado);
                break;
            case FACTORIAL:
                resultado = calcularFactorial(x);
                printf("Resultado FACTORIAL: %d\n",(int)resultado);
                break;
            case TODAS:
                resultado = sumar(x,y);
                printf("Resultado SUMA: %.2f\n",resultado);
                resultado = restar(x,y);
                printf("Resultado RESTA: %.2f\n",resultado);
                if(validarYDividir(x,y,&resultado))
                    printf("Resultado DIVISION: %.2f\n",resultado);
                else
                    printf("Resultado DIVISION: No se puede dividir por cero\n");
                resultado = multiplicar(x,y);
                printf("Resultado MULTIPLICACION: %.2f\n",resultado);
                resultado = calcularFactorial(x);
                printf("Resultado FACTORIAL: %d\n",(int)resultado);
                break;
        }
    }
    return 0;
}

//FUNCIONES AUXILIARES
void imprimirMenu(float x, float y)
{
    printf("1-Ingresar 1er operando(A=%.2f)\n",x);
    printf("2-Ingresar 2do operando(B=%.2f)\n",y);
    printf("3-Calcular la suma \n");
    printf("4-Calcular la resta\n");
    printf("5-Calcular la division\n");
    printf("6-Calcular la multiplicacion\n");
    printf("7-Calcular el factorial(A!)\n");
    printf("8-Calcular todas las operaciones\n");
    printf("9-Salir\n");
}

float pedirNumero()
{
    float numero;
    scanf("%f",&numero);
    return numero;
}


