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
//------ Recorrer un arbol (in, pre y post orden) ------

void inorden(Arbol a){
    if(a != NULL){
        inorden(a->izq);
        cout << " " << a->info;
        inorden(a->der);
    }
    
}

void recorrerArbol(Arbol a){
    cout << "Recorrido IN orden:"; inorden(a); cout <<endl;

}


int cont = 0, cont2 = 0;
int acumpar = 0, acumipar=0;

void ContadorNodos(Arbol a){
    if(a != NULL){
        if(a->info%2==0){
            cont ++;
            acumpar+= a->info;
        }
        else {
            cont2++;
            acumipar+= a->info;
        }
        ContadorNodos(a->izq);
      //  cout << " " << a->info;
        ContadorNodos(a->der);
    }
    
}

    int ContadorCero = 0, contadorMaycero = 0, contadorMencero=0;

void LiteralD(Arbol a){
    if(a != NULL){
        if(a->info==0){
            ContadorCero ++;
        }
        else {
            if(a->info>0)
            contadorMaycero++;
            
            else {
            contadorMencero++;
                
            }
        }
        LiteralD(a->izq);
      //  cout << " " << a->info;
        LiteralD(a->der);
    }
    
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
                ContadorNodos(arbol); cout<<endl;
                cout<<"cantidad de Nodos pares: "<<cont<<endl;
                cout<<"cantidad de Nodos impares: "<<cont2 <<endl;
                cout<<"Suma de Nodos pares: "<<acumpar<<endl;
                cout<<"Suma de Nodos impares: "<<acumipar <<endl; LiteralD(arbol);cout<<endl;
                cout<<"cantidad de nodos negativos "<<contadorMencero <<endl;
                cout<<"cantidad de nodos con el valor cero "<<ContadorCero <<endl;
                cout<<"cantidad de nodos positivos "<<contadorMaycero <<endl;

            break;
            case 3: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}
