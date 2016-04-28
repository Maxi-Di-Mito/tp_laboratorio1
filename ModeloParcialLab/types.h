
typedef struct
{
    int codigoProducto;
    int codigoProveedor;
    char descripcion[51];
    float importe;
    int cantidad;
    int enUso;
} Producto;

typedef struct
{
    int codigoproveedor;
    char descripcion[51];
    int enUso;
} Proveedor;
