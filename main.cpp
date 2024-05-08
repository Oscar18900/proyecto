#include<iostream>
#include <limits>
#include <algorithm>
using namespace std;
class Persona{
private:
	int id;
	string nombre;
	string apellidoPaterno;
	string apellidoMaterno;
	string sexo;
	int edad;
	string direccion;
	int telefono;
	string puesto;
	string departamento;
	int horasTrabajadas;
	double costoPorHora;
	double sueldo;
public:
	Persona() : id(0), nombre(""), apellidoPaterno(""),
	apellidoMaterno(""), sexo(""), edad(0), direccion(""), telefono(0),
	puesto(""), departamento(""), horasTrabajadas(0), costoPorHora(0),
	sueldo(0) {}
	
	
	Persona(int _id,string _nombre,string _apellidoPaterno,string _apellidoMaterno,
	string _sexo,int _edad,string _direccion,int _telefono,string _puesto,string _departamento,
	int _horasTrabajadas,double _costoPorHora,double _sueldo):id(_id), nombre(_nombre), apellidoPaterno(_apellidoPaterno),
	apellidoMaterno(_apellidoMaterno), sexo(_sexo), edad(_edad), direccion(_direccion), telefono(_telefono),
	puesto(_puesto), departamento(_departamento), horasTrabajadas(_horasTrabajadas), costoPorHora(_costoPorHora),
	sueldo(_horasTrabajadas * _costoPorHora) {}
	
	void setdatos(int _id,string _nombre,string _apellidoPaterno,string _apellidoMaterno,
	string _sexo,int _edad,string _direccion,int _telefono,string _puesto,string _departamento,
	int _horasTrabajadas,double _costoPorHora,double _sueldo)
	{
	id = _id;
	nombre = _nombre;
	apellidoPaterno = _apellidoPaterno;
	apellidoMaterno = _apellidoMaterno;
	sexo = _sexo;
	edad = _edad;
	direccion = _direccion;
	telefono = _telefono;
	puesto = _puesto;
	departamento = _departamento;
	horasTrabajadas = _horasTrabajadas;
	costoPorHora = _costoPorHora;
	sueldo = _horasTrabajadas * _costoPorHora;
	}
	
	int get_id(){
		return id;
	}
	
	string getNombre(){
		return nombre;
	}
	
	string getApellidoPaterno(){
		return apellidoPaterno;
	}
	
	string getApellidoMaterno(){
		return apellidoMaterno;
	}
	
	string getSexo(){
		return sexo;
	}
	
	int getEdad(){
		return edad;
	}
	
	string getDireccion(){
		return direccion;
	}
	
	int getTelefono(){
		return telefono;
	}
	
	string getPuesto(){
		return puesto;
	}
	
	string getDepartamento(){
		return departamento;
	}
	
	int getHorasTrabajadas(){
		return horasTrabajadas;
	}
	
	double getCostoPorHora(){
		return costoPorHora;
	}
	
	double getSueldo(){
		return sueldo;
	}
	
};
struct Nodo{
	Persona persona;
	Nodo* siguiente;
	Nodo(Persona _persona) : persona(_persona), siguiente(nullptr) {}

};
//prototipado de funcines
void agregar(Nodo *&, Persona);
void imprimirLista(Nodo *);
void eliminar(Nodo *&, int);
bool validacionString(const string &str);

