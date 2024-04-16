#include<iostream>
#include<windows.h>
#include<stdio.h>
#include<cstdlib>
#include<conio.h>
#include<stack>
#include <queue>
#include<locale.h>


void gotoxy(int x, int y)
{
	HANDLE hCon;
	COORD duPos;
	duPos.X=x;
	duPos.Y=y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon,duPos);
}
using namespace std;
//COLASSSSSS
struct Nodo {
    int dato;
    Nodo* siguiente;
};

struct Cola {
    Nodo* frente;
    Nodo* fin;
};

void inicializar(Cola& c) {
    c.frente = NULL;
    c.fin = NULL;
}

void insertar(Cola& c, int valor) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;
    if (c.frente == NULL) {
        c.frente = nuevoNodo;
        c.fin = nuevoNodo;
    } else {
        c.fin->siguiente = nuevoNodo;
        c.fin = nuevoNodo;
    }
    cout << "\nNúmero almacenado." << endl;
}

void quitar(Cola& c) {
    if (c.frente == NULL) {
    	cout << "\nNo hay numenos en la cola." << endl;
        return;
    } else {
        Nodo* temp = c.frente;
        c.frente = c.frente->siguiente;
        delete temp;
		cout << "\nNumero eliminado." << endl;

    }
}

void mostrar(Cola& c) {
    Nodo* actual = c.frente;
    if (c.frente == NULL) {
    	cout << "\nNo hay numenos en la cola." << endl;
        return;
    }
    while (actual != NULL) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}

struct nodo{
	int dato;
	nodo *der;
	nodo *izq;
	
};
//COLASSSSSS
//LISTA
// Definir la clase para el nodo
class Nodol {
public:
    int valor;
    Nodol* siguiente;
};

// Definir la clase para la lista
class Lista {
private:
    Nodol* cabeza;
public:
	
    // Constructor que inicializa la lista vacía
    Lista() {
        cabeza = NULL;
    }

    // Método para insertar un elemento al final de la lista
    void insertar(int val) {
        Nodol* nuevoNodo = new Nodol;
        nuevoNodo->valor = val;
        nuevoNodo->siguiente = NULL;

        if (cabeza == NULL) {
            cabeza = nuevoNodo;
        } else {
            Nodol* temp = cabeza;
            while (temp->siguiente != NULL) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoNodo;
        }
    }

    // Método para mostrar los elementos de la lista
    void mostrar() {
        if (cabeza == NULL) {
            cout << "La lista está vacía." << endl;
        } else {
            Nodol* temp = cabeza;
            while (temp != NULL) {
                cout << temp->valor << " ";
                temp = temp->siguiente;
            }
            cout << endl;
        }
    }
    void eliminar(int val) {
    if (cabeza == NULL) {
        cout << "La lista está vacía." << endl;
    } else if (cabeza->valor == val) {
        Nodol* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    } else {
        Nodol* temp = cabeza;
        while (temp->siguiente != NULL && temp->siguiente->valor != val) {
            temp = temp->siguiente;
        }
        if (temp->siguiente == NULL) {
            cout << "El elemento " << val << " no se encuentra en la lista." << endl;
        } else {
            Nodol* eliminarNodo = temp->siguiente;
            temp->siguiente = temp->siguiente->siguiente;
            delete eliminarNodo;
            cout << "El elemento " << val << " ha sido eliminado de la lista." << endl;
        }
    }
}

};

// Función para mostrar el menú
void mostrarMenu() {
    cout << "1. Insertar un elemento en la lista" << endl;
    cout << "2. Mostrar los elementos de la lista" << endl;
    cout << "3. Eliminar los elemento de la lista" << endl;
    cout << "4. Salir" << endl;
}
//LISTA
//ARBOL
void menu();
nodo *crearnodo(int);
void insertarnodo(nodo *&, int);
void mostrararbol(nodo *,int);
bool busqueda(nodo *,int);
void preorden(nodo *arbol);
void inorden(nodo *arbol);
void postorden(nodo *arbol);
void eliminarnodo(nodo *&arbol, int n);

nodo *arbol =NULL;





