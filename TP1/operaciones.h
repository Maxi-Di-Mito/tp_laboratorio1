#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

float sumar(float a, float b)
{
    return a+b;
}
float restar(float a, float b)
{
    float resultado = a-b;
    return resultado;
}
float dividir(float a, float b)
{
    return a/b;
}

float validarYDividir(float a, float b, float *resultado)
{
    if(b == 0)
    {
        return 0;
    }else
    {
        *resultado = dividir(a,b);
        return 1;
    }
}

float multiplicar(float a, float b)
{
    float resultado =a*b;
    return resultado;
}
float calcularFactorial(float a)
{
    long f = (long) a;
    if(f == 0)
        return 1;
    else
        return f*calcularFactorial(f-1);
}


#endif // FUNCIONES_H_INCLUDED
