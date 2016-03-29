/** \brief Suma 2 numeros
 *
 * \param a: primer operando
 * \param b: segundo operando
 * \return
 *
 */
float sumar(float a, float b)
{
    return a+b;
}
/** \brief Resta 2 numeros
 *
 * \param a: primer operando
 * \param b: segundo operando
 * \return
 *
 */

float restar(float a, float b)
{
    float resultado = a-b;
    return resultado;
}
float dividir(float a, float b)
{
    return a/b;
}
/** \brief Valida que sea posible dividir y divide
 *
 * \param a: primer operando
 * \param b: segundo operando
 * \return 1 para caso exitoso, 0 para cuando no es posible dividir
 *
 */

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

/** \brief Multiplica 2 numeros
 *
 * \param a: primer operando
 * \param b: segundo operando
 * \return a*b
 *
 */

float multiplicar(float a, float b)
{
    float resultado =a*b;
    return resultado;
}

/** \brief Calcula el factorial de un numero
 *
 * \param operando
 * \return
 *
 */

float calcularFactorial(float a)
{
    long f = (long) a;
    if(f == 0)
        return 1;
    else
        return f*calcularFactorial(f-1);
}
