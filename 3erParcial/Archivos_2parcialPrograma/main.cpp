#include "SegundoParcial_Archivos.h"

int main() {

    crearArchivos();

    Lista* lista = new Lista();

    int opcionArchivo;
    int opcion;

    cout << "\n";
    cout << "      Programa de archvios utilizando los temas del segundo parcial\n";
    cout << "\n";

    cout << "Seleccione el tipo de archivo:\n";
    cout << "1. TXT\n";
    cout << "2. CSV\n";
    cout << "3. JSON\n";
    cout << "4. XML\n";
    cout << "Opcion: ";
    cin >> opcionArchivo;
    
    switch(opcionArchivo) {

case 1:
    leerTXT();
    break;

case 2:
    leerCSV();
    break;

case 3:
    leerJSON();
    break;

case 4:
    leerXML();
    break;

default:
    cout << "Opcion invalida.\n";
}
    
    

    do {

        cout << "\n---- MENU ---\n";
        cout << "1. Agregar Alumno\n";
        cout << "2. Mostrar Alumnos\n";
        cout << "3. Guardar los dato en el Archivo\n";
        cout << "4. Salir\n";
        cout << "Seleccione: ";
        cin >> opcion;

        switch (opcion) {

        case 1: {

            int id;
            string nombre;

            cout << "\nIngrese ID: ";
            cin >> id;

            cout << "Ingrese Nombre: ";
            cin >> nombre;

            lista->agregar(id, nombre);

					lista->agregar(id, nombre);

						cout << "\nAlumno agregado correctamente en la memoria recuerde presionar el 3 para guardar en el archivo.\n";
            break;
        }

        case 2:

    switch(opcionArchivo)
    {
        case 1:
            leerTXT();
            break;

        case 2:
            leerCSV();
            break;

        case 3:
            leerJSON();
            break;

        case 4:
            leerXML();
            break;
    }

    break;

        case 3:

            switch (opcionArchivo) {

            case 1:
                guardarTXT(lista);
                cout << "Datos guardados en datos.txt\n";
                break;

            case 2:
                guardarCSV(lista);
                cout << "Datos guardados en datos.csv\n";
                break;

            case 3:
                guardarJSON(lista);
                cout << "Datos guardados en datos.json\n";
                break;

            case 4:
                guardarXML(lista);
                cout << "Datos guardados en datos.xml\n";
                break;

            default:
                cout << "Opcion de archivo invalida\n";
            }

            break;

        case 4:

            cout << "\nPrograma finalizado\n";
            break;

        default:

            cout << "\nOpcion no valida\n";
        }

    } while (opcion != 4);

    delete lista;

    return 0;
}