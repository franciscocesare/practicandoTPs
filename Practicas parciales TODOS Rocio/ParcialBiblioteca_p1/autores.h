#ifndef AUTORES_H_INCLUDED
#define AUTORES_H_INCLUDED

typedef struct
{
    int id;
    char apellido[31];
    char nombre[31];

} eAutores;

#endif // AUTORES_H_INCLUDED

int hardCodeAutores(eAutores lista[],int tam, int cant);
int buscarAutorId(eAutores vec[], int tam, int id);
void mostrarAutor(eAutores vec);
void mostrarAutores(eAutores vec[], int tam);
void ordenarActores(eAutores vec[], int tam);
void obtenerNomAutor(eAutores vec[], int tam, int idAutor,char dondeAsigar[]);

