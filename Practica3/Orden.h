#pragma once
#include <assert.h>
#include <cstdlib>
#include <stdexcept>
#include <typeinfo>

#include "ListaContigua.h"

// Values range (used in the rangeSort function). Both constant values are included in range.
#define MIN_VALUE 0
#define MAX_VALUE 99

#define ASC 1
#define DESC 0


class Orden
{
private:	
	// Compares a and b
	// E.g.: compare(1, 2, ASC) would return true, because 1, 2 is correct in ASC order
	// @Param	DATA_TYPE				a
	// @Param	DATA_TYPE				b
	// @Param	unsigned short			ASC or DESC
	// @Throws	std::invalid_argument
	bool compare(DATA_TYPE a, DATA_TYPE b, unsigned short order);

	// Spreads listaCompleta into sublista1 and sublista2
	// @Param	ListaContigua *			listaCompleta
	// @Param	ListaContigua *			sublista1
	// @Param	ListaContigua *			sublista2
	// @Precond	no NULL ptrs
	// @Precond	listaCompleta n >= 2
	// @Precond	sublista1 && sublista2 n == 0
	void repartir(ListaContigua* listaCompleta, ListaContigua* sublista1, ListaContigua* sublista2);

	// Combines the elements from origen1 and origen2 into destino in 'order' order
	// @Param	ListaContigua *			origen1
	// @Param	ListaContigua *			origen2
	// @Param	ListaContigua *			destino
	// @Param	unigned short			ASC or DESC
	// @Precond	no NULL ptrs
	// @Precond	origen1 && origen2 n >= 2
	// @Precond	destino n == 0
	// @Precond	esOrdenada(origen1, order) == true
	// @Precond	esOrdenada(origen2, order) == true
	void combinar(ListaContigua* origen1, ListaContigua* origen2, ListaContigua* destino, unsigned short order);
public:
	Orden();

	// Checks if list is ordered
	// @Param	ListaContigua *			lista
	// @Param	unsigned short			ASC or DESC
	bool esOrdenada(ListaContigua* lista, unsigned short order);

	// Orders list by insertion sort method
	// @Param	ListaContigua *			lista
	// @Param	unsigned short			ASC or DESC
	void insertionSort(ListaContigua* lista, unsigned short order);

	// Orders list by selection sort method
	// @Param	ListaContigua *			lista
	// @Param	unsigned short			ASC or DESC
	void selectionSort(ListaContigua* lista, unsigned short order);

	// Orders list by bubble sort method
	// @Param	ListaContigua *			lista
	// @Param	unsigned short			ASC or DESC
	void bubbleSort(ListaContigua* lista, unsigned short order);

	// Orders list by merge sort method
	// @Param	ListaContigua *			lista
	// @Param	unsigned short			ASC or DESC
	void mergeSort(ListaContigua* lista, unsigned short order);

	// Orders list by quick sort method
	// @Param	ListaContigua *			lista
	// @Param	unsigned short			ASC or DESC
	// @Throws	std::invalid_argument
	void quickSort(ListaContigua* lista, unsigned short order);

	#if defined(MIN_VALUE) && defined(MAX_VALUE)
	// Orders list when knowing the range in use
	// @Param	ListaContigua *			lista
	// @Param	unsigned short			ASC or DESC
	// @Precond	MAX_VALUE >= MIN_VALUE
	// @Precond DATA_TYPE == int
	// @Throws	std::invalid_argument
	void rangeSort(ListaContigua* lista, unsigned short order);
	#endif

	~Orden();
};

