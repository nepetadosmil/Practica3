/********************/
/*    PRÁCTICA 3    */
/*   NÉSTOR PÉREZ   */
/*   RAÚL  SANCHO   */
/********************/

#include "impresionListasContiguas.h"
#include "ListaContigua.h"
#include "Orden.h"

int main(int argc, char* argv[]) {
	ListaContigua lista;
	Orden sorter;

	for (unsigned i = 0; i < 5; ++i)
		lista.insertarAlFinal(i);

	imprimirListaContigua(&lista);

	try {
		sorter.insertionSort(&lista, DESC);
		imprimirListaContigua(&lista);
	}
	catch (const std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}