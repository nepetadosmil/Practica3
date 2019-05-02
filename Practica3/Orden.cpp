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
		throw ORDER_ERR;
	}
}



void Orden::repartir(ListaContigua* listaCompleta, ListaContigua* sublista1, ListaContigua* sublista2) {
	assert(listaCompleta != NULL && sublista1 != NULL && sublista2 != NULL);
	assert(listaCompleta->getN() >= 2);
	assert(sublista1->getN() == 0 && sublista2->getN() == 0);
	unsigned end = listaCompleta->getN();//Guarda longitud
	unsigned half = end / 2;//Calcula mitad

	for (unsigned i = 0; i < half; ++i) {
		sublista1->insertarAlFinal(listaCompleta->getValor(0));//Rellena sublista1 con la primera mitad
		listaCompleta->eliminar(0);
	}
	for (unsigned i = half, j = 0; i < end; ++i, ++j) {
		sublista2->insertarAlFinal(listaCompleta->getValor(0));//Rellena sublista2 con la segunda mitad
		listaCompleta->eliminar(0);
	}
}



void Orden::combinar(ListaContigua* origen1, ListaContigua* origen2, ListaContigua* destino, unsigned short order) {
	assert(origen1 != NULL && origen2 != NULL && destino != NULL);
	assert(origen1->getN() >= 1 && origen2->getN() >= 1);
	assert(destino->getN() == 0);
	assert(esOrdenada(origen1, order) && esOrdenada(origen2, order));

	while (origen1->getN() > 0 && origen2->getN() > 0) { // Fill in order until one of both is empty
		if (compare(origen1->getValor(0), origen2->getValor(0), order)) {
			destino->insertarAlFinal(origen1->getValor(0));
			origen1->eliminar(0);
		}
		else {
			destino->insertarAlFinal(origen2->getValor(0));
			origen2->eliminar(0);
		}
	}

	while (origen1->getN() > 0) { // Fill any remaining elements
		destino->insertarAlFinal(origen1->getValor(0));
		origen1->eliminar(0);
	}

	while (origen2->getN() > 0) { // Fill any remaining elements
		destino->insertarAlFinal(origen2->getValor(0));
		origen2->eliminar(0);
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
	unsigned i, j, max_min; // max_min is the index of the greatest (or smallest, depending on order) value that's left

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



void Orden::bubbleSort(ListaContigua* lista, unsigned short order)
{
	bool repeat;
	unsigned done = 0;
	DATA_TYPE tmp;

	do {
		repeat = false;

		for (unsigned i = 0; i + 1 + done < lista->getN(); ++i) {
			if (compare(lista->getValor(i + 1), lista->getValor(i), order)) { // If numbers not in order, swap them
				tmp = lista->getValor(i);
				lista->setValor(i, lista->getValor(i + 1));
				lista->setValor(i + 1, tmp);
				repeat = true;
			}
		}
		
		++done; // For efficiency. After n loops, the last n numbers will be in order, so no need to check
	} while (repeat == true);
}



void Orden::mergeSort(ListaContigua* lista, unsigned short order)
{
	if (lista->getN() == 1)
		return;

	ListaContigua lista1;
	ListaContigua lista2;
	repartir(lista, &lista1, &lista2);

	mergeSort(&lista1, order);
	mergeSort(&lista2, order);

	combinar(&lista1, &lista2, lista, order);
}



Orden::~Orden()
{

}
