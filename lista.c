#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*
    1. Definir un tipo que permita crear una lista enlazada, donde cada nodo almacene los siguientes datos:
        #Nombre y Apellido
        #DNI
        #Dirección
        #Fecha de Nacimiento
*/
struct personaNodo
{
    char nom_ape[50];
    int dni;
    char direccion[120];
    char fnac[11];
    struct personaNodo *siguiente;
};
/*
    2. Realizar un programa que por medio de un menú de opciones y trabajando con una lista de 10 números reales permita:
        a- Cargar la lista
        b- Ordenar la lista
        c- Mostrar su contenido
        d- Salir
*/
struct nodoReal
{
    float numero;
    struct nodoReal *siguiente;
};
// 2.a- Cargar lista
void crearListaReales(struct nodoReal **pLista)
{
    struct nodoReal *pUltimo;
    for(int i = 0; i<10; i++)
    {
        struct nodoReal *nuevoNodo;
        nuevoNodo = (struct nodoReal *) malloc(sizeof(struct nodoReal));
        if(nuevoNodo == NULL)
        {
            printf("Sin memoria disponible\n");
            exit(0);
        }
        printf("Por favor ingrese un numero real (pos %d): \n",i);
        scanf("%f", &nuevoNodo->numero);
        nuevoNodo->siguiente=NULL;
        if(i==0)
        {
            *pLista = nuevoNodo;
            pUltimo = *pLista;
        }
        else
        {
            pUltimo->siguiente = nuevoNodo;
            pUltimo = nuevoNodo;
        }
    }

    return;
}
// 2.b Ordenar lista
void ordenarListaReales(struct nodoReal **pLista)
{
    struct nodoReal *pActual, *pSiguiente;
    int aux=0;
    pActual = *pLista;
    pSiguiente = pActual->siguiente;
    while(pActual->siguiente!=NULL)
    {
        while(pSiguiente!=NULL)
        {
            if(pActual->numero < pSiguiente->numero)
            {
                aux = pSiguiente->numero;
                pSiguiente->numero = pActual->numero;
                pActual->numero = aux;
            }
            pSiguiente = pSiguiente->siguiente;
        }
        pActual = pActual->siguiente;
        pSiguiente = pActual->siguiente;
    }
    return;
}
// 2.c Mostrar lista
void mostrarListaReales(struct nodoReal *pLista)
{
    struct nodoReal *pAux;
    pAux = pLista;
    int i = 0;
    while (pAux != NULL)
    {
        printf("Pos %d: %f", i, pAux->numero);
        i++;
        pAux = pAux->siguiente;
    }
    return;
}
/*  3. Se desea implementar una lista en memoria dinámica con la información sobre un grupo de pacientes:
                #Nro de Historia Clínica {La información estará ordenada por este ítem}
                #Apellido y Nombres
                # Diagnóstico
                #Fecha de última visita
                #Código de medicamento recetado
       Se pide definir los tipos necesarios y desarrollar las siguientes funciones:
            a. Visualizar por pantalla los datos de un determinado
                        Nro de Historia Clínica.
            b. Insertar un paciente con Nro de HC dado, manteniendo la lista ordenada.
            c. Actualizar la fecha de última visita de un determinado Nro de HC.
            d. Conociendo la dirección del nodo anterior: insertarDespuesDe(cabeza, referencia , nuevo)
                I. Insertar un nuevo paciente.
                II. Eliminar un determinado paciente.
            e. Conociendo la dirección del nodo posterior: insertarAntesDe(cabeza, referencia, nuevo)
                I. Insertar un nuevo paciente.
                II. Eliminar un determinado paciente.
            f. Destruir la lista de pacientes.  */
