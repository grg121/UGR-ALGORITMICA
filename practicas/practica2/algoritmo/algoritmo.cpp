#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include<vector>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

/*

The maximum number of inversions that an
n-size array can have is

    n*(n-1) / 2

*/

int cuenta_y_combina(int vector[], int izquierda, int derecha){
    int mid = (izquierda+derecha)/2;
    int ret = 0 ;
    int a = izquierda ;
    int b = mid+1;
    int resultado[derecha-izquierda+1];
    int r = 0;

    while(a <= mid && b <= derecha){
        if(vector[a] <= vector[b]){
            resultado[r++] = vector[a++] ;
        }else{
            resultado[r++] = vector[b++] ;
            ret += mid - a + 1;
        }
    }

    while(a <= mid)
        resultado[r++] = vector[a++] ;
    while(b <= derecha)
        resultado[r++] = vector[b++] ;

    for(int i = 0 ; i < derecha-izquierda+1 ; i++){
        vector[i+izquierda] = resultado[i] ;
    }

    return ret ;
}

int ContarInversiones(int vector[], int izquierda, int derecha){
    int x,y,z,mid;
    if(izquierda >= derecha) return 0 ;
    mid = (izquierda+derecha)/2;

    x = ContarInversiones(vector, izquierda, mid);
    y = ContarInversiones(vector, mid+1, derecha);
    z = cuenta_y_combina(vector, izquierda, derecha);

    return x+y+z;
}



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

  if (argc != 2)
    {
      cerr << "Formato " << argv[0] << " <num_elem>" << endl;
      return -1;
    }

  int n = atoi(argv[1]);

  int * T = new int[n];
  assert(T);

srand(time(0));

 for (int j=0; j<n; j++){
     T[j] = j ;
 }
for (int j=n-1; j>0; j--) {
   double u=uniforme();
   int k=(int)(j*u);
   int tmp=T[j];
   T[j]=T[k];
   T[k]=tmp;
}
    int a[n];

    for(int i = 0 ; i < n ; i++)
        a[i] = T[i] ;

    cout << "\nT:";

    for (int j=0; j<n; j++){
        cout << "[" << T[j] << "]" ;
    }

    cout << "\n********** ORDENANDO ************ \n";

    int inversiones = 0 ;
    int len = n;
    inversiones = ContarInversiones(a, 0, len-1);

    for(int i = 0 ; i < len ; i++)
        cout << "[" << a[i] << "]" ;

    cout << "\nNúmero de inversiones: " << inversiones << " de " << n << endl ;

    inversiones = 0 ;
    for(int i = 0 ; i < n ; i++)
        for(int j = i+1 ; j < n ; j++){
            if(T[j] < T[i])
                inversiones++;
        }

    cout << "\nNúmero de inversiones: " << inversiones << " de " << n << endl ;

}
