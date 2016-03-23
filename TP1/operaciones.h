#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void suma(float a, float b)
{
    return a+b;
}
void resta(float a, float b)
{
    float resultado = a-b;
    printf("Resultado RESTA: %.2f\n",resultado);
}
void division(float a, float b)
{
    float resultado = a/b;
    printf("Resultado DIVISION: %.2f\n",resultado);
}
void multiplicacion(float a, float b)
{
    float resultado =a*b;
    printf("Resultado MULTIPLICACION: %.2f\n",resultado);
}
void factorial(float a)
{
    int resultado = 1;
    int f = (int)a;
    for(;f> 1;f--)
        resultado *= f;

    printf("Resultado FACTORIAL: %.2f\n",resultado);
}


#endif // FUNCIONES_H_INCLUDED