/* 3.1.- Definición de del tipo */
struct HistoriaClinica
{
    int numero;
    char nombre_y_apellido[50];
    char diagnostico[800];
    char ultima_visita[11];// DD-MM-AAAA
    char codigo_medicamento_recetado[50];
    struct HistoriaClinica *siguiente;
};
/*
    3.2.a- Buscar HC por numero y mostrar
*/
void mostrarHistoriaClinica(int id, struct HistoriaClinica *hcCabeza)
{
    struct HistoriaClinica *hcActual;
    hcActual = hcCabeza;
    while ((hcActual!=NULL)&&(hcActual->numero!=id)){
        hcActual = hcActual->siguiente;
    }
    if(hcActual == NULL){
        printf("No existe Historia Clínica correspondiente al Nro %d", id);
    }else{
        printf("HC Nro %d\n", hcActual->numero);
        printf("HC nombre y apellido %s\n", hcActual->nombre_y_apellido);
        printf("HC diagnostico %s\n", hcActual->diagnostico);
        printf("HC ultima visita %s\n", hcActual->ultima_visita);
        printf("HC codigo medicamento recetado %s\n\n", hcActual->codigo_medicamento_recetado);
    }
    return;
}
/*
    3.2.b.- Insertar HC ordenado
*/
void insertarHistoriaClinica(struct HistoriaClinica hc, struct HistoriaClinica **hcCabeza)
{
    struct HistoriaClinica *nuevaHC = (struct HistoriaClinica *) malloc(sizeof(struct HistoriaClinica));
    *nuevaHC = hc;
    nuevaHC->siguiente=NULL;
    struct HistoriaClinica *hcActual;
    hcActual = *hcCabeza;
    if(hcActual==NULL){
        *hcCabeza = nuevaHC;
    }else{
        // Si tengo que insertar antes de la cabeza
        if((hcActual->numero > nuevaHC->numero)){
            nuevaHC->siguiente = hcActual;
            *hcCabeza = nuevaHC;
        }else{
            while((hcActual->siguiente!=NULL)&&(nuevaHC->numero > hcActual->siguiente->numero)){
                hcActual = hcActual->siguiente;
            }
            if((hcActual->siguiente!=NULL)&&(nuevaHC->numero <= hcActual->siguiente->numero)){
                nuevaHC->siguiente = hcActual->siguiente;
                hcActual->siguiente = nuevaHC;
            }else{
                hcActual->siguiente = nuevaHC;
            }
        }
    }
    return;
}
// 3.2.c. Actualizar la fecha de última visita de un determinado Nro de HC.
void actualizarVisitaHistoriaClinica(int id, char ultima_visita[], struct HistoriaClinica **hcCabeza)
{
    struct HistoriaClinica *hcActual;
    hcActual = *hcCabeza;
    if(hcActual==NULL){
        printf("No hay historias clinicas cargadas");
    }else{
        while((hcActual!=NULL)&&(hcActual->numero!=id)){
            hcActual = hcActual->siguiente;
        }
        if(hcActual->numero==id){
            strcpy(hcActual->ultima_visita, ultima_visita);
            printf("Última visita de la historia clinica %d, actualizada: %s",id, hcActual->ultima_visita);
        }else{
            printf("No se encontró la historia clinica correspondiente relacionada con el numero: %d", id);
        }
    }
}
/*    3.2.d. Conociendo la dirección del nodo anterior: insertarDespuesDe(cabeza, referencia , nuevo)
                I. Insertar un nuevo paciente.
               II. Eliminar un determinado paciente.  */
