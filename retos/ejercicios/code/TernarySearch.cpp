template<class T>
int TernarySearch(T v[], int l, int r, T x){
    if( r >= l){
        int mid1 = l+(r-l)/3 ;
        int mid2 = mid1 + (r-l)/3 ;

        if( v[mid1] == x) return mid1 ;
        if( v[mid2] == x) return mid2 ;
        if( v[mid1] >  x) return TernarySearch(v,l,mid1-1,x);
        if( v[mid2] <  x) return TernarySearch(v,l,mid2+1,x);

        return TernarySearch(v,mid1+1,mid2-2,x) ;
    }

    return -1 ;
}
