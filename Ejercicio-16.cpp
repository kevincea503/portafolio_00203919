#include<iostream>
using namespace std;

int main() {
     float suma=0, promedio;
  int array[10] ={};

cout << "Ingrese 10 numeros enteros" << '\n';
for (int i = 0; i < 10; i++) {
    cin>>array[i];  // ingrsando elemntos
      }

    for (int i=0; i<10; i++) // realizando la suma
        suma += array[i];
        promedio = suma/10;
    cout<<"Su suma es:"<<suma<<endl;
    cout<<"El promedio es: "<<promedio<<endl;

  return 0;
}