void insertarDespuesDe(struct HistoriaClinica hcNuevo, struct HistoriaClinica *hcReferencia, struct HistoriaClinica **hcCabeza)
{
    struct HistoriaClinica *hcActual;
    hcActual = *hcCabeza;
    if(hcActual==NULL){
        printf("Lista vacía");
    }else{
        if(hcReferencia!=NULL)
            struct HistoriaClinica *hcNew = (struct HistoriaClinica *) malloc(sizeof(struct HistoriaClinica));
            *hcNew = hcNuevo;
            hcActual=hcReferencia;
            hcNew->siguiente = hcActual->siguiente;
            hcActual->siguiente = hcNew;
        }else{
            printf("La referencia no existe");
        }
    }
    return;
}
void eliminarElPosteriorDe(struct HistoriaClinica *hcReferencia, struct HistoriaClinica **hcCabeza)
{
    struct HistoriaClinica *hcActual;
    hcActual = *hcCabeza;
    if(hcActual==NULL){
        printf("Lista vacía");
    }else{
        if(hcReferencia!=NULL){
            hcActual= hcReferencia;
            struct HistoriaClinica *hcTarget;
            if(hcActual->siguiente!=NULL){
                hcTarget = hcActual->siguiente;
                hcActual->siguiente=hcActual->siguiente->siguiente;
                free(hcTarget);
            }else{
                printf("No hay elemento a eliminar posterior de la referencia");
            }
        }
    }
}
/*		3.2.e. Conociendo la dirección del nodo posterior: insertarAntesDe(cabeza, referencia, nuevo)
                I. Insertar un nuevo paciente.
                II. Eliminar un determinado paciente.   */
