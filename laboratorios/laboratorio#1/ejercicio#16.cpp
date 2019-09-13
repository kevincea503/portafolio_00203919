#include <iostream>
using namespace std;


int main() {
  int array [10];
  float suma =0;

  for(int i=0; i<10; i++)
    array[i]=0;

  cout << "Digite 10 enteros" << '\n';
  for(int i=0; i<10; i++)
    cin>>array[i];

    for(int i=0; i<10; i++)
      suma +=array[i];

    float promedio = suma/10.0;

  cout << "Suma: " <<suma<< '\n';
  cout << "Promedio: " <<promedio<< '\n';

  return 0;
}
