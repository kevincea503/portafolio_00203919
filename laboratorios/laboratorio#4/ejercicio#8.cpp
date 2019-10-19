#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo *sig;
};


nodo *crearNodo(int num) {
    nodo *nuevo = new nodo();
    nuevo->dato = num;
    nuevo->sig = NULL;
    return nuevo;
}

void insertar(nodo *&pinicio, nodo *&nuevo){
    if(pinicio == NULL)
        pinicio = nuevo;
    else{
        insertar(pinicio->sig, nuevo);
    }
}

void mostrar(nodo *pinicio){
    if(pinicio!=NULL){
        cout<<pinicio->dato<<" ";
        mostrar (pinicio->sig);
    }
    cout<<endl;
}


void toBynary(int x, nodo *&pinicio){
    nodo * aux =NULL;
    if(x==0)
        return;
    else{
        toBynary((x/2), pinicio);
            if(x%2 == 0){
                aux = crearNodo(0);
                insertar(pinicio, aux);
            }else{
                aux = crearNodo(1);
                insertar(pinicio, aux);
            }
        }
    }
    


int main()
{
    nodo *pinicio = NULL;
    int numero;
    cin>>numero;
    toBynary(numero, pinicio);
    mostrar(pinicio);

    return 0;
}

