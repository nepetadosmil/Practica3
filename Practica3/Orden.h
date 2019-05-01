#pragma once
#include <stdexcept>

#include "ListaContigua.h"

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
	~Orden();
};

