#include "Orden.h"

Orden::Orden()
{

}



bool Orden::compare(DATA_TYPE a, DATA_TYPE b, unsigned short order)
{
	switch (order)
	{
	case ASC:
		return a < b;
	case DESC:
		return a > b;
	default:
		throw std::invalid_argument("Invalid sorting order!");
	}
}



bool Orden::esOrdenada(ListaContigua* lista, unsigned short order)
{
	for (unsigned i = 0; i + 1 < lista->getN(); ++i) {
		if (!compare(lista->getValor(i), lista->getValor(i + 1), order))
			return false;
	}
	return true;
}



void Orden::insertionSort(ListaContigua* lista, unsigned short order)
{
	DATA_TYPE tmp;
	unsigned i, j;

	for (i = 1; i < lista->getN(); ++i) { // We start at index 1, because we wouldn't be able to compare index 0 with anything
		tmp = lista->getValor(i);

		for (j = i - 1; j > 0 && compare(tmp, lista->getValor(j), order); --j) {
			lista->setValor(j + 1, lista->getValor(j));
		}

		// These if/else are here so we can keep j as an unsigned integer and hence,
		// be able to parse longer lists with less memory space required
		if (compare(tmp, lista->getValor(j), order)) {
			lista->setValor(j + 1, lista->getValor(j));
			lista->setValor(j, tmp);
		}
		else {
			lista->setValor(j + 1, tmp);
		}
	}
}



void Orden::selectionSort(ListaContigua* lista, unsigned short order)
{
	DATA_TYPE tmp;
	unsigned i, j, max_min; // max_min is the index of the greatest (or smallest, depending on order) value left

	for (i = 0; i < lista->getN(); ++i) {
		max_min = i;
		for (j = i + 1; j < lista->getN(); ++j) { // Find the greatest (or smallest, depending on order) value of those remaining.
			if (compare(lista->getValor(j), lista->getValor(i), order)) {
				max_min = j;
			}
		}

		tmp = lista->getValor(i);
		lista->setValor(i, lista->getValor(max_min));
		lista->setValor(max_min, tmp);
	}
}



Orden::~Orden()
{

}
