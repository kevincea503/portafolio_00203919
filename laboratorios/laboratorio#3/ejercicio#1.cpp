
#include <stdlib.h>
#include <time.h>
#include<iostream>
using namespace std;

struct TNodo{
    int dato;
    struct TNodo *sig;
};
typedef struct TNodo Nodo;
Nodo *pInicio;

void insertarFinal(int num) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = num;
    nuevo->sig = NULL;

    if (pInicio == NULL) {
        pInicio = nuevo;
    } else {
        Nodo *p = pInicio;
        Nodo *q = NULL;
        while (p != NULL) {
            q = p;
            p = p->sig;
        }
        q->sig = nuevo;
    }
}

void agregarNumero(){
    int num = 0, c;

     srand(time(NULL));

    for(c = 1; c <= 100; c++)
    {
        num = 1 + rand() % (101 - 1);
         insertarFinal(num);
}
    }



void mostrarLista() {
    Nodo *s = pInicio;

    while (s != NULL) {
        cout << (s->dato)<<" ";
        s = s->sig;
    }
    cout<<endl;
}

void mostrarPares(){
  Nodo *s = pInicio;

  while (s != NULL){
      if (s->dato%2 == 0)
      cout << (s->dato)<<" ";
      
      s = s->sig;
   }
  cout<<endl;
 }


void mostrarImpares(){
  Nodo *s = pInicio;

  while (s != NULL){
     
   if (!(s->dato%2 == 0))
      cout << (s->dato)<<" ";
      
      s = s->sig;
   }
  cout<<endl;
}

void mostrarListaInversa(Nodo *s){
  if(s == NULL)
    return;
  else{
    mostrarListaInversa(s->sig);
    cout <<s->dato<<" ";
  }
 
 }

int main(){
    cout << "Inicializando..." << endl;
    pInicio = NULL;

    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar numeros aleatorio\n\t2) mostrar todo los elementos"
            << "\n\t3) Mostrar los numeros pares\n\t4) Mostrar los numeros impares\n\t5) Mostrar contenido inverso \n\t6) Salir\n\t Opcion: ";
        cin >> opcion;
        switch(opcion){
            case 1: cout << "Agregando..." << endl;
                agregarNumero();
            break;
            case 2: cout << "Listando... " << endl;
                mostrarLista();
            break;
            case 3: cout << "Listando... " ;
                mostrarPares();
            break;
            case 4: cout << "Listando... " << endl;
                mostrarImpares();
            break;
            case 5: cout << "Listando... " << endl;
                mostrarListaInversa(pInicio);
                cout<<endl;
            break;
            case 6: continuar = false;

            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}
