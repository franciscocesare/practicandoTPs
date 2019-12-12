
int menuInformes();

void mostrarAutosPorColor(eAuto lista[], int tam, eColor color[], int tamColor, eMarca marca[], int tamMarca);

void mostrarAutosPorMarca(eAuto lista[], int tam, eColor color[], int tamColor, eMarca marca[], int tamMarca);

void trabajosUnAuto(eAuto listA[], int tamA, eServicio listaS[], int tamS, eTrabajo listT[], int tamT, eColor listC[], int tamC, eMarca listM[], int tamM);

int listarAutosSinTrabajos(eAuto autos[], int tam, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eTrabajo trabajos[], int tamTrabajos);

void importePorAuto(eAuto listA[], int tamA, eServicio listaS[], int tamS, eTrabajo listT[], int tamT, eColor listC[], int tamC, eMarca listM[], int tamM);

void servicioMasPedido(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eAuto listaA[], int tamA);

void totalPorFecha(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS);

void mostrarAutosPorTrabajo(eAuto listaA[], int tamA, eTrabajo listaT[], int tamT, eServicio listaS[], int tamS);

void trabajosPorColor(eServicio listaS[], int tamS, eTrabajo listT[], int tamT, eColor listC[], int tamC, eAuto listaA[], int tamA);

void totalPorServicio(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS);

void autosConTrabajoXFecha(eAuto listaA[], int tamA, eTrabajo listaT[], int tamT, eColor listaC[], int tamC, eMarca listaM[], int tamM);
