
#include <iostream>
#include<stdio.h>
#define true 1;
#define false 0
#define max 3
using namespace std;

typedef struct {
    int inicio;
    int final;
    int vector[max];
} queue;


void intialize(queue *cola){
    cola->inicio = -1;
    cola->final = -1;
}

bool empty(queue *cola){
    if(cola->final == -1){
        return true;
    }else{
        return false;
    }
}

int elementos(queue *cola){
    if(empty(cola)){
        return 0;
    }else{
        if(cola->inicio <= cola->final){
            return cola->final - cola->inicio +1;
        }else{
            return max- cola->inicio + cola->final +1;
        }
    }
}

int llena(queue *cola){
    if(elementos(cola) == max){
        return true;
    }else{
        return false;
    }
}



void agregar(queue * cola, int e){
    if(!llena(cola)){
        if(empty(cola))
        cola->inicio = 0;
    
    if(cola->final == max-1){
        cola->final = 0;
    }else{
         cola->final ++;
    }
    
    cola->vector[ cola->final] = e;
    cout<<"posicion incial: "<<cola->inicio<<endl;
  
    cout<<"se añadio: "<<cola->vector[ cola->final]<<" en la posicion ["<<cola->final<<"]"<<endl;
    
   }
   else{
    cout<<"Esta llena"<<endl;
        }
} 


void borrar(queue *cola){
    if(!empty(cola)){
        int tmp = cola->vector[ cola->inicio];
        if(elementos(cola)==1){
            intialize(cola);
        }else{
            cola->inicio ++;
        }
        cout<<"Eliminando:"<<tmp<<endl;   
     cout<<"Nuevo inicio de la cola ["<<cola->inicio<<"]"<<" con valor: "<<cola->vector[ cola->inicio] <<" y final ["<<cola->final<<"]"<<endl;   
        
    }
    
    else{
        cout<<"UNDERFLOW!:Esta vacia"<<endl;
    }
    
}


int main()
{
    queue cola;
    intialize(&cola);
    
    agregar(&cola, 5);
    cout<<endl;
    agregar(&cola, 10);
     cout<<endl;
    agregar(&cola, 1);
     cout<<endl;
    borrar(&cola);
    borrar(&cola);    
   agregar(&cola, 20);   
    cout<<endl;
    agregar(&cola, 25);   
    
    cout<<"El elemento inicial de la cola es: "<< cola.vector[ cola.inicio] <<" y el final es: "<< cola.vector[ cola.final] <<endl;
    
    return 0;
}

