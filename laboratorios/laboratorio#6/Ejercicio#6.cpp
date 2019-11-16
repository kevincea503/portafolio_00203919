
/*EL EJERCICIO NO PIDE IMPRIMIR LA LISTA ANTES DE INTERCAMBIAR POR LO QUE DECIDI USAR UNA PILA*/

#include <iostream>
using namespace std;

//Creacion de la estructura pila
struct nodo{
    float elemento;
    struct nodo *siguiente;
};
typedef struct nodo *Pila;

bool empty(Pila *s){
    return *s == NULL;
}

void push(Pila *s, float e){
    struct nodo *unNodo;
    unNodo = (struct nodo *)malloc(sizeof(struct nodo));
    unNodo->elemento = e;
    unNodo->siguiente = *s;
    *s =    unNodo;   
}

float pop(Pila *s){
        struct nodo *unNodo = *s;
        float e = (*s)->elemento;
        *s = (*s)->siguiente;
        delete(unNodo);
        
        return e;
}


//------ Creacion de nodo y de arbol ------
struct Tnodo{
    int info;
    struct Tnodo *izq;
    struct Tnodo *der;
};
typedef struct Tnodo Nodo;
typedef struct Tnodo *Arbol;

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

void agregarNodo(float dato, Arbol a){   // <----------------

    Arbol p = a;

    //desplazarse hasta el lugar adecuado
    while(true){
        if(dato == p->info){
            cout << "Error: " << dato << " ya existe" << endl;
            return;
        }
        else if(dato < p->info){//ir a la izquierda
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
    if(dato < p->info)
        asignarIzq(p, dato);
    else
        asignarDer(p, dato);
}


void Intercambio(Pila *s, Arbol a){
    cout << "Intercambiando elementos... "<<endl;
    float dato = 0;
	while(!empty(s)){
		dato = pop(s);
    	agregarNodo(dato, a);
	}
}



//------ Recorrer un arbol  ------

void inorden(Arbol a){
    if(a != NULL){
        inorden(a->izq);
        cout << " " << a->info;
        inorden(a->der);
    }
    
}

void recorrerArbol(Arbol a){
    cout << "Mostrando elementos desde el arbol... "<<endl;
    cout << "Recorrido IN orden:"; inorden(a); cout <<endl;

}


int main(){
     Pila unaPila = NULL;

cout << "-- Agregando elementos a la lista -- "<<endl;
  bool continuar = true;
    do{
        cout << "Desea agregar un elemento? (y/n) ";
        char opcion = 'y';
        cin >> opcion;
        if(opcion=='y'){
            cout << "Elemento: ";
            int x = 0;
            cin >> x;
            push(&unaPila, x);
        }
        else
            continuar = false;
    }while(continuar);
    
    float raiz = pop(&unaPila);
    Arbol arbol = crearArbol(raiz);
    Intercambio(&unaPila, arbol);
    recorrerArbol(arbol);
    
    return 0;
}
