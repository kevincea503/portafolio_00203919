// EJERCICIO DE IMPLEMENTACION DE PILAS CON EL EJERCICIO OBTENER EL ULTIMO ELEMENTO DE UNA PILA

#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo{
    float elemento;
    struct nodo *siguiente;
};
typedef struct nodo *Pila;

void initialize(Pila *s){
    *s = NULL;
}

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

float obtenerultimo(Pila *s){
    float a = 0;
	while(!empty(s)){
		a = pop(s);
		cout<<a<<endl; 
	}
	
	return a;
}

int main(){
    Pila unaPila;
    initialize(&unaPila);
    
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
    
   
     if(!empty(&unaPila)){
    float ultimo = obtenerultimo(&unaPila);
	cout << "El ultimo elemento es: " << ultimo << endl;
		
	}else{
	     cout << "Underflow!" << endl;
        return -1;
	
	}
    
    return 0;
}


