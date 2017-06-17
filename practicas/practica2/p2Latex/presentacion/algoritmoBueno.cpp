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
