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

Empleado *buscarLegajo(Empleado nomina[],int largo,int legajo);

void altas(Empleado nomina[], int largo);

void modificar(Empleado nomina[], int largo);

void baja(Empleado nomina[], int largo);

