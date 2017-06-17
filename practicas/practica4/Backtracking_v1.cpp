#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include<stdio.h>

using namespace std;
const int MAX = 6;

int X[]={-2,-2,2,2,-1,-1,1,1};
int Y[]={-1,1,-1,1,-2,2,-2,2};


void MostrarTablero(int tablero[MAX][MAX]) {

    cout <<"--------------------------------"<< endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf(" %2d ",tablero[i][j]) ;
        }
        cout << endl << endl ;
    }
    cout << "----------------------------------"<< endl;
};

bool Dentro(int x, int y){
    if(x >= 0 and y >= 0 and x < MAX and y < MAX)
        return true ;
    else return false ;
}

bool valido(int x, int y, int tablero[MAX][MAX]){
    return(Dentro(x,y) && tablero[x][y] == 0);
}

int Grado(int x, int y, int tablero[MAX][MAX]){

}

bool Ensayar(int i, int x, int y,int tablero[MAX][MAX]){
    MostrarTablero(tablero) ;
    int k, siguiente_x=x, siguiente_y=y;
    char nada ;
    if(i == MAX*MAX){
        return true ;
    }

    for(k = 0 ; k < 8 ; k++){
        siguiente_x = x+X[k] ;
        siguiente_y = y+Y[k] ;

        if(Dentro(siguiente_x,siguiente_y)){

            if(tablero[siguiente_x][siguiente_y] == 0){
                tablero[siguiente_x][siguiente_y] = i ;
                if(Ensayar(i+1,siguiente_x,siguiente_y,tablero))
                    return true ;
                else
                    tablero[siguiente_x][siguiente_y] = 0 ;
            }
        }
    }
    return false ;
}

int main() {

    int tablero[MAX][MAX];
    int x=2,y=2;
    bool exito;

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            tablero[i][j] = 0;
        }
    }

    tablero[x][y] = 1;

    if(Ensayar(1,x,y, tablero)){
        cout << "\nLa solución encontrada es: " << endl ;
        MostrarTablero(tablero) ;
    }else{
        cout << "\nNo se ha encontrado solución." ;
    }
}
