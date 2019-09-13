#include <iostream>
using namespace std;

int busbin(int low, int high, int x, int *l){
    if(low > high)
        return -1;
    int mid = (low+high)/2;
    if(x==l[mid])
        return mid;
    if(x<l[mid])
        return busbin(low, mid-1, x, l);
    else
        return busbin(mid+1, high, x, l);
}

int main(){
    int n=0, longitud [8] = {1,3,4,5,17,18,31,33};
    cout<< "Arreglo: 1,3,4,5,17,18,31,33" <<endl;
      cout<< "Ingrese el elemento a buscar" <<endl;
      cin>>n;
        if(n>=0){
         cout<<"El elemento esta en la posicion: "<<busbin(0, 7, n, longitud)<<endl;
        }
        else{
        cout << "Error." << endl;
        }

    return 0;
}