int main(){
	string nombre, apellidoPaterno, apellidoMaterno, sexo, direccion,  puesto, departamento;
	int id,  edad, horasTrabajadas,telefono;
	double costoPorHora;
	Persona persona;
	Nodo *lista=NULL;
	int opc;
	do{
		cout<<"---------¿Qué deseas realizar?-------------"<<endl;
		cout<<"1.-Dar de alta a un empleado"<<endl;
		cout<<"2.-Mostrar nomina de empleado"<<endl;
		cout<<"3.-Dar de baja a un empleado"<<endl;
		cout<<"4.-Realizar cambios en la nomina"<<endl;
		cout<<"5.-Consultar informacion de un empleado"<<endl;
		cout<<"6.-Salir"<<endl;
		cin>>opc;
		
		switch(opc){
		
			case 1:
				cin.ignore(); 
				cout << "Ingrese el ID del trabajador (6 caracteres): ";
				while (!(cin >> id) || cin.peek() != '\n' || to_string(id).length() != 6) {
        			cout << "El ID del trabajador debe ser un número entero de 6 dígitos. Inténtalo de nuevo: ";
        			cin.clear();
        			cin.ignore();
    			}
    			cin.ignore();
    			do{
				cout << "Ingrese el nombre del trabajador: ";
                getline(cin, nombre);
                	if (!nombre.empty() && validacionString(nombre)) {
                    		break; 
                	} else {
                    	cout << "Ingrese un apellido válido (solo letras, no vacío): ";
                	}
            	}while(nombre.empty() || !validacionString(nombre));
           		cin.ignore();
                do{
					cout << "Ingrese el apellido paterno del trabajador: ";
                	getline(cin, apellidoPaterno);
                	if (!apellidoPaterno.empty() && validacionString(apellidoPaterno)) {
                    		break; 
                	} else {
                    	cout << "Ingrese un apellido válido (solo letras, no vacío): ";
                	}
            	}while(apellidoPaterno.empty() || !validacionString(apellidoPaterno));
            	cin.ignore();
            	do{
					cout << "Ingrese el apellido materno del trabajador: ";
					getline(cin,apellidoMaterno);
					if (!apellidoMaterno.empty() && validacionString(apellidoMaterno)) {
                    		break; 
                	} else {
                    	cout << "Ingrese un apellido válido (solo letras, no vacío): ";
                	}
            	}while(apellidoMaterno.empty() || !validacionString(apellidoMaterno));
            	cin.ignore();
				do{
					cout << "Ingrese el sexo del trabajador (M o F): ";
					cin >> sexo;
                	if (sexo!="M"&&sexo!="F"){
                    cout<<"caracter incorrecto"<<endl;
               		}
                }while(sexo!="M"&&sexo!="F");
                cin.ignore();
				cout<< "Ingrese la edad del trabajador: ";
				while (!(cin >> edad) || cin.peek() != '\n' || to_string(edad).length() != 2) {
				    cout << "Ingrese su edad con el formato 00: ";
		    		cin.clear();		        	
					cin.ignore();
				}                
				cin.ignore(); 
				cout << "Ingrese la dirección del trabajador: ";
				getline(cin, direccion);
				cout << "Ingrese el teléfono del trabajador: ";
				while (!(cin >> telefono) || cin.peek() != '\n') {
				    cout << "Ingrese valores numericos: ";
		    		cin.clear();		        	
					cin.ignore();
				}
				cin.ignore();
				do{
				 cout<< "Ingrese el puesto del trabajador: ";
				 getline(cin,puesto);
					if (!puesto.empty() && validacionString(puesto)) {
                    		break; 
                	} else {
                    	cout << "Ingrese un apellido válido (solo letras, no vacío): ";
                	}
            	}while(puesto.empty() || !validacionString(puesto));
            	cin.ignore();
            	do{
				cout << "Ingrese el departamento del trabajador: ";
				getline(cin,departamento);
					if (!departamento.empty() && validacionString(departamento)) {
                    		break; 
                	} else {
                    	cout << "Ingrese un apellido válido (solo letras, no vacío): ";
                	}
            	}while(departamento.empty() || !validacionString(departamento));
            	cin.ignore();
				cout << "Ingrese las horas trabajadas por el trabajador: ";
				while (!(cin >> horasTrabajadas) || cin.peek() != '\n') {
				    cout << "Ingrese valores numericos: ";
		    		cin.clear();		        	
					cin.ignore();
				}
				cin.ignore();
				cout << "Ingrese el costo por hora del trabajador: ";
				 while (!(cin >> costoPorHora) || cin.peek() != '\n') {
				    cout << "Ingrese valores numericos: ";
		    		cin.clear();		        	
					cin.ignore();
				}
                
				persona.setdatos(id, nombre, apellidoPaterno, apellidoMaterno, sexo, edad, direccion, telefono, puesto, departamento, horasTrabajadas, costoPorHora, horasTrabajadas * costoPorHora);
				agregar(lista, persona);
			break;
			case 2:
				imprimirLista(lista);
				system("pause");

			break;
			case 3:
				cout << "Ingrese el ID del empleado que desea dar de baja\n";
				cin >> id;
				eliminar(lista, id);
			break;
            		case 6:
				cout << "Adios...\n";
				system("pause");
			break;
			default: 
				cout << "Opcion no valida\n";
				system("pause");
			break;
			
		}
		system("cls");
	}while(opc != 6);
	return 0;
}

void agregar(Nodo *&lista, Persona persona) {
    Nodo *nuevo_nodo = new Nodo(persona);
    nuevo_nodo->siguiente = NULL;

    if (lista == nullptr) {
        lista = nuevo_nodo;
    } else if (nuevo_nodo->persona.getNombre() < lista->persona.getNombre()) {
        nuevo_nodo->siguiente = lista;
        lista = nuevo_nodo;
    } else {
        Nodo *actual = lista;
        Nodo *anterior = NULL;
        while (actual != NULL && persona.getNombre() > actual->persona.getNombre()) {
            anterior = actual;
            actual = actual->siguiente;
        }
        nuevo_nodo->siguiente = actual;
        anterior->siguiente = nuevo_nodo;
    }
}

