/* Ejercicio 2 */
struct nodoReal{
    float numero;
    struct nodoReal *siguiente;
};
void crearListaReales(struct nodoReal**pLista);
void ordenarListaReales(struct nodoReal **pLista);
void mostrarListaReales(struct nodoReal*pLista);
/* Ejercicio 3 */
struct HistoriaClinica{
    int numero;
    char nombre_y_apellido[50];
    char diagnostico[800];
    char ultima_visita[11];// DD-MM-AAAA
    char codigo_medicamento_recetado[50];
    struct HistoriaClinica *siguiente;
};
void mostrarHistoriaClinica(int id, struct HistoriaClinica *hcCabeza);
void insertarHistoriaClinica(struct HistoriaClinica hc, struct HistoriaClinica **hcCabeza);
void actualizarVisitaHistoriaClinica(int id, char ultima_visita[], struct HistoriaClinica **hcCabeza);
void insertarDespuesDe(struct HistoriaClinica hcNuevo, struct HistoriaClinica *hcReferencia, struct HistoriaClinica **hcCabeza);
void eliminarElPosteriorDe(struct HistoriaClinica *hcReferencia, struct HistoriaClinica **hcCabeza);
void insertarAntesDe(struct HistoriaClinica hcNuevo, struct HistoriaClinica *hcReferencia, struct HistoriaClinica **hcCabeza);
void eliminarElAnteriorDe(struct HistoriaClinica *hcReferencia, struct HistoriaClinica **hcCabeza);
void eliminarHistoriasClinicas(struct HistoriaClinica **hcCabeza);
void mostrarHistoriasClinicas(struct HistoriaClinica *hcCabeza);
/* Ejercicio 4*/
struct intNodo{
    int numero;
    struct intNodo *siguiente;
};
struct intNodo * nuevoNodo(struct intNodo entero);
void agregarListaEntero(struct intNodo entero, struct intNodo **nCabeza);
void mostrarListadoEnteros(struct intNodo *intCabeza);
//5. Cargar el nombre y la fecha de nacimiento de 10 personas. Mostrar un listado de los que tienen 30 años.
struct tFecha{
    int dia, mes, anio;
};
struct fichaNodo{
    char nombre[50];
    struct tFecha nacimiento;
    struct fichaNodo *siguiente;
};
int calcEdad(struct tFecha nacimiento);
void mostrarLosDeTreinta(struct fichaNodo *fCabeza);
//6. Letra capital
void strCapital(char palabra[]);
