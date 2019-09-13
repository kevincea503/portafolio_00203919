#include<iostream>
using namespace std;

int producto(int a, int b){
    if(b==1){
      cout << "b=" << a << " caso base" << endl;
      return a;
    }
    else{
      return a + producto(a, b-1);
          }
    }

int main(){
int n1=0  , n2, r;
cout << "ingrese los numeros a multiplicar:" << '\n';
cin>>n1;
cin>>n2;
 r = producto(n1,n2);
cout << "Resultado: " <<r<< endl;
  return 0;
}
