#include <iostream>
using namespace std;

int recursion(int x){

  if(x>=0 && x<10){
    return 1;
  }
  else{

  return  1 + recursion(x/10);


  }
    }

int main() {

int n = 0, c=0;

cout << "Ingrese un numero entero" << '\n';
cin>>n;

cout << "Cifras: "<<recursion(n)<< '\n';


  return 0;
}
