#include<iostream>
#include <limits>
#include <algorithm>
using namespace std;

class Persona {
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
    Persona() : id(0), nombre(""), apellidoPaterno(""), apellidoMaterno(""), sexo(""), edad(0), direccion(""), telefono(0), puesto(""), departamento(""), horasTrabajadas(0), costoPorHora(0), sueldo(0) {}

    Persona(int _id,string _nombre,string _apellidoPaterno,string _apellidoMaterno,string _sexo,int _edad,string _direccion,int _telefono,string _puesto,string _departamento,int _horasTrabajadas,double _costoPorHora,double _sueldo)
    :id(_id), nombre(_nombre), apellidoPaterno(_apellidoPaterno), apellidoMaterno(_apellidoMaterno), sexo(_sexo), edad(_edad), direccion(_direccion), telefono(_telefono), puesto(_puesto), departamento(_departamento), horasTrabajadas(_horasTrabajadas), costoPorHora(_costoPorHora), sueldo(_horasTrabajadas * _costoPorHora) {}

    void setdatos(int _id,string _nombre,string _apellidoPaterno,string _apellidoMaterno,string _sexo,int _edad,string _direccion,int _telefono,string _puesto,string _departamento,int _horasTrabajadas,double _costoPorHora,double _sueldo)
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

// Prototipado de funciones
void agregar(Nodo *&, Persona);
void imprimirLista(Nodo *);
void eliminar(Nodo *&, int);
void modificar(Nodo *&, int);
bool esLetra(const string &str);
Nodo* buscarPorID(Nodo *, int);
Nodo* buscarPorNombre(Nodo *, string);

int main(){
    string nombre, apellidoPaterno, apellidoMaterno, sexo, direccion, puesto, departamento;
    int id, edad, horasTrabajadas, telefono;
    double costoPorHora;
    Persona persona;
    Nodo *lista = NULL;
    int opc;
    do {
        cout << "---------¿Qué deseas realizar?-------------" << endl;
        cout << "1.- Dar de alta a un empleado" << endl;
        cout << "2.- Mostrar nomina de empleado" << endl;
        cout << "3.- Dar de baja a un empleado" << endl;
        cout << "4.- Realizar cambios en la nomina" << endl;
        cout << "5.- Consultar informacion de un empleado" << endl;
        cout << "6.- Salir" << endl;
        cin >> opc;

        switch(opc) {
            case 1:
                cin.ignore();
                cout << "Ingrese el ID del trabajador (6 caracteres): ";
                while (!(cin >> id) || cin.peek() != '\n' || to_string(id).length() != 6) {
                    cout << "El ID del trabajador debe ser un número entero de 6 dígitos. Inténtalo de nuevo: ";
                    cin.clear();
                    cin.ignore();
                }
                cin.ignore();
                cout << "Ingrese el nombre del trabajador: ";
                while (true) {
                    getline(cin, nombre);
                    if (!nombre.empty() && esLetra(nombre)) {
                        break; 
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
                do {
                    cout << "Ingrese el sexo del trabajador (M o F): ";
                    cin >> sexo;
                    if (sexo != "M" && sexo != "F") {
                        cout << "Caracter incorrecto" << endl;
                    }
                } while (sexo != "M" && sexo != "F");
                cout << "Ingrese la edad del trabajador: ";
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
                cout << "Ingrese el ID del empleado que desea dar de baja: ";
                cin >> id;
                eliminar(lista, id);
                break;
            case 4:
                cout << "Ingrese el ID del empleado que desea hacer cambios: ";
                cin >> id;
                modificar(lista, id);
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
            case 6:
                cout << "Adios..." << endl;
                system("pause");
                break;
            default: 
                cout << "Opcion no valida" << endl;
                system("pause");
                break;
        }
        system("cls");
    } while (opc != 6);
    return 0;
}

void agregar(Nodo *&lista, Persona persona) {
    Nodo *nuevo_nodo = new Nodo(persona);
    Nodo *aux1 = lista;
    Nodo *aux2 = nullptr;

    while ((aux1 != nullptr) && (aux1->persona.get_id() < persona.get_id())) {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if (lista == aux1) {
        lista = nuevo_nodo;
    } else {
        aux2->siguiente = nuevo_nodo;
    }

    nuevo_nodo->siguiente = aux1;

    cout << "Empleado agregado exitosamente" << endl;
}

void imprimirLista(Nodo *lista) {
    if (lista == nullptr) {
        cout << "La lista está vacía" << endl;
    } else {
        Nodo *actual = lista;
        while (actual != nullptr) {
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
            cout << "---------------------------------" << endl;
            actual = actual->siguiente;
        }
    }
}

void eliminar(Nodo *&lista, int id) {
    if (lista != nullptr) {
        Nodo *aux_borrar;
        Nodo *anterior = nullptr;

        aux_borrar = lista;

        while ((aux_borrar != nullptr) && (aux_borrar->persona.get_id() != id)) {
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        }

        if (aux_borrar == nullptr) {
            cout << "El elemento no existe" << endl;
        } else if (anterior == nullptr) {
            lista = lista->siguiente;
            delete aux_borrar;
            cout << "Empleado eliminado" << endl;
        } else {
            anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
            cout << "Empleado eliminado" << endl;
        }
    } else {
        cout << "La lista está vacía" << endl;
    }
}

void modificar(Nodo *&lista, int id) {
    if (lista != nullptr) {
        Nodo *aux_modificar = lista;

        while (aux_modificar != nullptr && aux_modificar->persona.get_id() != id) {
            aux_modificar = aux_modificar->siguiente;
        }

        if (aux_modificar == nullptr) {
            cout << "El elemento no existe" << endl;
        } else {
            string nombre, apellidoPaterno, apellidoMaterno, sexo, direccion, puesto, departamento;
            int edad, telefono, horasTrabajadas;
            double costoPorHora;

            cout << "Ingrese el nuevo nombre del empleado: ";
            cin.ignore();
            getline(cin, nombre);
            aux_modificar->persona.setnombre(nombre);

            cout << "Ingrese el nuevo apellido paterno del empleado: ";
            getline(cin, apellidoPaterno);
            aux_modificar->persona.setap(apellidoPaterno);

            cout << "Ingrese el nuevo apellido materno del empleado: ";
            getline(cin, apellidoMaterno);
            aux_modificar->persona.setam(apellidoMaterno);

            cout << "Ingrese el nuevo sexo del empleado (M o F): ";
            cin >> sexo;
            aux_modificar->persona.setsexo(sexo);

            cout << "Ingrese la nueva edad del empleado: ";
            cin >> edad;
            aux_modificar->persona.setedad(edad);

            cout << "Ingrese la nueva dirección del empleado: ";
            cin.ignore();
            getline(cin, direccion);
            aux_modificar->persona.setdireccion(direccion);

            cout << "Ingrese el nuevo teléfono del empleado: ";
            cin >> telefono;
            aux_modificar->persona.settelefono(telefono);

            cout << "Ingrese el nuevo puesto del empleado: ";
            cin.ignore();
            getline(cin, puesto);
            aux_modificar->persona.setpuesto(puesto);

            cout << "Ingrese el nuevo departamento del empleado: ";
            getline(cin, departamento);
            aux_modificar->persona.setdepartamento(departamento);

            cout << "Ingrese las nuevas horas trabajadas por el empleado: ";
            cin >> horasTrabajadas;
            aux_modificar->persona.sethoras(horasTrabajadas);

            cout << "Ingrese el nuevo costo por hora del empleado: ";
            cin >> costoPorHora;
            aux_modificar->persona.setcosto(costoPorHora);

            aux_modificar->persona.setdatos(aux_modificar->persona.get_id(), nombre, apellidoPaterno, apellidoMaterno, sexo, edad, direccion, telefono, puesto, departamento, horasTrabajadas, costoPorHora, horasTrabajadas * costoPorHora);

            cout << "Empleado modificado exitosamente" << endl;
        }
    } else {
        cout << "La lista está vacía" << endl;
    }
}

bool esLetra(const string &str) {
    return all_of(str.begin(), str.end(), ::isalpha);
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
