#include "MaquinaDelTiempo.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

MaquinaDelTiempo::MaquinaDelTiempo() {
    primerEvento = nullptr;
    ultimoEvento = nullptr;
    cantidadEventosTipoA = 0;
    cantidadEventosTipoB = 0;
    ultimoEventoTipoA = nullptr;
    ultimoEventoTipoB = nullptr;
    nodoSingularidad = nullptr;
    std::srand(std::time(nullptr));
}

MaquinaDelTiempo::~MaquinaDelTiempo() {
    // Implementa la liberación de memoria para los nodos si es necesario.
}

void MaquinaDelTiempo::crearEventos() {
    for (int i = 0; i < 22; i++) {
        int randomDatos = std::rand() % 100 + 1;
        int randomCientifico = std::rand() % 2 + 1;
        Nodo* nuevoEvento = new Nodo(randomDatos, randomCientifico);

        if (primerEvento == nullptr) {
            primerEvento = nuevoEvento;
            ultimoEvento = nuevoEvento;
        } else {
            nuevoEvento->PtrPasado = ultimoEvento;
            ultimoEvento->PtrFuturo = nuevoEvento;
            ultimoEvento = nuevoEvento;
        }

        // Verificar si es un evento tipo A o B y aplicar las restricciones según sea necesario.
        if (randomDatos == 1 || randomDatos == 2) { // Evento A o B
            if (randomCientifico == 1) { // Einstein
                nuevoEvento->cientifico = "Einstein";
            }
            if (randomDatos == 1) { // Evento A
                cantidadEventosTipoA++;
                ultimoEventoTipoA = nuevoEvento;
            } else { // Evento B
                cantidadEventosTipoB++;
                ultimoEventoTipoB = nuevoEvento;
            }
        }

        // Verificar si se ha producido una singularidad y almacenar el nodo correspondiente.
        if (nuevoEvento->PtrPasado != nullptr && nuevoEvento->datos % nuevoEvento->PtrPasado->datos == 0) {
            nodoSingularidad = nuevoEvento;
        }
    }
}

void MaquinaDelTiempo::mostrarEventos() {
    Nodo* actual = primerEvento;
    int contador = 1;
    while (actual != nullptr) {
        std::cout << "Evento " << contador << ": ";
        std::cout << "Datos=" << actual->datos << ", ";
        std::cout << "Cientifico=" << actual->cientifico << ", ";
        if (actual->PtrPasado != nullptr) {
            std::cout << "PtrPasado->Datos=" << actual->PtrPasado->datos << ", ";
        }
        if (actual->PtrFuturo != nullptr) {
            std::cout << "PtrFuturo->Datos=" << actual->PtrFuturo->datos;
        }
        std::cout << std::endl;
        actual = actual->PtrFuturo;
        contador++;
    }
}

void MaquinaDelTiempo::mostrarEventosTipoA() {
    std::cout << "Eventos Tipo A (" << cantidadEventosTipoA << "):" << std::endl;
    Nodo* actual = primerEvento;
    while (actual != nullptr) {
        if (actual->datos == 1 || actual->datos == 2) {
            std::cout << "Datos=" << actual->datos << ", ";
            std::cout << "Cientifico=" << actual->cientifico << std::endl;
        }
        actual = actual->PtrFuturo;
    }
}

void MaquinaDelTiempo::mostrarEventosTipoB() {
    std::cout << "Eventos Tipo B (" << cantidadEventosTipoB << "):" << std::endl;
    Nodo* actual = primerEvento;
    while (actual != nullptr) {
        if (actual->datos == 1 || actual->datos == 2) {
            std::cout << "Datos=" << actual->datos << ", ";
            std::cout << "Cientifico=" << actual->cientifico << std::endl;
        }
        actual = actual->PtrFuturo;
    }
}

void MaquinaDelTiempo::mostrarSingularidad() {
    if (nodoSingularidad != nullptr) {
        std::cout << "Singularidad encontrada en el evento con Datos=" << nodoSingularidad->datos << std::endl;
    } else {
        std::cout << "No se ha encontrado ninguna singularidad." << std::endl;
    }
}

int MaquinaDelTiempo::obtenerTotalEventos() {
    int contador = 0;
    Nodo* actual = primerEvento;
    while (actual != nullptr) {
        contador++;
        actual = actual->PtrFuturo;
    }
    return contador;
}