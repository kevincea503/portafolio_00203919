#include <iostream>
using namespace std;

int mcd(int mayor, int menor){

  if(mayor%menor==0)
    return menor;
  else{
    int aux = mayor%menor;
    mayor =menor;
    menor =aux;
    mcd(mayor, menor);
  }

}

int main() {
int n1,n2;
cout << "Ingrese numeros: " << '\n';
cin>>n1;
cin>>n2;
cout << "MCD:"<<mcd(n1,n2) << '\n';

  return 0;
}
