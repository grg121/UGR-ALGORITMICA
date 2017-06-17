#include "Solucion.h"

Solucion::Solucion() {
    Num= 0;
    coste= 0;
}

Solucion::Solucion(const Solucion & s) {

    Num= 0;
    coste= 0;
    *this = s;
}




double Solucion::getCoste() {

    return recubrimiento.size();
}

int getMaximo(int [] vector, int tam){
    int max = 0 ;
    for(int i = 1 ; i < tam ; i++){
        if(vector[i] > vector[i-1])
            max = i ;
    }
    return max ;
}

void Solucion::Evaluar(Problema p) {

    // calcular los grados de los nodos

    int * grados;
    int nodo_seleccionado;
    bool solucion = false;


    grados = new int[p.N] ;

    for(int i = 0 ; i < p.N ; i++) {
        for(int j = i ; j < p.N) {
            if(p.adyacencia[i][j] == 1){
                grados[i]++ ;
                grados[j]++ ;
            }
        }
    }

    while(recubrimiento.size() < p.N and !solucion) {
    	nodo_seleccionado = getMaximo(grados, p.N);
    	solucion = añadirNodo(nodo_seleccionado);

    }

}

bool Solucion::añadirNodo(int nodo, int * grados) {
	bool solucion = true;
	grados[nodo] = 0;
	for(int i=0; i<p.N; i++) {
		if(adyacencia[nodo][i] == 1) {
			grados[i]--;
			adyacencia[nodo][i] = 0;
		}

	}
	recubrimiento.push_back(nodo);

	for(int i=0; i<p.N && !solucion; i++) {
		if(grados[i] > 0) {
			solucion  = false;
		}
	}

	return solucion;
}




