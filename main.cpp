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

		void setid(int i)
	{
	    id = i;
	}

	void setnombre(string nom)
	{
	    nombre = nom;
	}

	void setap(string ap)
	{
	    apellidoPaterno = ap;
	}

	void setam(string am)
	{
	    apellidoMaterno = am;
	}

	void setsexo(string s)
	{
	    sexo = s;
	}

	void setedad(int e)
	{
	    edad = e;
	}

	void setdireccion(string di)
	{
	    direccion = di;
	}

	void settelefono(int t)
	{
	    telefono = t;
	}

	void setpuesto(string pue)
	{
	    puesto = pue;
	}

	void setdepartamento(string dep)
	{
	    departamento = dep;
	}

	void sethoras(int h)
	{
	    horasTrabajadas = h;
	}

	void setcosto(int c)
	{
	    costoPorHora = c;
	}

	int get_id() const {
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
void modificar(Nodo *&, int);
bool esLetra(const string &str);
Nodo* buscarPorID(Nodo *,int);
Nodo* buscarPorNombre(Nodo *,string);
bool mensaje_mostrado = false;

int main(){
	string nombre, apellidoPaterno, apellidoMaterno, sexo, direccion,  puesto, departamento;
	int id,  edad, opcionConsulta, horasTrabajadas,telefono;
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
		///cin>>opc;
        while (!(cin >> opc || to_string(opc).length() != 1)) {
            if (!mensaje_mostrado) {
                cout << "Ingrese 1 valor numerico: ";
                mensaje_mostrado = true;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }


		switch(opc){

			case 1:
				cin.ignore();
				cout << "Ingrese el ID del trabajador (6 caracteres): ";
                while (!(cin >> id) || to_string(id).length() != 6) {
                    if (!mensaje_mostrado) {
                        cout << "El ID del trabajador debe ser un número entero de 6 dígitos. Inténtalo de nuevo: ";;
                        mensaje_mostrado = true;
                    }
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

    			cin.ignore();

				cout << "Ingrese el nombre del trabajador: ";
                while (true) {
                    getline(cin, nombre);
                    if (!nombre.empty() && esLetra(nombre)) {
                        break; // Sale del bucle si el nombre es válido
                    } else {
                        cout << "Ingrese un nombre válido (solo letras, no vacío): ";
                    }
                }

				cout << "Ingrese el apellido paterno del trabajador: ";
                while (true) {
                    getline(cin, apellidoPaterno);
                    if (!apellidoPaterno.empty() && esLetra(apellidoPaterno)) {
                        break;
                    } else {
                        cout << "Ingrese un apellido válido (solo letras, no vacío): ";
                    }
                }

				cout << "Ingrese el apellido materno del trabajador: ";
                while (true) {
                    getline(cin, apellidoMaterno);
                    if (!apellidoMaterno.empty() && esLetra(apellidoMaterno)) {
                        break;
                    } else {
                        cout << "Ingrese un apellido válido (solo letras, no vacío): ";
                    }
                }

				do{
                    cout << "Ingrese el sexo del trabajador (M o F): ";
                    cin >> sexo;
                    if (sexo!="M"&&sexo!="F")
                    {
                        cout<<"caracter incorrecto"<<endl;
                    }
                }while(sexo!="M"&&sexo!="F");

				cout<< "Ingrese la edad del trabajador: ";
				while (!(cin >> edad) || to_string(edad).length() != 2) {
                    if (!mensaje_mostrado) {
                        cout << "Ingrese su edad con el formato 00: ";;
                        mensaje_mostrado = true;
                    }
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

				cin.ignore();

				cout << "Ingrese la dirección del trabajador: ";
				getline(cin, direccion);
				cout << "Ingrese el teléfono del trabajador: ";
				while (!(cin >> telefono)) {
                    if (!mensaje_mostrado) {
                        cout << "Ingrese valores numericos";;
                        mensaje_mostrado = true;
                    }
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

				cin.ignore();

				cout << "Ingrese el puesto del trabajador: ";
                while (true) {
                    getline(cin, puesto);
                    if (!puesto.empty() && esLetra(puesto)) {
                        break;
                    } else {
                        cout << "Ingrese un puesto válido (solo letras, no vacío): ";
                    }
                }

				cout << "Ingrese el departamento del trabajador: ";
                while (true) {
                    getline(cin, departamento);
                    if (!departamento.empty() && esLetra(departamento)) {
                        break;
                    } else {
                        cout << "Ingrese un departamento válido (solo letras, no vacío): ";
                    }
                }

				cout << "Ingrese las horas trabajadas por el trabajador: ";
				while (!(cin >> horasTrabajadas)) {
                    if (!mensaje_mostrado) {
                        cout << "Ingrese valores numericos: ";;
                        mensaje_mostrado = true;
                    }
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

				cin.ignore();

				cout << "Ingrese el costo por hora del trabajador: ";
                while (!(cin >> costoPorHora)) {
                    if (!mensaje_mostrado) {
                        cout << "Ingrese valores numericos: ";;
                        mensaje_mostrado = true;
                    }
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
			case 4:
			    cout << "Ingrese el ID del empleado que desea hacer cambios\n";
				cin >> id;
				modificar(lista, id);
                	break;
            		case 6:
				cout << "Adios...\n";
				system("pause");
			break;
			case 5:
				int opcionConsulta;
                cout << "¿Qué empleado deseas consultar?" << endl;
                cout << "1. Por ID" << endl;
                cout << "2. Por nombre completo" << endl;
                cin >> opcionConsulta;
                if (opcionConsulta == 1) {
                    int idConsulta;
                    cout << "Dame por favor su ID: ";
                    cin >> idConsulta;
                    Nodo* empleadoID = buscarPorID(lista, idConsulta);
                    if (empleadoID != nullptr) {
                        cout << "Información del empleado encontrado por ID:" << endl;
                        cout << "ID Trabajador: " << empleadoID->persona.get_id() << endl;
                        cout << "Nombre: " << empleadoID->persona.getNombre() << endl;
                        cout << "Apellido Paterno: " << empleadoID->persona.getApellidoPaterno() << endl;
                        cout << "Apellido Materno: " << empleadoID->persona.getApellidoMaterno() << endl;
                        cout << "Sexo: " << empleadoID->persona.getSexo() << endl;
                        cout << "Edad: " << empleadoID->persona.getEdad() << endl;
                        cout << "Dirección: " << empleadoID->persona.getDireccion() << endl;
                        cout << "Teléfono: " << empleadoID->persona.getTelefono() << endl;
                        cout << "Puesto: " << empleadoID->persona.getPuesto() << endl;
                        cout << "Departamento: " << empleadoID->persona.getDepartamento() << endl;
                        cout << "Horas Trabajadas: " << empleadoID->persona.getHorasTrabajadas() << endl;
                        cout << "Costo por Hora: " << empleadoID->persona.getCostoPorHora() << endl;
                        cout << "Sueldo: " << empleadoID->persona.getSueldo() << endl;
                    } else {
                        cout << "El empleado no se encontró en la nómina." << endl;
                    }
                } else if (opcionConsulta == 2) {
                    cin.ignore();
                    string nombreCompleto;
                    cout << "Dame por favor su nombre completo: ";
                    getline(cin, nombreCompleto);
                    Nodo* empleadoNombre = buscarPorNombre(lista, nombreCompleto);
                    if (empleadoNombre != nullptr) {
                        cout << "Información del empleado encontrado por nombre completo:" << endl;
                        cout << "ID Trabajador: " << empleadoNombre->persona.get_id() << endl;
                        cout << "Nombre: " << empleadoNombre->persona.getNombre() << endl;
                        cout << "Apellido Paterno: " << empleadoNombre->persona.getApellidoPaterno() << endl;
                        cout << "Apellido Materno: " << empleadoNombre->persona.getApellidoMaterno() << endl;
                        cout << "Sexo: " << empleadoNombre->persona.getSexo() << endl;
                        cout << "Edad: " << empleadoNombre->persona.getEdad() << endl;
                        cout << "Dirección: " << empleadoNombre->persona.getDireccion() << endl;
                        cout << "Teléfono: " << empleadoNombre->persona.getTelefono() << endl;
                        cout << "Puesto: " << empleadoNombre->persona.getPuesto() << endl;
                        cout << "Departamento: " << empleadoNombre->persona.getDepartamento() << endl;
                        cout << "Horas Trabajadas: " << empleadoNombre->persona.getHorasTrabajadas() << endl;
                        cout << "Costo por Hora: " << empleadoNombre->persona.getCostoPorHora() << endl;
                        cout << "Sueldo: " << empleadoNombre->persona.getSueldo() << endl;
                    } else {
                        cout << "El empleado no se encontró en la nómina." << endl;
                    }
                } else {
                    cout << "Opción inválida." << endl;
                }
                system("pause");
                break;
                default:
                    cout << "Opcion no valida\n";
                    system("pause");
                    cin.clear();
                    cin.ignore();
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
		    system("pause");
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


void modificar(Nodo *&lista, int id)
{
    int o = 0;
    Nodo *aux_nodo;
    aux_nodo = lista;
    while(aux_nodo != NULL && id != aux_nodo->persona.get_id())
    {
        aux_nodo = aux_nodo->siguiente;
    }
    if(aux_nodo != NULL)
    {
        string ap, am, n, s, d, dep, p;
        int i, e, t, h, c, o;
        while(o != 13){

            cout << "Que dato desea actualizar del siguiente empleado: " << endl;
            cout << "1) ID Trabajador: " << aux_nodo->persona.get_id() <<  endl;
            cout << "2) Nombre: " << aux_nodo->persona.getNombre() <<  endl;
            cout << "3) Apellido Paterno: " << aux_nodo->persona.getApellidoPaterno() << endl;
            cout << "4) Apellido Materno: " << aux_nodo->persona.getApellidoMaterno() << endl;
            cout << "5) Sexo: " << aux_nodo->persona.getSexo() << endl;
            cout << "6) Edad: "  << aux_nodo->persona.getEdad() << endl;
            cout << "7) Direccion: " << aux_nodo->persona.getDireccion() << endl;
            cout << "8) Telefono: " << aux_nodo->persona.getTelefono() << endl;
            cout << "9) Puesto: " << aux_nodo->persona.getPuesto() << endl;
            cout << "10) Departamento: " << aux_nodo->persona.getDepartamento() << endl;
            cout << "11) Horas Trabajadas: " << aux_nodo->persona.getHorasTrabajadas() << endl;
            cout << "12) Costo por Hora: " << aux_nodo->persona.getCostoPorHora() << endl;
            cout << "13) SALIR" << endl;
            cout << "-----------------------------------" << endl;
            cin >> o;
            switch(o)
            {
            case 1:
                cout << "ID Trabajador: " << aux_nodo->persona.get_id() << endl;
                cout << "Nuevo id: ";
                while (!(cin >> i) || to_string(i).length() != 6) {
                    if (!mensaje_mostrado) {
                        cout << "El ID del trabajador debe ser un número entero de 6 dígitos. Inténtalo de nuevo: ";;
                        mensaje_mostrado = true;
                    }
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                aux_nodo->persona.setid(i);
                break;
            case 2:
                cout << "2) Nombre: " << aux_nodo->persona.getNombre() << endl;
                cout << "Nuevo nombre: ";
                while (true) {
                    getline(cin, n);
                    if (!n.empty() && esLetra(n)) {
                        break; // Sale del bucle si el nombre es válido
                    } else {
                        cout << "Ingrese un nombre válido (solo letras, no vacío): ";
                    }
                }

                aux_nodo->persona.setnombre(n);
                break;
            case 3:
                cout << "3) Apellido Paterno: " << aux_nodo->persona.getApellidoPaterno() << endl;
                cout << "Nuevo apellido: ";
                while (true) {
                    getline(cin, ap);
                    if (!ap.empty() && esLetra(ap)) {
                        break;
                    } else {
                        cout << "Ingrese un apellido válido (solo letras, no vacío): ";
                    }
                }
                aux_nodo->persona.setap(ap);
                break;
            case 4:
                cout << "4) Apellido Materno: " << aux_nodo->persona.getApellidoMaterno() << endl;
                cout << "Nuevo apellido: ";
                while (true) {
                    getline(cin, am);
                    if (!am.empty() && esLetra(am)) {
                        break;
                    } else {
                        cout << "Ingrese un apellido válido (solo letras, no vacío): ";
                    }
                }
                aux_nodo->persona.setam(am);
                break;
            case 5:
                cout << "5) Sexo: " << aux_nodo->persona.getSexo() << endl;
                do{
                    cout << "Ingrese el nuevo sexo del trabajador (M o F): ";
                    cin >> s;
                    if (s!="M"&&s!="F")
                    {
                        cout<<"caracter incorrecto"<<endl;
                    }
                }while(s!="M"&&s!="F");

                aux_nodo->persona.setsexo(s);
                break;
            case 6:
                cout << "6) Edad: " << aux_nodo->persona.getEdad() << endl;
                cout << "Nueva edad: ";
                while (!(cin >> e) || to_string(e).length() != 2) {
                    if (!mensaje_mostrado) {
                        cout << "Ingrese su edad con el formato 00: ";;
                        mensaje_mostrado = true;
                    }
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                aux_nodo->persona.setedad(e);
                break;
            case 7:
                cout << "7) Direccion: " << aux_nodo->persona.getDireccion() << endl;
                cout << "Nueva direccion: ";
                getline(cin, d);
                aux_nodo->persona.setdireccion(d);
                break;
            case 8:
                cout << "8) Telefono: " << aux_nodo->persona.getTelefono() << endl;
                cout << "Nuevo telefono: ";
                while (!(cin >> t)) {
                    if (!mensaje_mostrado) {
                        cout << "Ingrese valores numericos";;
                        mensaje_mostrado = true;
                    }
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                aux_nodo->persona.settelefono(t);
                break;
            case 9:
                cout << "9) Puesto: " << aux_nodo->persona.getPuesto() << endl;
                cout << "Nuevo puesto: ";
                while (true) {
                    getline(cin, p);
                    if (!p.empty() && esLetra(p)) {
                        break;
                    } else {
                        cout << "Ingrese un puesto válido (solo letras, no vacío): ";
                    }
                }
                aux_nodo->persona.setpuesto(p);
                break;
            case 10:
                cout << "10) Departamento: " << aux_nodo->persona.getDepartamento() << endl;
                cout << "Nuevo departamento: ";
                while (true) {
                    getline(cin, dep);
                    if (!dep.empty() && esLetra(dep)) {
                        break;
                    } else {
                        cout << "Ingrese un departamento válido (solo letras, no vacío): ";
                    }
                }
                aux_nodo->persona.setdepartamento(dep);
                break;
            case 11:
                cout << "11) Horas Trabajadas: " << aux_nodo->persona.getHorasTrabajadas() << endl;
                cout << "Nueva cantidad de horas trabajadas: ";
                while (!(cin >> h)) {
                    if (!mensaje_mostrado) {
                        cout << "Ingrese valores numericos: ";;
                        mensaje_mostrado = true;
                    }
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                aux_nodo->persona.sethoras(h);
                break;
            case 12:
                cout << "12) Costo por Hora: " << aux_nodo->persona.getCostoPorHora() << endl;
                cout << "Nuevo costo por hora: ";
                while (!(cin >> c)) {
                    if (!mensaje_mostrado) {
                        cout << "Ingrese valores numericos: ";;
                        mensaje_mostrado = true;
                    }
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                aux_nodo->persona.setcosto(c);
                break;
                default:
                cout << "Saliendo..." << endl;
            }
            system("pause");
            system("cls");
		}

    }
    else
    {
        cout << "No existe..." << endl;
    }
}

bool esLetra(const string &str) {
    for (char c : str) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

Nodo* buscarPorID(Nodo *lista, int id) {
    Nodo *actual = lista;
    while (actual != nullptr) {
        if (actual->persona.get_id() == id) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

Nodo* buscarPorNombre(Nodo *lista, string nombreCompleto) {
    Nodo *actual = lista;
    while (actual != nullptr) {
        if (actual->persona.getNombre() + " " + actual->persona.getApellidoPaterno() + " " + actual->persona.getApellidoMaterno() == nombreCompleto) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}
