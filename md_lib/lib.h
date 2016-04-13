#ifndef MD_LIB_INCLUDED
#define MD_LIB_INCLUDED

int confirmacion(char* mensaje, char op1, char op2,int cantidadIntentos);

int confirmacionSinReintentos(char* mensaje, char op1, char op2);

void swap(void *vp1,void *vp2,int size);

int pedirInt(int *dato,char* msg, int max, int min, char* errorMsg);

int pedirLong(long *dato,char* msg, int max, int min, char* errorMsg);

int pedirString(char* dato,char* msg, int max, int min, char*errorMsg);

#endif // MD_LIB_INCLUDED
