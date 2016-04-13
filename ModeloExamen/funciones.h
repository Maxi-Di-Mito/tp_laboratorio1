typedef struct Empleado
{
    int legajo;
    char nombre[26];
    char apellido[26];
    int salario;
    short int sector;
    long fechaIngreso;
    short int estado;
}Empleado;


void printMenu();

Empleado *buscarLugar(Empleado nomina[], int largo);

int buscarProxLegajo(Empleado nomina[], int largo);

void altas(Empleado nomina[], int largo);


