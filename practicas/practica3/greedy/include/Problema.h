#ifndef PROBLEMA_H
#define PROBLEMA_H

#include <string>

using namespace std;


class Problema
{
    public:
        Problema();
        Problema(const Problema & p);
        Problema & operator=(const Problema &p);
        ~Problema();

        bool cargarDesdeFlujo(const char *nombreFichero); // Carga un problema
                                                    // desde el fichero dado por argumento.
                                                    // Devuelve true si ok, y false
                                                    // si error al cargarlo

        int getNumNodos(); // Devuelve el número de nodos del problema

        unsigned int N; // Num. de nodos

        double **adyacencia; // cada posición [i][j] representa si hay o no arista entre los vértices i y j.


    private:
};

#endif // PROBLEMA_H
