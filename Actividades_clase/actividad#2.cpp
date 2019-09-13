#include<iostream>

using namespace std;

float mediana(int i, int f, int*a){
  int mit = f/2;
  if(!(f%2==0)){
      mit-=0.5;
      return a[mit+1];
      }
  else{
    return ((a[mit-1] + a[mit])/2.0);
  }
}

int main() {
    int tam ={0};

  cout << "Ingrese tamaño del Arreglo" << '\n';
  cin>>tam;
  int array [tam];
  // inicializando array
  for(int i=0; i<tam; i++){
      int array[i] ={0};
      }
    cout << "Ingrese los elementos de menor a mayor" << '\n';
    for (int i = 0; i <tam; i++) {
      cin>>array[i];
        }

    cout <<"Mediana: "<<mediana(0, tam, array)<< '\n';

    return 0;
  }
