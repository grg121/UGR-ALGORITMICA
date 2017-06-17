template<class T>
int BinarySearch(T v[], int l, int r, T x){
    if( r >= l){
        int mid = l + (r-l)/2 ;

        if(v[mid] == x) return mid ;

        if(v[mid] > x) return binarySearch(v,l,mid-1,x);

        return binarySearch(v,mid+1,r,x) ;
    }

    return -1 ;
}
