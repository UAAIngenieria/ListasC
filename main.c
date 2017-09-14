#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include "lista.h"

int main()
{
    /*struct nodoReal *pLista;
    pLista = (struct nodoReal *) NULL;
    crearListaReales(&pLista);
    ordenarListaReales(&pLista);
    mostrarListaReales(pLista);*/
    
	/*Ejercicio 3*/
        struct HistoriaClinica *hcCabeza;
        hcCabeza = (struct HistoriaClinica *) NULL;

        struct HistoriaClinica hc;

        hc.numero=3;
        strcpy(hc.nombre_y_apellido, "Mariana Peppe");
        strcpy(hc.diagnostico, "Bronquiespasmo");
        strcpy(hc.codigo_medicamento_recetado, "02278");
        strcpy(hc.ultima_visita, "20/05/2017");
        insertarHistoriaClinica(hc, &hcCabeza);
        //mostrarHistoriaClinica(1, hcCabeza);

        hc.numero=2;
        strcpy(hc.nombre_y_apellido, "Romeo Fernandez");
        strcpy(hc.diagnostico, "Colesterol Alto");
        strcpy(hc.codigo_medicamento_recetado, "00055");
        strcpy(hc.ultima_visita, "11/11/2011");
        insertarHistoriaClinica(hc, &hcCabeza);
        //mostrarHistoriaClinica(1, hcCabeza);

        hc.numero=1;
        strcpy(hc.nombre_y_apellido, "Alberto Rosamonte");
        strcpy(hc.diagnostico, "Taquicardia");
        strcpy(hc.codigo_medicamento_recetado, "00454");
        strcpy(hc.ultima_visita, "09/12/2016");
        insertarHistoriaClinica(hc, &hcCabeza);
        //mostrarHistoriaClinica(1, hcCabeza);
        //actualizarVisitaHistoriaClinica(1, "11/11/2011", &hcCabeza);
        //mostrarHistoriaClinica(1, hcCabeza);

        hc.numero=50;
        strcpy(hc.nombre_y_apellido, "Jose Altamirano");
        strcpy(hc.diagnostico, "Gastroenteritis");
        strcpy(hc.codigo_medicamento_recetado, "00454");
        strcpy(hc.ultima_visita, "09/12/2016");

        insertarDespuesDe(hc, hcCabeza, &hcCabeza);

        mostrarHistoriasClinicas(hcCabeza);
        eliminarElAnteriorDe(hcCabeza, &hcCabeza);
        mostrarHistoriasClinicas(hcCabeza);
    
    /*insertarAntesDe(struct HistoriaClinica hcNuevo, struct HistoriaClinica *hcReferencia, struct HistoriaClinica **hcCabeza);
    eliminarElAnteriorDe(struct HistoriaClinica *hcReferencia, struct HistoriaClinica **hcCabeza);
    eliminarHistoriasClinicas(struct HistoriaClinica **hcCabeza);*/

	/* Ejercicio 4 */
	/*struct intNodo *intCabeza;
    intCabeza = NULL;
    struct intNodo entero;
    entero.numero = 3;
    agregarListaEntero(entero, &intCabeza);
    entero.numero = 5;
    agregarListaEntero(entero, &intCabeza);
    mostrarListadoEnteros(intCabeza);*/
	
	/* Ejercicio 5 */
    /*fprintf(stdout, "%lu\n", (unsigned long)time(NULL));
    fprintf(stdout, "%lu\n", ((unsigned long)time(NULL))/60/60/24/365);*/
    
	/* Ejercicio 6 */
	//printf("%d - %d\n", 'A', 'a');
    //printf("%d - %d", 'Z', 'z');
	char palabra[] ="ROBERT";
    strCapital(palabra);
    printf("%s", palabra);
    return 0;
}
