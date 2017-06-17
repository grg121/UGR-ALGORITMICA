#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>

//generador de ejemplos para el problema de la comparación de preferencias.
//Simplemente se genera una permutación aleatoria del vector 0,1,2,...,n-2,n-1

double uniforme() //Genera un número uniformemente distribuido en el
                  //intervalo [0,1) a partir de uno de los generadores
                  //disponibles en C.
{
 int t = rand();
 double f = ((double)RAND_MAX+1.0);
 return (double)t/f;
}

int main(int argc, char * argv[])
{
    int  n = 7;
    int T[7] = {6,3,4,1,0,5,2} ;

    cout << endl;
    for (int j=0; j<n; j++)
        cout << "["<< T[j]<<"]" ;

    cout << "\n********** ORDENANDO ************ \n";

    int inversiones = 0 ;
    for(int i = 0 ; i <n ; i++)
        for(int j = i+1 ; j < n ; j++){
            if(T[j] < T[i])
                inversiones++;
        }

    cout << "\nNúmero de inversiones: " << inversiones ;

}
