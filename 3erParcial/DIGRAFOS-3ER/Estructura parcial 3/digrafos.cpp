#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cstdio>

using namespace std;

// =========================
// RUTA COMPLETA
// =========================
struct Ruta
{
    vector<string> nodos;
    int costo;
};

class Digrafo
{
private:
    vector<string> nodosBase;
    vector<Ruta> rutas;

    string archivoActual;
    bool archivoCargado;

public:

    Digrafo()
    {
        archivoCargado = false;
        archivoActual = "";
    }

    // =========================
    // CREAR NODOS
    // =========================
    void crearNodos()
    {
        int n;
        cout << "\nCuantos nodos deseas crear: ";
        cin >> n;
        cin.ignore();

        nodosBase.clear();

        for (int i = 0; i < n; i++)
        {
            string nodo;
            cout << "Nodo " << i + 1 << ": ";
            getline(cin, nodo);
            nodosBase.push_back(nodo);
        }
    }

    // =========================
    // AGREGAR VARIAS RUTAS
    // =========================
    void agregarRutas()
    {
        int cant;
        cout << "\nCuantas rutas deseas agregar: ";
        cin >> cant;
        cin.ignore();

        for (int k = 0; k < cant; k++)
        {
            Ruta r;
            int pasos;

            cout << "\nRuta " << k + 1 << ":\n";

            cout << "Cantidad de nodos en esta ruta: ";
            cin >> pasos;
            cin.ignore();

            for (int i = 0; i < pasos; i++)
            {
                string nodo;
                cout << "Nodo " << i + 1 << ": ";
                getline(cin, nodo);
                r.nodos.push_back(nodo);
            }

            cout << "Costo total de la ruta: ";
            cin >> r.costo;
            cin.ignore();

            rutas.push_back(r);
        }
    }

    // =========================
    // MOSTRAR DIGRAFO COMO ÁRBOL
    // =========================
    void mostrarDigrafo()
    {
        cout << "\n===== DIGRAFO (ARBOL DE RUTAS) =====\n";

        for (int i = 0; i < rutas.size(); i++)
        {
            cout << "\nRuta " << i + 1 << " | costo " << rutas[i].costo << "\n";

            for (int j = 0; j < rutas[i].nodos.size(); j++)
            {
                cout << rutas[i].nodos[j];

                if (j != rutas[i].nodos.size() - 1)
                    cout << " -> ";
            }

            cout << endl;
        }
    }

    // =========================
    // MEJOR RUTA
    // =========================
    void mejorRuta()
    {
        if (rutas.empty())
        {
            cout << "\nNo hay rutas.\n";
            return;
        }

        int best = 0;

        for (int i = 1; i < rutas.size(); i++)
            if (rutas[i].costo < rutas[best].costo)
                best = i;

        cout << "\n===== MEJOR RUTA =====\n";
        cout << "Costo minimo: " << rutas[best].costo << "\n";
        cout << "Camino: ";

        for (int i = 0; i < rutas[best].nodos.size(); i++)
        {
            cout << rutas[best].nodos[i];
            if (i != rutas[best].nodos.size() - 1)
                cout << " -> ";
        }

        cout << endl;
    }

    // =========================
    // GUARDAR CON FORMATO
    // =========================
    void guardar()
    {
        string nombre;
        int op;

        cout << "\nNombre del archivo: ";
        cin >> nombre;

        cout << "\nFormato:\n1 TXT\n2 CSV\n3 JSON\n4 HTML\n5 CC\nOpcion: ";
        cin >> op;

        string file = nombre;

        if (op == 1) file += ".txt";
        if (op == 2) file += ".csv";
        if (op == 3) file += ".json";
        if (op == 4) file += ".html";
        if (op == 5) file += ".cc";

        FILE* f = fopen(file.c_str(), "w");

        for (int i = 0; i < rutas.size(); i++)
        {
            fprintf(f, "Ruta %d | costo %d | ", i + 1, rutas[i].costo);

            for (int j = 0; j < rutas[i].nodos.size(); j++)
            {
                fprintf(f, "%s", rutas[i].nodos[j].c_str());
                if (j != rutas[i].nodos.size() - 1)
                    fprintf(f, " -> ");
            }

            fprintf(f, "\n");
        }

        fclose(f);

        cout << "\nArchivo guardado: " << file << endl;
    }

    // =========================
    // LEER ARCHIVO (CON EXTENSIÓN)
    // =========================
    void leerArchivo()
    {
        cout << "\nNombre del archivo con extension: ";
        cin >> archivoActual;

        FILE* f = fopen(archivoActual.c_str(), "r");

        if (!f)
        {
            cout << "No se pudo abrir.\n";
            archivoCargado = false;
            return;
        }

        archivoCargado = true;

        cout << "\n===== CONTENIDO DEL ARCHIVO =====\n";

        char linea[300];
        while (fgets(linea, sizeof(linea), f))
            cout << linea;

        fclose(f);

        char op;
        cout << "\n¿Deseas modificar el archivo? (s/n): ";
        cin >> op;

        if (op == 's' || op == 'S')
        {
            modificarArchivo();
        }
    }

    // =========================
    // MODIFICAR + RE-GUARDAR
    // =========================
    void modificarArchivo()
    {
        if (!archivoCargado)
        {
            cout << "\nPrimero lee un archivo.\n";
            return;
        }

        cout << "\n1 Agregar ruta\n2 Eliminar ultima ruta\nOpcion: ";
        int op;
        cin >> op;

        if (op == 1)
        {
            agregarRutas();
        }
        else if (op == 2 && !rutas.empty())
        {
            rutas.pop_back();
        }

        cout << "\nArchivo modificado en memoria.\n";

        char save;
        cout << "¿Deseas guardar cambios? (s/n): ";
        cin >> save;

        if (save == 's' || save == 'S')
        {
            FILE* f = fopen(archivoActual.c_str(), "w");

            for (int i = 0; i < rutas.size(); i++)
            {
                fprintf(f, "Ruta %d | costo %d | ", i + 1, rutas[i].costo);

                for (int j = 0; j < rutas[i].nodos.size(); j++)
                {
                    fprintf(f, "%s", rutas[i].nodos[j].c_str());
                    if (j != rutas[i].nodos.size() - 1)
                        fprintf(f, " -> ");
                }

                fprintf(f, "\n");
            }

            fclose(f);

            cout << "Cambios guardados correctamente.\n";
        }
    }
};

// =========================
int main()
{
    Digrafo g;
    int op;

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1 Crear nodos\n2 Agregar rutas\n3 Mostrar digrafo\n4 Mejor ruta\n5 Guardar\n6 Leer archivo\n7 Salir\nOpcion: ";
        cin >> op;

        if (op == 1) g.crearNodos();
        if (op == 2) g.agregarRutas();
        if (op == 3) g.mostrarDigrafo();
        if (op == 4) g.mejorRuta();
        if (op == 5) g.guardar();
        if (op == 6) g.leerArchivo();

    } while (op != 7);

    return 0;
}
