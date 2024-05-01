#include<iostream>
using namespace std;
class Persona{
	private:
		string ID_Trabajador;
	    string nombre;
	    string apellidoPaterno;
	    string apellidoMaterno;
	    string sexo;
	    int edad;
	    string direccion;
	    string telefono;
	    string puesto;
	    string departamento;
	    int horasTrabajadas;
	    double costoPorHora;
	    double sueldo;
	public:
		Persona(string _ID_Trabajador,string _nombre,string _apellidoPaterno,string _apellidoMaterno,
		string _sexo,int _edad,string _direccion,string _telefono,string _puesto,string _departamento,
		int _horasTrabajadas,double _costoPorHora,double _sueldo):ID_Trabajador(_ID_Trabajador), nombre(_nombre), apellidoPaterno(_apellidoPaterno),
        apellidoMaterno(_apellidoMaterno), sexo(_sexo), edad(_edad), direccion(_direccion), telefono(_telefono),
        puesto(_puesto), departamento(_departamento), horasTrabajadas(_horasTrabajadas), costoPorHora(_costoPorHora),
        sueldo(_horasTrabajadas * _costoPorHora) {}
          
       string getID_Trabajador() const {
    return ID_Trabajador;
}

string getNombre() const {
    return nombre;
}

string getApellidoPaterno() const {
    return apellidoPaterno;
}

string getApellidoMaterno() const {
    return apellidoMaterno;
}

string getSexo() const {
    return sexo;
}

int getEdad() const {
    return edad;
}

string getDireccion() const {
    return direccion;
}

string getTelefono() const {
    return telefono;
}

string getPuesto() const {
    return puesto;
}

string getDepartamento() const {
    return departamento;
}

int getHorasTrabajadas() const {
    return horasTrabajadas;
}

double getCostoPorHora() const {
    return costoPorHora;
}

double getSueldo() const {
    return sueldo;
}
        
};
struct Nodo{
	Persona persona;
    Nodo* siguiente;
    Nodo(Persona _persona) : persona(_persona), siguiente(nullptr) {}

};

void agregar(Nodo *&, Persona);
void imprimirLista(Nodo *);


int main(){
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
				string ID_Trabajador, nombre, apellidoPaterno, apellidoMaterno, sexo, direccion, telefono, puesto, departamento;
			    int edad, horasTrabajadas;
			    double costoPorHora;
			    cin.ignore(); 
			    cout << "Ingrese el ID del trabajador (6 caracteres): ";
			    cin >> ID_Trabajador;
			    cin.ignore(); 
			    cout << "Ingrese el nombre del trabajador: ";
			    getline(cin, nombre);
			    cout << "Ingrese el apellido paterno del trabajador: ";
			    getline(cin, apellidoPaterno);
			    cout << "Ingrese el apellido materno del trabajador: ";
			    getline(cin, apellidoMaterno);
			    cout << "Ingrese el sexo del trabajador: ";
			    cin >> sexo;
			    cout << "Ingrese la edad del trabajador: ";
			    cin >> edad;
			    cin.ignore(); // Ignora el salto de línea pendiente en el buffer
			    cout << "Ingrese la dirección del trabajador: ";
			    getline(cin, direccion);
			    cout << "Ingrese el teléfono del trabajador: ";
			    getline(cin, telefono);
			    cout << "Ingrese el puesto del trabajador: ";
			    getline(cin, puesto);
			    cout << "Ingrese el departamento del trabajador: ";
			    getline(cin, departamento);
			    cout << "Ingrese las horas trabajadas por el trabajador: ";
			    cin >> horasTrabajadas;
			    cout << "Ingrese el costo por hora del trabajador: ";
			    cin >> costoPorHora;
			    Persona persona(ID_Trabajador, nombre, apellidoPaterno, apellidoMaterno, sexo, edad, direccion, telefono, puesto, departamento, horasTrabajadas, costoPorHora, horasTrabajadas * costoPorHora);
			    agregar(lista, persona);
			    break;
			case 2:
				imprimirLista(lista);
				break;
	
		}
	}while(opc != 6);
	return 0;
}

void agregar(Nodo *&lista, Persona persona) {
    Nodo *nuevo_nodo = new Nodo(persona);
    nuevo_nodo->siguiente = NULL;

    if (lista == nullptr) {
        lista = nuevo_nodo;
    } else if (persona.getNombre() < lista->persona.getNombre()) {
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


