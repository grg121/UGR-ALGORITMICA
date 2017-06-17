#include <iostream>
#include <vector>
#include<fstream>
using namespace std;



class Problema
{
    public:

    Problema(){
        N = 0 ;
    }

        bool cargarDesdeFlujo(const char *nombreFichero); // Carga un problema
                                                    // desde el fichero dado por argumento.
                                                    // Devuelve true si ok, y false
                                                    // si error al cargarlo

        int getNumNodos(); // Devuelve el número de nodos del problema

    unsigned int N ; // Num. de nodos

        int **adyacencia; // cada posición [i][j] representa si hay o no arista entre los vértices i y j.


    private:
};


class Solucion
{
    public:

        double getCoste(); // Devuelve el coste de la solución


        /*
            Evalúa la solución actual en el problema "p". Como resultado, se modifica
            el coste de la solución actual. El coste será -1 si hay error al evaluar.
        */
        void Evaluar(Problema p);

        int getNumNodos(); // Devuelve el número de nodos en la solución

    bool addNodo(int nodo, int * &grados, Problema p);

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



double Solucion::getCoste() {

    return recubrimiento.size();
}

int getMaximo(int vector[], int tam){
    //cout << "\nGetmaximo" << endl ;
    int max = 0 ;
    //cout << "nodo " << 0 << " grado " << vector[0] << endl ;
    for(int i = 1 ; i < tam ; i++){
        //  cout << "nodo " << i << " grado " << vector[i] << endl ;
        if(vector[i] >= vector[max]){
            max = i ;
        }
    }
    return max ;
}

void Solucion::Evaluar(Problema p) {

    // calcular los grados de los nodos

    int * grados;
    int nodo_seleccionado;
    bool solucion = false;


    grados = new int[p.N] ;

    cout << "\nEvaluando problema." << endl ;

    for(int i = 0 ; i < p.N ; i++)
        grados[i] = 0 ;



    for(int i = 0 ; i < p.N ; i++) {
        for(int j = i ; j < p.N; j++) {
            if(p.adyacencia[i][j] == 1){
                grados[i]++ ;
                grados[j]++ ;
            }
        }
    }

    //    cout << "\nGrados iniciales: " << endl ;
    /*
    for(int i=0; i<p.N ; i++) {
        cout << "\nNodo " << i << " grado " << grados[i] << endl ;
    }
    */

    while(recubrimiento.size() < p.N and !solucion) {

      nodo_seleccionado = getMaximo(grados, p.N);

      //cout << "\nSeleccionamos nodo: " << nodo_seleccionado << endl ;

      solucion = addNodo(nodo_seleccionado, grados, p);

    }
}

bool Solucion::addNodo(int nodo, int * &grados, Problema p) {

  grados[nodo] = 0;
  for(int i=0; i<p.N; i++) {
    if(p.adyacencia[nodo][i] == 1) {
      grados[i]--;
      p.adyacencia[nodo][i] = 0;
    }

  }
  recubrimiento.push_back(nodo);

  /*
  cout << "\nNuevos grados: " << endl ;

  for(int i = 0 ; i < p.N ; i++){
        cout << "\nNodo " << i << " grado " << grados[i] << endl ;
        }*/

  for(int i=0; i<p.N ; i++) {
    if(grados[i] > 0) {
        return false ;
    }
  }
  return true ;
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
    adyacencia= new int *[N];

    for (unsigned int i= 0; i<N; i++) {

        adyacencia[i]= new int[N];
    }

    while (!fichero.eof()) {

        int i, j;
        int x ;

        for(int i = 0 ; i < N ; i++)
            for(int j = 0 ; j < N ; j++)
                fichero >> adyacencia[i][j] ;
    }

    fichero.close();

    return true;
}



int main(int argc, char * argv[]){

    if(argc < 2){
        cout << "\nTienes que pasar el nombre del fichero con los datos como parámetro." << endl ;
        return -1 ;
    }

    Problema myproblema ;

    myproblema.cargarDesdeFlujo(argv[1]) ;

    Solucion mysolucion ;

    mysolucion.Evaluar(myproblema) ;


    cout << "\nNúmero de nodos necesarios: " << mysolucion.getCoste() << endl ;

    cout << "\nNodos necesarios: -";
    int i ;
    for(i = 0 ; i < mysolucion.recubrimiento.size() ; i++)
        cout << mysolucion.recubrimiento[i] << "-" ;
    cout << endl ;
}