void imprimirLista(Nodo *lista) {
    Nodo *actual = lista;
	if(actual == NULL){
		cout << "No existen registros\n";
	}
	else{		
		while (actual != NULL) {
		cout << "ID Trabajador: " << actual->persona.get_id() << endl;
		cout << "Nombre: " << actual->persona.getNombre() << endl;
		cout << "Apellido Paterno: " << actual->persona.getApellidoPaterno() << endl;
		cout << "Apellido Materno: " << actual->persona.getApellidoMaterno() << endl;
		cout << "Sexo: " << actual->persona.getSexo() << endl;
		cout << "Edad: " << actual->persona.getEdad() << endl;
		cout << "Dirección: " << actual->persona.getDireccion() << endl;
		cout << "Teléfono: " << actual->persona.getTelefono() << endl;
		cout << "Puesto: " << actual->persona.getPuesto() << endl;
		cout << "Departamento: " << actual->persona.getDepartamento() << endl;
		cout << "Horas Trabajadas: " << actual->persona.getHorasTrabajadas() << endl;
		cout << "Costo por Hora: " << actual->persona.getCostoPorHora() << endl;
		cout << "Sueldo: " << actual->persona.getSueldo() << endl;
		cout << "-----------------------------------" << endl;
		actual = actual->siguiente;
		}
	}
}

void eliminar(Nodo *&lista, int ID){
	if(lista != NULL){
		Nodo *aux_borrar;
		Nodo *anterior = NULL;
		aux_borrar = lista;
		    
		while(aux_borrar != NULL && aux_borrar->persona.get_id() != ID)
		{
		    anterior = aux_borrar;
		    aux_borrar = aux_borrar->siguiente;
		}
		if(aux_borrar == NULL){
		    cout << "Esta persona no existe\n";
		}
			
		else if(anterior == NULL){
		    lista = aux_borrar->siguiente;
		    delete aux_borrar;
		}
		else{
		    anterior->siguiente = aux_borrar->siguiente;
		    delete aux_borrar;
		}
	}
	else{
		cout << "No existen registros\n";
	}
}
void agregar(Nodo *&lista, Persona persona) {
    Nodo *nuevo_nodo = new Nodo(persona);
    nuevo_nodo->siguiente = NULL;

    if (lista == nullptr) {
        lista = nuevo_nodo;
    } else if (nuevo_nodo->persona.getNombre() < lista->persona.getNombre()) {
        nuevo_nodo->siguiente = lista;
        lista = nuevo_nodo;
    } else {
        Nodo *actual = lista;
        Nodo *anterior = NULL;
        while (actual != NULL && persona.getNombre() > actual->persona.getNombre()) {
            anterior = actual;
            actual = actual->siguiente;
        }
        nuevo_nodo->siguiente = actual;
        anterior->siguiente = nuevo_nodo;
    }
}

void imprimirLista(Nodo *lista) {
    Nodo *actual = lista;
	if(actual == NULL){
		cout << "No existen registros\n";
	}
	else{		
		while (actual != NULL) {
		cout << "ID Trabajador: " << actual->persona.getID_Trabajador() << endl;
		cout << "Nombre: " << actual->persona.getNombre() << endl;
		cout << "Apellido Paterno: " << actual->persona.getApellidoPaterno() << endl;
		cout << "Apellido Materno: " << actual->persona.getApellidoMaterno() << endl;
		cout << "Sexo: " << actual->persona.getSexo() << endl;
		cout << "Edad: " << actual->persona.getEdad() << endl;
		cout << "Dirección: " << actual->persona.getDireccion() << endl;
		cout << "Teléfono: " << actual->persona.getTelefono() << endl;
		cout << "Puesto: " << actual->persona.getPuesto() << endl;
		cout << "Departamento: " << actual->persona.getDepartamento() << endl;
		cout << "Horas Trabajadas: " << actual->persona.getHorasTrabajadas() << endl;
		cout << "Costo por Hora: " << actual->persona.getCostoPorHora() << endl;
		cout << "Sueldo: " << actual->persona.getSueldo() << endl;
		cout << "-----------------------------------" << endl;
		actual = actual->siguiente;
		}
	}
}

void eliminar(Nodo *&lista, int ID){
	if(lista != NULL){
		Nodo *aux_borrar;
		Nodo *anterior = NULL;
		aux_borrar = lista;
		    
		while(aux_borrar != NULL && aux_borrar->persona.getID_Trabajador() != ID)
		{
		    anterior = aux_borrar;
		    aux_borrar = aux_borrar->siguiente;
		}
		if(aux_borrar == NULL){
		    cout << "Esta persona no existe\n";
		}
			
		else if(anterior == NULL){
		    lista = aux_borrar->siguiente;
		    delete aux_borrar;
		}
		else{
		    anterior->siguiente = aux_borrar->siguiente;
		    delete aux_borrar;
		}
	}
	else{
		cout << "No existen registros\n";
	}
}
bool validacionString(const string &str) {
    for (char c : str) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}
