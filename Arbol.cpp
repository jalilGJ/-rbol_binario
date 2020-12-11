#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo{
	int dato; // se declara variable
	Nodo *derecho; // este funcion nos indica la direccion o hubicasion de los datos a insertar
	Nodo *izquierdo;	// este funcion nos indica la direccion o hubicasion de los datos a insertar
};

// menu
void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&,int);
void mostrarArbol(Nodo *,int);// parametros  para el arbol y para el contador
bool busqueda(Nodo *,int); // busqueda
void preOrden(Nodo *); // de tipo puntero

Nodo *arbol = NULL;

int main() { // el inicio de la ejecucion 
	menu();
	
	getch(); // nos permitira guardar un valor en una variable 
	return 0;
}

//metodo para crear un nuevo nodo
Nodo *crearNodo(int n){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->derecho = NULL;
	nuevo_nodo->izquierdo= NULL;
	
	return nuevo_nodo;
}
//metodo para insertar elementos en el arbol
void insertarNodo(Nodo *&arbol,int n){
	if(arbol == NULL){ // comparacion para saber si el arbol esta vacio
		Nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;	
	}
	else{// de lo contrario para saber si el arbol tiene un nodo o mas
	    int valorRaiz = arbol->dato;// obtener el valor de la raiz
	    if(n < valorRaiz){// si el elemento es menor a la raiz, insertamos en izquierda
		    insertarNodo(arbol->izquierdo,n);    
		}
		else{// si no, si el elemento es mayor a la raiz,insertamos en derecha
		    insertarNodo(arbol->derecho,n);
		}
	}

}
//metodo para mostrar el arbol completo
void mostrarArbol(Nodo *arbol,int cont){
	if(arbol == NULL){// si el arbol se encuentra vacio
		return;
	}  
	else{// si no, nos immprimira los datos que contiene el arbol
	    mostrarArbol(arbol->derecho,cont+1); //  nos sirve para imprimir todos los datos del arbol 
	    for(int i=0;i<cont;i++){// utilizamos un bucle desde que cero hasta que sea menor a contaador
		    cout<<"   " ;// espacio para separar los datos del arbol
	   }
	   cout<<arbol->dato<<endl;// se imprime todos del lado derecho
    	mostrarArbol(arbol->izquierdo,cont+1);
   }

}
//metodo pra buscar un elemento en el arbol
bool busqueda (Nodo *arbol,int n){
	if(arbol == NULL){//si se encuentra vacio
	   return false;	
	}
	else if(arbol->dato == n){// si no encuentra el elmento en el arbol entonces accedera otro 
	    return true;
	}
	else if(n < arbol->dato){ //otra error que se puede presentar
	    return busqueda(arbol->izquierdo,n);	
	}  
	   
    else{
	    return busqueda(arbol->derecho,n);
	   	
	} 
 }
// metodo para recorrer el arbol en preorden
void preOrden(Nodo *arbol){
	if(arbol == NULL){ // si la lista esta vacia 
		return;
	}
	else{// 
		cout<<arbol->dato<<" - "; // se imprime la raiz 
		preOrden(arbol->izquierdo); // se llama de nuevo la funcion preorden pra recorrer el lado izquierdo del arbol
		preOrden(arbol->derecho);
	}
}	         


//menu de opciones 
void menu(){
	int dato,opcion,contador=0;
	
	do{
	    cout<<"\t ESTRUTURA DE DATO NO LINEAL: ARBOL BINARIO."<<endl;
		cout<<"1. Insertar un nuevo nodo"<<endl;
		cout<<"2. Mostar el arbol completo"<<endl;
		cout<<"3. Buscar un elemento en el arbol"<<endl;
		cout<<"4. Recorrer el arbol en preorden"<<endl;
		cout<<"5. Salir"<<endl;
		cout <<"opcion: ";
		
		cin>>opcion;
		
	    switch(opcion){
			case 1: 
			        cout<<"\nIngrese un numero: ";//insertar nodo
			        cin>>dato;
			        insertarNodo(arbol,dato);
			        cout<<"\n"; 
			        system("pause");
			        break;
			case 2: 
			        cout<<"\naArbol completo:\n\n";//mostrar el arbol completo
			        mostrarArbol(arbol,contador);
			        cout<<"\n"; 
			        system ("pause");
			        break;
			case 3: 
	                cout<<"\nIngrese el elemento a busacr en el arbol: "; //buscar un elemento en el arbol
			        cin>>dato;
			        if(busqueda(arbol,dato) == true){
			        	cout<<"\nElemento "<<dato<<" a sido encontrado en el arbol\n";
					}
					else{
						cout<<"\nElemento no encontrado\n";
							
					}
					cout<<"\n";
					system ("pause");
					break;
			case 4:
			    	cout<<"\nRecorrido en preorden: ";	//recorrer el arbol en preorden
			        preOrden(arbol);
			        cout<<"\n\n";
			        system("pause");
			        break;
			case 5: //salir del programa
			        cout<<"salir"<<endl;
			        break;
				       
		       
		}
		system("cls");
	}while(opcion != 5);
}	   


