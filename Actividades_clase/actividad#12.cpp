

#include <iostream>
#include <string>
using namespace std;

struct pupusas{
    int revueltas;
    int frijolConQueso;
    int queso;
    bool arroz;
};
typedef struct pupusas orden;

orden solicitarOrden(){
    orden p;
    int op;
    cout << "revueltas: "; cin >> p.revueltas;
    cout << "frijol con queso: ";   cin >> p.frijolConQueso;
    cout << "queso: "; cin >> p.queso;
    cout << "de arroz o de maiz? 1/2";
    cin >> op;
    p.arroz = (op == 1? true : false );
        
    return p;
}

void mostrarOrden(orden p){
    cout << "revueltas: "<< p.revueltas<<endl;
    cout << "frijol con queso: "<< p.frijolConQueso<<endl;
    cout << "queso: "<<p.queso<<endl;
    cout <<"Total: "<<p.revueltas + p.frijolConQueso + p.queso<<" pupusas"<< endl;
    if(p.arroz == true){
        cout<<"todas de arroz"<<endl;
    }else{
        cout<<"todas de maiz"<<endl;
    }
    cout<<endl;
}

struct TNodo{
    orden dato;
    struct TNodo *sig;
};
typedef struct TNodo Nodo;
Nodo *pInicio;  // variable global

void insertarInicio(orden p) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = pInicio;  
    
    pInicio = nuevo; // ingreso un nuevo inicio
}

void insertarFinal(orden p) { // le recibo el elemento a insertar
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = NULL;
    
    if (pInicio == NULL) { // caso 1: lista vacia
        pInicio = nuevo;   // 
    } else {
        Nodo *p = pInicio;  
        Nodo *q = NULL;
        while (p != NULL) {
            q = p;   // q apunta a lo que esta apuntando p (direcciones)
            p = p->sig;    // p sera el valor del nodo siguiente
        }
        q->sig = nuevo;   // el puntero que ahora esta apuntando a null ya que lo recorri, ahora me apuntara al nuevo nodo que acabo de insertar;
    }
}

void agregarOrden(){
    orden p = solicitarOrden();
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\t1) Al principio\n\t2) Al final"
            << "\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: insertarInicio(p);
                continuar = false;
            break;
            case 2: insertarFinal(p);
                continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
}

void mostrarLista() {
    Nodo *s = pInicio;

    while (s != NULL) {
        mostrarOrden(s->dato);
        s = s->sig;
    }
}

int main(){
    cout << "Inicializando..." << endl;
    pInicio = NULL;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar orden\n\t2) Ver ordenes"
            << "\n\t3) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: cout << "Agregando..." << endl;
                agregarOrden();
            break;
            case 2: cout << "Listando..." << endl;
                mostrarLista();
            break;
            case 3: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}

