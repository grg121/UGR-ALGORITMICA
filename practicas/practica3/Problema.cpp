#include "Problema.h"
#include <fstream>
#include <iostream>

using namespace std;


Problema::Problema() {

    N= 0;
}


Problema::Problema(const Problema & p) {

    N= 0;
    *this= p;
}


Problema & Problema::operator=(const Problema &p) {

    if (&p == this) // Para evitar cosas como mivariables= mivariables
        return *this;


    if (N > 0) { // Liberar la memoria previa
        delete [] adyacencia;
    }

    N= p.N; // Reserva de memoria nueva si es necesario y copia
    if (N>0) {

        adyacencia= new double *[N];

        for (unsigned int i= 0; i<N; i++) {

            adyacencia[i]= new double[N];

            for (unsigned int j= 0; j<N; j++) {
                adyacencia[i][j]= p.precioCalles[i][j];
            }
        }

    }


    return *this;
}


Problema::~Problema() {

    if (N!= 0) {

        for (unsigned int i= 0; i<N; i++) {
                    delete [] adyacencia[i];
        }
        delete [] adyacencia;
    }
}


bool Problema::cargarDesdeFlujo(const char *nombreFichero) {

    /*
        Formato del fichero
        Línea 1: N (número de nodos, > 0
        el resto de lineas es la matriz de adyacencia.
    */

    // Liberar memoria si la hubiese
    if (N!= 0) {

        for (unsigned int i= 0; i<N; i++) {
                    delete [] adyacencia[i];
        }
        delete [] adyacencia;
    }

    // Inicializar a problema vacío
    N= 0;

    ifstream fichero;

    fichero.open( nombreFichero );
    if ( !fichero )
        return false;

    fichero >> N;
    if (N<=0) {
        fichero.close();
        N= 0;
        return false;
    }

    // Reserva de la memoria para el "N" nuevo
    adyacencia= new double *[N];

    for (unsigned int i= 0; i<N; i++) {

        adyacencia[i]= new double[N];
    }

    while (!fichero.eof()) {

        int i, j;
        int x ; 
        
        for(int i = 0 ; i < N ; i++)
            for(int j = 0 ; j < N ; j++)
                fichero >> adyacencia[i][j] ;
    }

    fichero.close();

/*
    cout << "N= " << N << endl;
    for (unsigned int i= 0; i<N; i++)
        cout << "Plaza " << nombresPlazas[i] << endl;

    for (unsigned int i= 0; i<N; i++)
        for (unsigned int j= 0; j<N; j++)
            if (precioCalles[i][j] != -1) {
                cout << "i=" << i<< " j=" << j << " p=" <<precioCalles[i][j] << " ";
                cout << nombresCalles[i][j]<<endl;
            }
*/

    return true;
}


