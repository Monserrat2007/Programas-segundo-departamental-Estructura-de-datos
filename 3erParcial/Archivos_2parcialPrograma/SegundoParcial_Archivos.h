#ifndef SEGUNDOPARCIAL_ARCHIVOS_H
#define SEGUNDOPARCIAL_ARCHIVOS_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Clase Alumno
class Alumno {
public:
    int id;
    string nombre;

    Alumno();
    Alumno(int i, string n);
};

// ADT Lista
class Lista {
private:
    Alumno* alumnos;
    int capacidad;
    int cantidad;

public:
    Lista(int cap = 10);
    ~Lista();

    void agregar(int id, string nombre);
    void mostrar();

    Alumno* obtenerArreglo();
    int getCantidad();
};

// Funciones para archivos
void crearArchivos();

void guardarTXT(Lista* lista);
void guardarCSV(Lista* lista);
void guardarJSON(Lista* lista);
void guardarXML(Lista* lista);

void leerTXT();
void leerCSV();
void leerJSON();
void leerXML();

#endif