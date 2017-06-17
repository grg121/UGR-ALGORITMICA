#ifndef SOLUCION_H
#define SOLUCION_H
#include <vector>
#include "Problema.h"


class Solucion
{
    public:
        Solucion(); // Construye una solución vacía, con coste 0 y sin aristas
        Solucion(const Solucion & s); // Constructor de copia

        ~Solucion(); // Destructor

        Solucion & operator=(const Solucion & s); // Operador de asignación

        double getCoste(); // Devuelve el coste de la solución


        /*
            Evalúa la solución actual en el problema "p". Como resultado, se modifica
            el coste de la solución actual. El coste será -1 si hay error al evaluar.
        */
        void Evaluar(Problema p);

        int getNumNodos(); // Devuelve el número de nodos en la solución

        void añadirNodo(int nodo, int * grados);

    private:

        /*
          La solución es un vector de Num Aristas. Las Aristas se representarán en
          el vector "Aristas[0..1][0..Num-1]. Cada columna "i" de la matriz será una
          arista, donde la componente Arista[0][i] es el nodo origen, y la componente
          Arista[1][i] es el nodo destino.

          Cada nodo se representará con un valor entero, desde 0 hasta
          p.getNumPlazas()-1, donde "p" es un objeto de la clase "Problema". Dicho nodo
          se corresponderá con la plaza "p.getNombrePlaza ( Aristas[j][i] )"
        */
        vector<int> recubrimiento ; 
};

#endif // SOLUCION_H
