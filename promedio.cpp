#include <iostream>
using namespace std;

int main(){
 int elementos = 5;
 int numeros[elementos];
 int total = 0;
 float promedio =0, diferencia =0;

for(int i=0; i<elementos; i++){
  cout << "Digite un numero: " << '\n';
  cin >> numeros[i];
  total+=numeros[i];
}

  promedio = (float)(total/elementos);
  cout << "promedio: "<<promedio << '\n';

  return 0;
}
