/********************/
/*    PRÁCTICA 3    */
/*   NÉSTOR PÉREZ   */
/*   RAÚL  SANCHO   */
/********************/

#include "impresionListasContiguas.h"
#include "ListaContigua.h"
#include "Orden.h"
#include <time.h>

int main(int argc, char* argv[]) {
	ListaContigua listaPorInsercion;
	Orden sorter;
	int size;

	std::cout << "Tamano de la lista: ";
	std::cin >> size;

	for (unsigned i = 0; i < size; ++i)
		listaPorInsercion.insertarAlFinal(i);

	ListaContigua listaPorSeleccion(listaPorInsercion);
	ListaContigua listaPorBubble(listaPorInsercion);
	ListaContigua listaPorMerge(listaPorInsercion);
	ListaContigua listaPorQuick(listaPorInsercion);
	ListaContigua listaPorRange(listaPorInsercion);


	int numeroClicksInicio, numeroClicksFin;
	float segundosTranscurridos;

	try {

		  ////////////////////
		 // INSERTION SORT //	
		////////////////////

		// ordenar ascendente
		numeroClicksInicio = clock();
		sorter.insertionSort(&listaPorInsercion, ASC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por Insercion en el caso general he tardado %.3f segundos.\n", segundosTranscurridos);
		if(sorter.esOrdenada(&listaPorInsercion, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");

		// volver a ordenar ascendente
		numeroClicksInicio = clock();
		sorter.insertionSort(&listaPorInsercion, ASC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por Insercion en el mejor caso he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorInsercion, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");

		// ordenar descendente
		numeroClicksInicio = clock();
		sorter.insertionSort(&listaPorInsercion, DESC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por Insercion en el peor caso he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorInsercion, DESC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");

		std::cout << std::endl;

		  /////////////////////
		 // SELECTION SORT  //	
		/////////////////////

		// ordenar ascendente
		numeroClicksInicio = clock();
		sorter.selectionSort(&listaPorSeleccion, ASC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por Seleccion en el caso general he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorSeleccion, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");

		// volver a ordenar ascendente
		numeroClicksInicio = clock();
		sorter.selectionSort(&listaPorSeleccion, ASC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por Seleccion en el mejor caso he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorSeleccion, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");

		// ordenar descendente
		numeroClicksInicio = clock();
		sorter.selectionSort(&listaPorSeleccion, DESC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por Seleccion en el peor caso he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorSeleccion, DESC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");

		std::cout << std::endl;

		  /////////////////////
		 //   BUBBLE SORT   //	
		/////////////////////

		// ordenar ascendente
		numeroClicksInicio = clock();
		sorter.bubbleSort(&listaPorBubble, ASC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por Bubble en el caso general he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorBubble, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");

		// volver a ordenar ascendente
		numeroClicksInicio = clock();
		sorter.bubbleSort(&listaPorBubble, ASC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por Bubble en el mejor caso he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorBubble, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");

		// ordenar descendente
		numeroClicksInicio = clock();
		sorter.bubbleSort(&listaPorBubble, DESC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por Bubble en el peor caso he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorBubble, DESC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");

		std::cout << std::endl;

		  /////////////////////
		 //   MERGE SORT   ///	
		/////////////////////

		// ordenar ascendente
		numeroClicksInicio = clock();
		sorter.mergeSort(&listaPorMerge, ASC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por Merge en el caso general he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorMerge, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");

		// volver a ordenar ascendente
		numeroClicksInicio = clock();
		sorter.mergeSort(&listaPorMerge, ASC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por Merge en el mejor caso he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorMerge, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");

		// ordenar descendente
		numeroClicksInicio = clock();
		sorter.mergeSort(&listaPorMerge, DESC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por Merge en el peor caso he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorMerge, DESC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");

		std::cout << std::endl;

		  /////////////////////
		 //   QUICK SORT   ///	
		/////////////////////

		// ordenar ascendente
		numeroClicksInicio = clock();
		sorter.quickSort(&listaPorQuick, ASC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por QucickSort en el caso general he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorQuick, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");

		// volver a ordenar ascendente
		numeroClicksInicio = clock();
		sorter.quickSort(&listaPorQuick, ASC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por QucickSort en el mejor caso he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorQuick, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");

		// ordenar descendente
		numeroClicksInicio = clock();
		sorter.quickSort(&listaPorQuick, DESC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por QucickSort en el peor caso he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorQuick, DESC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");

		std::cout << std::endl;

		  /////////////////////
		 //   RANGE SORT   ///	
		/////////////////////

		// ordenar ascendente
		numeroClicksInicio = clock();
		sorter.rangeSort(&listaPorRange, ASC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por Range en el caso general he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorRange, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");

		// volver a ordenar ascendente
		numeroClicksInicio = clock();
		sorter.rangeSort(&listaPorRange, ASC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por Range en el mejor caso he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorRange, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");

		// ordenar descendente
		numeroClicksInicio = clock();
		sorter.rangeSort(&listaPorRange, DESC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por Range en el peor caso he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorRange, DESC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADA CORRECTAMENTE!!! <<<<\n");

		std::cout << std::endl;
	}
	catch (const std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}