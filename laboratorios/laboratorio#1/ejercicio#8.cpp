#include <iostream>
using namespace std;

void recursion(int x, int c){

  if( c == x){
    cout << c << '\n';
  }
  else{
    cout << c << '\n';
    recursion(x, c + 1);
    cout << c << '\n';
  }
    }


int main() {

int n = 0, cont = 1, r;

cout << "Ingrese un numero entero" << '\n';
cin>>n;
 recursion(n, cont);




  return 0;
}
