/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct Tnodo{
    int elemento;
    struct Tnodo *siguiente;
};
typedef struct Tnodo nodo;
 nodo *pInicio;


void ingresarNodo(int e){
    nodo *nuevo_nodo = new nodo;
    nuevo_nodo->elemento = e;
    nuevo_nodo->siguiente = pInicio;
    pInicio = NULL;
    if (pInicio == NULL) {
        pInicio = nuevo_nodo;
    } else {
        nodo *p = pInicio;
        nodo *q = NULL;
        while (p != NULL) {
            q = p;
            p = p->siguiente;
        }
        q->siguiente = nuevo_nodo;
    }
}

void eliminarNodo(){
    int num = 0;
    cout << "elemento a eliminar: ";
    cin >> num;

    nodo *p = pInicio, *q = NULL;
    while(p != NULL && (p->elemento) != num){
        q = p;
        p = p->siguiente;
    }
    if(p == NULL){
        cout << "El elemento NO existe" << endl;
        return;
    }
    if(q == NULL)
        pInicio = p->siguiente;
    else
        q->siguiente = p->siguiente;
    delete(p);
    cout << "elemento borrado!" << endl;

}

void mostrar(nodo *pinicio){
    if(pinicio!=NULL){
        cout<<pinicio->elemento<<" ";
        mostrar (pinicio->siguiente);
    }
    cout<<endl;
}



int main()
{
    pInicio = NULL;
    int e;
    char resp;
   bool continuar = true;

    do{
   cout<<"Ingresar? y/n"<<endl;
   cin>>resp;
   if(resp == 'y'){
       cin>> e;
       ingresarNodo(e);
   }else
       continuar = false;
 }while (continuar);
 mostrar(pInicio);
 eliminarNodo();
 mostrar(pInicio);
    return 0;
}
