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
