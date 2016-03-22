#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

float suma(float a, float b)
{
    return a+b;
}
float resta(float a, float b)
{
    return a-b;
}
float division(float a, float b)
{
    return a/b;
}
float multiplicacion(float a, float b)
{
    return a*b;
}
float factorial(float a)
{
    int f = (int)a;
    if(f == 1 || f == 0)
        return 1;
    else
        return f*factorial(f-1);
}


#endif // FUNCIONES_H_INCLUDED