void menu(){
	int dato,opcion,contador=0;
		do{
		cout<<"\t ARBOL"<<endl;
		cout<<"1 insertar un nuevo nodo"<<endl;
		cout<<"2 mostrar el arbol "<<endl;
		cout<<"3 buscar numero"<<endl;
		cout<<"4 recorrer el arbol en preorden"<<endl;
		cout<<"5 recorrer el arbol en inorden"<<endl;
		cout<<"6 recorrer el arbol en postorden"<<endl;
		cout<<"7 eliminar nodo en el arbol"<<endl;
		cout<<"8 salir"<<endl;
		cout<<"opcion; ";
		cin>>opcion;
	
		
		switch(opcion){
			case 1: 
				cout<<"digite un numero "<<endl;
				cin>>dato;
				insertarnodo(arbol,dato);
				cout<<"\n";
				system("pause");
			break;
			case 2:
				cout<<"\nMostrando el arbol completo\n\n "<<endl;
				mostrararbol(arbol,contador);
				cout<<"\n";
				system("pause");
				break;
			case 3:
				cout<<"digite el elmento a buscar: "<<endl;
				cin>>dato;
				if(busqueda(arbol,dato)==true){
					cout<<"elemento "<<dato<<"a sido encontrado en el arbol ";
				}
				else{
					cout<<"elemento no encontrado"<<endl;
				}
				cout<<"\n";
				system("pause");
				break;
			case 4:
				cout<<"\n recorrido en preorden: ";
				preorden(arbol);
				cout<<"\n\n";
				system("pause");
				break;
			case 5:
				cout<<"\n recorrido en inorden: ";
				inorden(arbol);
				cout<<"\n\n";
				system("pause");
				break;
			case 6:
				cout<<"\n recorrido en postorden: ";
				postorden(arbol);
				cout<<"\n\n";
				system("pause");
				break;
			case 7:
				
				if (arbol==NULL){
					cout<<"no hay elementos";
					cout<<"\n\n";
					system("pause");
				}else{
				
					cout<<"\nDigite el valor del nodo a eliminar ";
					cin>>dato;
					eliminarnodo(arbol, dato);
					cout<<"\nSe elimina el numero "<<dato<<endl;
					cout<<"\n\n";
					system("pause");
				}
			}
			
			
			system("cls");
		}while(opcion !=8);
		
}


nodo *crearnodo(int n){
	nodo *nuevo_nodo =new nodo();
	
	nuevo_nodo->dato=n;
	nuevo_nodo->der=NULL;
	nuevo_nodo->izq=NULL;
	return nuevo_nodo;
}

void insertarnodo(nodo *&arbol, int n){
	if(arbol ==NULL){
		nodo *nuevo_nodo=crearnodo(n);
		arbol=nuevo_nodo;
		
	}else{
		int valoraiz=arbol->dato;
		
		if(n<valoraiz){
			insertarnodo(arbol->izq,n);
			
		}else{
			insertarnodo(arbol->der,n);
		}
	}
}


