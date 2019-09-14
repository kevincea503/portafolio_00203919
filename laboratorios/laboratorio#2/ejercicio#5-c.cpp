#include <iostream>
using namespace std;

void hanoi(int d, int t1, int t2, int t3){
  if(d==1){
    cout << "Mover disco de la torre "<<t1<<" a la torre "<<t3 << '\n';
  }else{
    hanoi(d-1, t1, t3, t2);
    cout << "Mover disco de la torre "<<t1<<" a la torre "<<t3 << '\n';
    hanoi(d-1, t2, t1, t3);

  }
}

int main() {
  int disco =0, torre1=1, torre2=2, torre3=3;

  cout << "con cuantos discos quiere jugar:";
  cin>>disco;

  hanoi(disco, torre1, torre2, torre3);

  return 0;
}
