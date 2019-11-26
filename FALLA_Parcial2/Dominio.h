
typedef struct{
    int id_cachorro;
    char nombre[20];
    int dias;
    char raza[20];
    char reservado[3];
    char genero;
}eCachorro;

eCachorro* newCachorro();
eCachorro* newCachorro_Parametros(char* id,char* nombre,char* dias, char* raza , char* reservado,char* genero);

///EL SET MODIFICA EL ELEMENTO, EL GET OBTIENE Y CARGA

void showCachorro(eCachorro* cachorro);///
void showCachorros(LinkedList* pArrayLinkedCachorro);///

int eCachorro_setId(eCachorro* listaCachorro,int id);
int eCachorro_getId(eCachorro* listaCachorro,int* id);

int eCachorro_setNombre(eCachorro* listaCachorro, char* nombre);
int eCachorro_getNombre(eCachorro* listaCachorro,char* nombre);

int eCachorro_getDias(eCachorro* listaCachorro,int* dias);
int eCachorro_setDias(eCachorro* listaCachorro,int dias);

int eCachorro_setRaza(eCachorro* listaCachorro, char* raza);
int eCachorro_getRaza(eCachorro* listaCachorro,char* raza);

int eCachorro_setGenero(eCachorro* listaCachorro,char* genero);///genero
int eCachorro_getGenero(eCachorro* listaCachorro,char* genero);

int eCachorro_setReservado(eCachorro* listaCachorro,char* reservado);///reservado
int eCachorro_getReservado(eCachorro* listaCachorro,char* reservado);

int setearTipo(eCachorro* cacho);///aca setear 45 dias??? y setear machos, y listado callejeros
void* seteaTipo(eCachorro* e);

int filterTipo(void* e);
