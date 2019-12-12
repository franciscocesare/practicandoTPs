#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[51];
}eCategoria;

#endif // CATEGORIA_H_INCLUDED

/** \brief lista de categorias precargadas para testeo
 *
 * \param estructura categorias
 * \param tamanio de la estructura
 * \param cantidad de lineas de datos que se desea cargar
 * \return sin retorno
 *
 */
void harcodearCategoria(eCategoria vec[], int tam);


/** \brief muestra un solo dato de la estuctura categorias
 *
 * \param estructura categorias
 * \return sin retorno
 *
 */
void mostrarCategoria(eCategoria vec);


/** \brief muestra todos los datos de la estuctura categorias
 *
 * \param estructura categorias
 * \param tamanio estructura categorias
 * \return sin retorno
 *
 */
void mostrarCategorias(eCategoria vec[], int tam);


/** \brief obtiene nombre de una categoria a traves del id
 *
 * \param estructura categorias
 * \param tamanio estructura categorias
 * \param id de la categoria a buscar
 * \param donde asignar nombre obtenido
 * \return sin retorno
 *
 */
void obtenerNomCat(eCategoria vec[], int tam, int id, char dondeAsignar[]);

