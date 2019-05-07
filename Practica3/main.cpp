/********************/
/*    PRÁCTICA 3    */
/*   NÉSTOR PÉREZ   */
/*   RAÚL  SANCHO   */
/********************/

#include "main.h"

int main(int argc, char* argv[]) {
	ListaContigua listaPorInsercion;
	Orden sorter;
	int size;

	std::cout << "Tamano de la lista: ";
	std::cin >> size;

	srand(NULL); // Random seed
	for (unsigned i = 0; i < size; ++i)
		listaPorInsercion.insertarAlFinal(rand() % (MAX_VALUE + 1)); // Rellenar con números entre 0 y MAX_VALUE

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
		printf("Con ordenacion por INSERCION en el caso general he tardado %.3f segundos.\n", segundosTranscurridos);
		if(sorter.esOrdenada(&listaPorInsercion, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADO CORRECTAMENTE!!! <<<<\n");

		// volver a ordenar ascendente
		numeroClicksInicio = clock();
		sorter.insertionSort(&listaPorInsercion, ASC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por INSERCION en el mejor caso he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorInsercion, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADO CORRECTAMENTE!!! <<<<\n");

		// ordenar descendente
		numeroClicksInicio = clock();
		sorter.insertionSort(&listaPorInsercion, DESC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por INSERCION en el peor caso he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorInsercion, DESC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADO CORRECTAMENTE!!! <<<<\n");

		std::cout << std::endl;

		  /////////////////////
		 // SELECTION SORT  //	
		/////////////////////

		// ordenar ascendente
		numeroClicksInicio = clock();
		sorter.selectionSort(&listaPorSeleccion, ASC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por SELECCION en el caso general he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorSeleccion, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADO CORRECTAMENTE!!! <<<<\n");

		// volver a ordenar ascendente
		numeroClicksInicio = clock();
		sorter.selectionSort(&listaPorSeleccion, ASC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por SELECCION en el mejor caso he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorSeleccion, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADO CORRECTAMENTE!!! <<<<\n");

		// ordenar descendente
		numeroClicksInicio = clock();
		sorter.selectionSort(&listaPorSeleccion, DESC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por SELECCION en el peor caso he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorSeleccion, DESC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADO CORRECTAMENTE!!! <<<<\n");

		std::cout << std::endl;

		  /////////////////////
		 //   BUBBLE SORT   //	
		/////////////////////

		// ordenar ascendente
		numeroClicksInicio = clock();
		sorter.bubbleSort(&listaPorBubble, ASC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por BUBBLE en el caso general he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorBubble, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADO CORRECTAMENTE!!! <<<<\n");

		// volver a ordenar ascendente
		numeroClicksInicio = clock();
		sorter.bubbleSort(&listaPorBubble, ASC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por BUBBLE en el mejor caso he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorBubble, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADO CORRECTAMENTE!!! <<<<\n");

		// ordenar descendente
		numeroClicksInicio = clock();
		sorter.bubbleSort(&listaPorBubble, DESC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por BUBBLE en el peor caso he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorBubble, DESC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADO CORRECTAMENTE!!! <<<<\n");

		std::cout << std::endl;

		  /////////////////////
		 //   MERGE SORT   ///	
		/////////////////////

		// ordenar ascendente
		numeroClicksInicio = clock();
		sorter.mergeSort(&listaPorMerge, ASC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por MERGE en el caso general he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorMerge, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADO CORRECTAMENTE!!! <<<<\n");

		// volver a ordenar ascendente
		numeroClicksInicio = clock();
		sorter.mergeSort(&listaPorMerge, ASC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por MERGE en el mejor caso he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorMerge, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADO CORRECTAMENTE!!! <<<<\n");

		// ordenar descendente
		numeroClicksInicio = clock();
		sorter.mergeSort(&listaPorMerge, DESC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por MERGE en el peor caso he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorMerge, DESC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADO CORRECTAMENTE!!! <<<<\n");

		std::cout << std::endl;

		  /////////////////////
		 //   QUICK SORT   ///	
		/////////////////////

		// ordenar ascendente
		numeroClicksInicio = clock();
		sorter.quickSort(&listaPorQuick, ASC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por QUICKSORT en el caso general he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorQuick, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADO CORRECTAMENTE!!! <<<<\n");

		// volver a ordenar ascendente
		numeroClicksInicio = clock();
		sorter.quickSort(&listaPorQuick, ASC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por QUICKSORT en el mejor caso he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorQuick, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADO CORRECTAMENTE!!! <<<<\n");

		// ordenar descendente
		numeroClicksInicio = clock();
		sorter.quickSort(&listaPorQuick, DESC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por QUICKSORT en el peor caso he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorQuick, DESC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADO CORRECTAMENTE!!! <<<<\n");

		std::cout << std::endl;

		  /////////////////////
		 //   RANGE SORT   ///	
		/////////////////////

		// ordenar ascendente
		numeroClicksInicio = clock();
		sorter.rangeSort(&listaPorRange, ASC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por RANGO en el caso general he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorRange, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADO CORRECTAMENTE!!! <<<<\n");

		// volver a ordenar ascendente
		numeroClicksInicio = clock();
		sorter.rangeSort(&listaPorRange, ASC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por RANGO en el mejor caso he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorRange, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADO CORRECTAMENTE!!! <<<<\n");

		// ordenar descendente
		numeroClicksInicio = clock();
		sorter.rangeSort(&listaPorRange, DESC);
		numeroClicksFin = clock();
		segundosTranscurridos = ((float)numeroClicksFin - numeroClicksInicio) / CLOCKS_PER_SEC;
		printf("Con ordenacion por RANGO en el peor caso he tardado %.3f segundos.\n", segundosTranscurridos);
		if (sorter.esOrdenada(&listaPorRange, DESC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADO CORRECTAMENTE!!! <<<<\n");

		std::cout << std::endl;
	}
	catch (const std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}