void insertarAntesDe(struct HistoriaClinica hcNuevo, struct HistoriaClinica *hcReferencia, struct HistoriaClinica **hcCabeza)
    struct HistoriaClinica *hcActual;
    hcActual = *hcCabeza;
    if(hcActual==NULL){
        printf("Lista vacía");
    }else{
        if(hcReferencia!=NULL){
            if(hcReferencia==*hcCabeza){
                struct HistoriaClinica *hcNew = (struct HistoriaClinica *) malloc(sizeof(struct HistoriaClinica));
                *hcNew = hcNuevo;
                hcNew->siguiente = hcReferencia;
                *hcCabeza = hcNew;
            }else{
                while((hcActual->siguiente!=hcReferencia)&&(hcActual->siguiente!=NULL)){
                    hcActual = hcActual->siguiente;
                }
                if(hcActual->siguiente==hcReferencia){
                    struct HistoriaClinica *hcNew = (struct HistoriaClinica *) malloc(sizeof(struct HistoriaClinica));
                    *hcNew = hcNuevo;
                    hcNew->siguiente = hcActual->siguiente;
                    hcActual->siguiente = hcNew;
                }else{
                    printf("La referencia no existe");
                }
            }
        }else{
            printf("La referencia no existe");
        }
    }
    return;
}
void eliminarElAnteriorDe(struct HistoriaClinica *hcReferencia, struct HistoriaClinica **hcCabeza)
{
    struct HistoriaClinica *hcActual;
    hcActual = *hcCabeza;
    if(hcActual==NULL){
        printf("Lista vacía");
    }else{
        if((hcReferencia!=NULL)||(hcReferencia!=hcActual)){
            if(hcActual->siguiente==hcReferencia){
                //ELIMINAR LA CABEZA
                struct HistoriaClinica *hcTarget;
                hcTarget = hcActual;
                *hcCabeza=hcActual->siguiente;
                free(hcTarget);
            }else{
                while((hcActual->siguiente->siguiente!=hcReferencia)&&(hcActual->siguiente->siguiente!=NULL)){
                    hcActual = hcActual->siguiente;
                }
                if(hcActual->siguiente->siguiente!=NULL){
                    struct HistoriaClinica *hcTarget;
                    hcTarget = hcActual->siguiente;
                    hcActual->siguiente=hcActual->siguiente->siguiente;
                    free(hcTarget);
                }else{
                    printf("No hay elemento a eliminar anterior de la referencia");
                }
            }
        }
    }
}
//    3.2.f. Destruir la lista de pacientes.	
void eliminarHistoriasClinicas(struct HistoriaClinica **hcCabeza)
{
    struct HistoriaClinica *hcActual;
    while(hcCabeza!=NULL){
        hcActual = *hcCabeza;
        *hcCabeza = hcActual->siguiente;
        free(hcActual);
    }
}
void mostrarHistoriasClinicas(struct HistoriaClinica *hcCabeza)
{
    struct HistoriaClinica *hcActual;
    hcActual = hcCabeza;
    if(hcActual==NULL){
        printf("No hay Historias Clínicas aún");
    }else{
        while(hcActual!=NULL){
            printf("HC Nro %d\n", hcActual->numero);
            printf("HC nombre y apellido %s\n", hcActual->nombre_y_apellido);
            printf("HC diagnostico %s\n", hcActual->diagnostico);
            printf("HC ultima visita %s\n", hcActual->ultima_visita);
            printf("HC codigo medicamento recetado %s\n\n", hcActual->codigo_medicamento_recetado);
            hcActual=hcActual->siguiente;
        }
    }
    return;
}
//    4. Realizar un programa que me permita cargar y mostrar una lista de 10 enteros utilizando punteros.
struct intNodo
{
    int numero;
    struct intNodo *siguiente;
};
struct intNodo * nuevoNodo(struct intNodo entero)
{
    struct intNodo *nEntero = (struct intNodo *) malloc(sizeof(struct intNodo));
    *nEntero = entero;
    nEntero->siguiente = NULL;
    return nEntero;
}
void agregarListaEntero(struct intNodo entero, struct intNodo **nCabeza)
{
    if(*nCabeza == NULL) {
        *nCabeza = nuevoNodo(entero);
    } else {
        struct intNodo* nAux;
        nAux = nuevoNodo(entero);
        nAux->siguiente = *nCabeza;
        *nCabeza = nAux;
    }
}
void mostrarListadoEnteros(struct intNodo *intCabeza)
{
    if(intCabeza==NULL){
        printf("No existen elementos en la lista");
    } else {
        while(intCabeza!=NULL){
            printf("%d\n", intCabeza->numero);
            intCabeza = intCabeza->siguiente;
        }
    }
    return;
}
//	5. Cargar el nombre y la fecha de nacimiento de 10 personas. Mostrar un listado de los que tienen 30 años.
struct tFecha{
    int dia, mes, anio;
};
struct fichaNodo{
    char nombre[50];
    struct tFecha nacimiento;
    struct fichaNodo *siguiente;
};
int calcEdad(struct tFecha nacimiento){
    struct tm t;
    time_t t_of_day;
    time_t now = time(NULL);
    t.tm_year = nacimiento.anio-1900;    //
    t.tm_mon = nacimiento.mes-1;         // 0 - ene [0-11]
    t.tm_mday = nacimiento.dia;          // [1-31]
    t.tm_hour = 0;
    t.tm_min = 0;
    t.tm_sec = 0;
    t.tm_isdst = -1;        // DST? 1 = si, 0 = no, -1 = desonocido
    t_of_day = mktime(&t);
    float a = (float)(now-t_of_day);
    return (int)(a/60/60/24/365);
}
void mostrarLosDeTreinta(struct fichaNodo *fCabeza){
    if(fCabeza==NULL){
        printf("No existen elementos en la lista");
    } else {
        while(fCabeza!=NULL){
            if(calcEdad(fCabeza->nacimiento)==30){
                printf("Nombre: %s\n", fCabeza->nombre);
                printf("Nacimiento: %d-%d-%d",fCabeza->nacimiento.dia, fCabeza->nacimiento.mes, fCabeza->nacimiento.anio);
            }
            fCabeza = fCabeza->siguiente;
        }
    }
    return;
}
/*	6. Cargar el nombre y sueldo de los 10 empleados de una fábrica manteniendo la lista ordenada. El nombre de la persona debe quedar guardado con la inicial en mayúsculas el resto de las letras en minúsculas. Mostrar los datos ordenados por sueldo. */
void strCapital(char palabra[]){
    int aux;
    for(int i=0; i < strlen(palabra); i++){
        aux = (int)palabra[i];
        if((aux>96)&&(aux<123)&&(i==0)){
            palabra[i]=aux-32;
        }
        if((i>0)&&(aux>64)&&(aux<91)){
            palabra[i]=aux+32;
        }
    }
    return;
}