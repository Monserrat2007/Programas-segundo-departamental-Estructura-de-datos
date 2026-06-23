#include "SegundoParcial_Archivos.h"


// CLASE ALUMNO


Alumno::Alumno() {
    id = 0;
    nombre = "";
}

Alumno::Alumno(int i, string n) {
    id = i;
    nombre = n;
}

// CLASE LISTA


Lista::Lista(int cap) {
    capacidad = cap;
    cantidad = 0;
    alumnos = new Alumno[capacidad];
}

Lista::~Lista() {
    delete[] alumnos;
}

void Lista::agregar(int id, string nombre) {
    if (cantidad < capacidad) {
        alumnos[cantidad] = Alumno(id, nombre);
        cantidad++;
    }
}

void Lista::mostrar() {

    cout << "\n ALUMNOS REGISTRADOS \n";

    for (int i = 0; i < cantidad; i++) {
        cout << "ID: " << alumnos[i].id
             << "  Nombre: "
             << alumnos[i].nombre
             << endl;
    }
}

Alumno* Lista::obtenerArreglo() {
    return alumnos;
}

int Lista::getCantidad() {
    return cantidad;
}


// CREAR ARCHIVOS


void crearArchivos() {

    ofstream txt("datos.txt", ios::app);
    txt.close();

    ofstream csv("datos.csv", ios::app);
    csv.close();

    ofstream json("datos.json", ios::app);
    json.close();

    ofstream xml("datos.xml", ios::app);
    xml.close();
}


// GUARDAR EN TXt


void guardarTXT(Lista* lista) {

    ofstream archivo("datos.txt");

    Alumno* arr = lista->obtenerArreglo();

    for (int i = 0; i < lista->getCantidad(); i++) {

        archivo << arr[i].id
                << " "
                << arr[i].nombre
                << endl;
    }

    archivo.close();
}


// GUARDAR CSV


void guardarCSV(Lista* lista) {

    ofstream archivo("datos.csv");

    Alumno* arr = lista->obtenerArreglo();

    archivo << "ID,NOMBRE\n";

    for (int i = 0; i < lista->getCantidad(); i++) {

        archivo << arr[i].id
                << ","
                << arr[i].nombre
                << endl;
    }

    archivo.close();
}


// GUARDAR JSON

void guardarJSON(Lista* lista) {

    ofstream archivo("datos.json");

    Alumno* arr = lista->obtenerArreglo();

    archivo << "[\n";

    for (int i = 0; i < lista->getCantidad(); i++) {

        archivo << "  {\"id\": "
                << arr[i].id
                << ", \"nombre\": \""
                << arr[i].nombre
                << "\"}";

        if (i < lista->getCantidad() - 1)
            archivo << ",";

        archivo << "\n";
    }

    archivo << "]";

    archivo.close();
}


// GUARDAR XML


void guardarXML(Lista* lista) {

    ofstream archivo("datos.xml");

    Alumno* arr = lista->obtenerArreglo();

    archivo << "<alumnos>\n";

    for (int i = 0; i < lista->getCantidad(); i++) {

        archivo << "   <alumno>\n";
        archivo << "      <id>"
                << arr[i].id
                << "</id>\n";

        archivo << "      <nombre>"
                << arr[i].nombre
                << "</nombre>\n";

        archivo << "   </alumno>\n";
    }

    archivo << "</alumnos>";

    archivo.close();   
}


void leerTXT() {

    ifstream archivo("datos.txt");

    if(!archivo)
    {
        cout << "No se pudo abrir datos.txt\n";
        return;
    }

    cout << "Archivo abierto correctamente\n";

    string linea;
    bool vacio = true;

    while(getline(archivo, linea))
    {
        cout << "[" << linea << "]" << endl;
        vacio = false;
    }

    if(vacio)
    {
        cout << "Archivo vacio\n";
    }

    archivo.close();
}

void leerCSV() {

    ifstream archivo("datos.csv");

    if(!archivo)
    {
        cout << "No se pudo abrir datos.csv\n";
        return;
    }

    cout << "Archivo abierto correctamente\n";

    string linea;
    bool vacio = true;

    while(getline(archivo, linea))
    {
        cout << "[" << linea << "]" << endl;
        vacio = false;
    }

    if(vacio)
    {
        cout << "Archivo vacio\n";
    }

    archivo.close();
}

void leerJSON() {

    ifstream archivo("datos.json");

    if(!archivo)
    {
        cout << "No se pudo abrir datos.json\n";
        return;
    }

    cout << "Archivo abierto correctamente\n";

    string linea;
    bool vacio = true;

    while(getline(archivo, linea))
    {
        cout << "[" << linea << "]" << endl;
        vacio = false;
    }

    if(vacio)
    {
        cout << "Archivo vacio\n";
    }

    archivo.close();
}

void leerXML() {

    ifstream archivo("datos.xml");

    if(!archivo)
    {
        cout << "No se pudo abrir datos.xml\n";
        return;
    }

    cout << "Archivo abierto correctamente\n";

    string linea;
    bool vacio = true;

    while(getline(archivo, linea))
    {
        cout << "[" << linea << "]" << endl;
        vacio = false;
    }

    if(vacio)
    {
        cout << "Archivo vacio\n";
    }

    archivo.close();
}
