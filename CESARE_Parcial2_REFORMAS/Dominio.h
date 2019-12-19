
/*typedef struct{
    int id_cachorro;
    char nombre[20];
    int dias;
    char raza[20];
    char reservado[3];
    char genero;
}eCachorro;
*/
typedef struct {

    int id;
    char descripcion[150];
    float precio;
    int idTipo;
    char oferta[50];

}eComputer;



//eCachorro* newCachorro();
eComputer* newComputer();
///NEW PARAMETROS SON TODOS CHAR, DESPUES CASTEA CON ATOI A LOS CARACTERES
//eCachorro* newCachorro_Parametros(char* id,char* nombre,char* dias, char* raza , char* reservado,char* genero);
eComputer* newComputer_Parametros(char* id, char* descripcion, char* precio, char* idTipo, char* oferta);

///EL SET MODIFICA EL ELEMENTO, EL GET OBTIENE Y CARGA

///void showCachorro(eCachorro* cachorro);
void showComputer(eComputer* compu);
///void showCachorros(LinkedList* pArrayLinkedCachorro);
void showComputers(LinkedList*pArrayLinkedComputers);

///int eCachorro_setId(eCachorro* listaCachorro,int id);///GET ID INT ENTEROS
///int eCachorro_getId(eCachorro* listaCachorro,int* id);///SET ID INT ENTEROS
int eComputer_setId(eComputer* listaComputer,int id);
int eComputer_getId(eComputer* listaComputer,int* id);///el get lleva * el SET no

///int eCachorro_setNombre(eCachorro* listaCachorro, char* nombre);///SET NOMBRE CADENA DE CARACTERES
///int eCachorro_getNombre(eCachorro* listaCachorro,char* nombre);///GET NOMBRE CADENA DE CARACTERES
int eComputer_setDescripcion(eComputer* listaComputer, char* descripcion);
int eComputer_getDescripcion(eComputer* listaComputer,char* descripcion);

///int eCachorro_getDias(eCachorro* listaCachorro,int* dias);///GET DIAS FLOAT
///int eCachorro_setDias(eCachorro* listaCachorro,int dias);///SET DIAS FLOAT
int eComputer_getPrecio(eComputer* listaComputer,float* precio);///el get lleva * el SET no
int eComputer_setPrecio(eComputer* listaComputer,float precio);

///int eCachorro_setRaza(eCachorro* listaCachorro, char* raza);///SET RAZA CADENA DE CARACTERES
///int eCachorro_getRaza(eCachorro* listaCachorro,char* raza); ///GET RAZA CADENA DE CARACTERES
int eComputer_setIdTipo(eComputer* listaComputer,int idTipo);
int eComputer_getIdTipo(eComputer* listaComputer,int* idTipo);


///int eCachorro_setGenero(eCachorro* listaCachorro,char* genero);///set genero UN CARACTER
///int eCachorro_getGenero(eCachorro* listaCachorro,char* genero); ///Get genero UN CARACTER

///int eCachorro_setReservado(eCachorro* listaCachorro,char* reservado);///reservado
///int eCachorro_getReservado(eCachorro* listaCachorro,char* reservado);
int eComputer_setOferta(eComputer* listaComputer,char* oferta);///reservado
int eComputer_getOferta(eComputer* listaComputer,char* oferta);

int cargarDescripcion(void* lista, char* desc);

int sortComputers (void* desktop, void* laptop);

int filter_desktop(void* aux);

int setearOferta(void* element);



///FILTER DE CACHORROS
/*int filter_45dias(void* aux);
int filter_machos(void* aux);
int filter_callejeros(void* aux) ;
int filter_reservado(void* aux); ///la funcion que despues es pasada como pFUNC a ll_filter con filtro de CARACTERES


///FILTER DE DOMINIOS

int setearTipo(eCachorro* cacho);///aca setear 45 dias??? y setear machos, y listado callejeros
void* seteaTipo(eCachorro* e);

int filterTipo(void* e);
*/
