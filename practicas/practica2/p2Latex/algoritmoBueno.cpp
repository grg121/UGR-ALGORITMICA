int Posicion (vector<int> &vO, int ini, int fin, int &x) {
    int resultado = 0;
    if(ini <= fin) {
        int m = ((fin - ini)/2)+ ini;
        //    cout << "x: " << x << " m: " << vO[m] << " " ;
        if(x < vO[m]) resultado = Posicion(vO, ini, m, x);
        else if (x>vO[m]) resultado = Posicion(vO, m+1, fin, x);
        else resultado = m;
    }
    else resultado = -1;

    //  cout << "esto es el resultado: " << resultado << endl;
    return resultado;

}

int Preferencias(vector<int> vO, vector<int> vD) {
    int res = 0;

    while(vD.size() > 0) {
        int x = vD.front();

        int pos = Posicion(vO, 0, vO.size()-1, x);
        // cout << "pos "  <<  pos ;
        res = res + pos ;

//    cout << "\n";

        vO.erase(find(vO.begin(),vO.end(),x));
        vD.erase(vD.begin());
    }

//  cout << "resultado: " << res ;

    return res;

}

vector<int> desordenado ;
vector<int> ordenado;



for(int i = 0 ; i < n ; i++) {
    desordenado.push_back(T[i]) ;
    ordenado.push_back(i);
}


double tiempo_transcurrido;
const int NUM_VECES=10000;
clock_t tantes=clock();
int inversiones;
for (int i=0; i<NUM_VECES;i++)
    inversiones = Preferencias(ordenado,desordenado) ;

clock_t tdespues = clock();

tiempo_transcurrido=((double)(tdespues-tantes)/(CLOCKS_PER_SEC* (double)NUM_VECES));

//cout << "\nInversiones = " << inversiones ;
cout << "\n" << n  << "\t" << tiempo_transcurrido << endl;



}
