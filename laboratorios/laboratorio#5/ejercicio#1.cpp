#include <iostream>
using namespace std;

//------ Creacion de nodo y de arbol ------
struct nodo{
    int info;
    struct nodo *izq;
    struct nodo *der;
};
typedef struct nodo Nodo;
typedef struct nodo *Arbol;

Arbol crearArbol(int x){
    Arbol p = new Nodo;
    p->info = x;
    p->izq = NULL;
    p->der = NULL;
    return p;
}

//------ Agregar nodos a un arbol ------
void asignarIzq(Arbol a, int unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->izq != NULL)
        cout << "Error: subarbol IZQ ya existe" << endl;
    else
        a->izq = crearArbol(unDato);
}

void asignarDer(Arbol a, int unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->der != NULL)
        cout << "Error: subarbol DER ya existe" << endl;
    else
        a->der = crearArbol(unDato);
}

void agregarNodo(Arbol a){
    //solicitar informacion (numero a agregar)
    int numero = 0;
    cout << "Numero a agregar: ";
    cin >> numero;

    Arbol p = a;

    //desplazarse hasta el lugar adecuado
    while(true){
        if(numero == p->info){
            cout << "Error: " << numero << " ya existe" << endl;
            return;
        }
        else if(numero < p->info){//ir a la izquierda
            if(p->izq == NULL)
                break;
            else
                p = p->izq;
        }
        else{//ir a la derecha
            if(p->der == NULL)
                break;
            else
                p = p->der;
        }
    }

    //agregar el nuevo nodo
    if(numero < p->info)
        asignarIzq(p, numero);
    else
        asignarDer(p, numero);
}
int cont = 0;
//------ Recorrer un arbol (in, pre y post orden) ------

void inorden(Arbol a){
    if(a != NULL){
        inorden(a->izq);
        cout << " " << a->info;
        inorden(a->der);
        cont ++;
    }
    
}

void recorrerArbol(Arbol a){
    cout << "Recorrido IN orden:"; inorden(a); cout <<endl;

}

int altura(Arbol a){
  if (a!=NULL) {
      int izq = altura(a->izq)+1;
      int der = altura(a->der)+1;
      if(izq > der)
          return izq;
        return der;
  }
    return -1;
}

int sumaNodos(Arbol a){
    if(a!=NULL){
        int centro = a->info;
      int izq = sumaNodos(a->izq);
      int der = sumaNodos(a->der);
      return centro + izq + der;
    }
    return 0;
}


int main(){
    int raiz = 0;
    cout<<"Inicializando arbol...\nValor contenido en la raiz: ";
    cin >> raiz;

    Arbol arbol = crearArbol(raiz);

    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar\n\t2) Recorrer"
            << "\n\t3) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: agregarNodo(arbol);
            break;
            case 2: recorrerArbol(arbol);
                cout<<"Nodos: "<<cont <<endl;
                cout<<"Altura: "<<altura(arbol) <<endl;
                cout<<"Suma de elementos: "<<sumaNodos(arbol) <<endl;

            break;
            case 3: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}