void mostrararbol(nodo *arbol,int cont){
	if(arbol==NULL){
		return;
	}else{
		mostrararbol(arbol->der,cont+1);
		for(int i=0;i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrararbol(arbol->izq,cont+1);
		
	}
}

bool busqueda(nodo *arbol,int n){
	if(arbol ==NULL){
		return false;
	}
	else if(arbol->dato==n){
		return true;
	}
	else if(n<arbol->dato){
		return busqueda(arbol->izq,n);
		
	}
	else{
		return busqueda(arbol->der,n);
	}
}

void preorden(nodo *arbol){
	if(arbol ==NULL){
		return;
		
	}else{
		cout<<arbol->dato<<" - ";
		preorden(arbol->izq);
		preorden(arbol->der);
		
	}
}
void inorden(nodo *arbol){
	if(arbol==NULL){
		return;
	}
	else{
		inorden(arbol->izq);
		cout<<arbol->dato<<" - ";
		inorden(arbol->der);
		
	}
}
void postorden(nodo *arbol){
	if(arbol==NULL){
		return;
	}
	else{
		postorden(arbol->izq);
		postorden(arbol->der);
		cout<<arbol->dato<<" - ";
		
	}
}
void eliminarnodo(nodo *&arbol, int n){
	
	if(arbol==NULL){
		return;
	}else if(n<arbol->dato){
		eliminarnodo(arbol->izq,n);
	}else if(n>arbol->dato){
		eliminarnodo(arbol->der,n);
	}else{
		// caso en que se encontró el nodo a eliminar
		if(arbol->izq==NULL && arbol->der==NULL){
			delete arbol;
			arbol=NULL;
			
		}else if(arbol->izq!=NULL && arbol->der==NULL){
			
			nodo *temp=arbol;
			arbol=arbol->izq;
			delete temp;
			
		}else if(arbol->izq==NULL && arbol->der!=NULL){
			nodo *temp=arbol;
			arbol=arbol->der;
			delete temp;
			
		}else{
			
			nodo *temp=arbol->der;
			while(temp->izq!=NULL){
				temp=temp->izq;
			}
			
			arbol->dato=temp->dato;
			eliminarnodo(arbol->der,temp->dato);
		}
	}	
}
//ARBOLLL

stack <int> pila;

int main(){
	
	system("color 9f");
	
	setlocale(LC_ALL, "");
	
	Lista miLista;
   
    Cola c;
    inicializar(c);
    
    int opcion = 0,opcionesmax ;
    int a,b,h,i;
    i=1;
    
    	cout << "Menú:" << endl;
        cout << "1. Pilas" << endl;
        cout << "2. Colas" << endl;
        cout << "3. Listas" << endl;
        cout << "4. Arbol" << endl;
        cin >> opcionesmax;
        
        system("cls");
    
    
    
    switch(opcionesmax){
    	
    	case 1:
    		
    		while(i=1){
    		cout<<"PILAS\n1 ingrese numero \n2 valor de la pila\n3 vaciar pila\n4 salir"<<endl;
			cin>>a;
	 
			switch(a){
				case 1:
	 		
	 				cout<<"Ingrese un numero"<<endl;
	 				cin>>h;
	 				pila.push(h);
	 	
	 				break;
				case 2:
				
	 				cout<<"Se cargo "<<pila.top()<<endl;
	 				i=0;
	 				break;
		 		
			 	case 3:
	 		
	 				pila.pop();
	 				cout<<"Pila vaciada"<<endl;
	 				pila.push(0);
			 		break;
	 		
				case 4:
			
	 				cout<<"SEGURO? \n1 Si\n2 No "<<endl;
	 				cin>>b;
	 		
	 				if(b==1){
	 					return 0;
					}else{
						if(b==2){
					system("cls");
					return main();
				
						}
					}
					
					}
					system("pause");system("cls");
    				
    			}
    	case 2:
    		
		    do {
		        cout << "COLAS:" << endl;
		        cout << "1. Agregar dato" << endl;
		        cout << "2. Remover dato" << endl;
		        cout << "3. Mostrar datos" << endl;
		        cout << "4. Salir" << endl;
		        cout << "Ingresa tu opción: ";
		        cin >> opcion;
		        
		        system("cls");
		        
		        switch(opcion) {
		            case 1:
		                int valor;
		                cout << "Ingresa el valor : ";
		                cin >> valor;
		                insertar(c, valor);
		                break;
		            case 2:
		                quitar(c);
		                break;
		            case 3:
		                mostrar(c);
		                break;
		            case 4:
		                cout << "Adios" << endl;
		                break;
		            default:
		                cout << "Dato erroneo." << endl;
		                break;
		        }
				 system("pause");system("cls");
		
		    } while (opcion != 4);
    		
    		break;
    	case 3:
		    do {
		        mostrarMenu();
		        cout << "Seleccione una opción: ";
		        cin >> opcion;
		
		        switch (opcion) {
		            case 1:
		                int num;
		                cout << "Ingrese el número a agregar a la lista: ";
		                cin >> num;
		                miLista.insertar(num);
		                system("cls");
		                break;
		            case 2:
		                miLista.mostrar();
		                system("pause");system("cls");
		                break;
		            case 3:
					    int numEliminar;
					    cout << "Ingrese el número a eliminar de la lista: ";
					    cin >> numEliminar;
					    miLista.eliminar(numEliminar);
					    system("pause");system("cls");
		
		            case 4:
		                cout << "Saliendo del programa..." << endl;
		                break;
		            
					    break;
		            default:
		                cout << "Opción no válida. Intente de nuevo"<<endl;
						system("pause");system("cls");
		
		                break;
		    		}
			}while(opcion !=4 );
	
    		break;
    	case 4:
    	
    		menu();
    		break;
    		
    
    		
    			
    			
    			
	}
    
    
	
	
	getch;
	return 0;
}


