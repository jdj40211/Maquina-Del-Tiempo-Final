#include "Nodo.h"

Nodo::Nodo(int datos, int cientifico) {
    this->datos = datos;
    this->cientifico = (cientifico == 1) ? "Einstein" : "Rosen";
    PtrPasado = nullptr;
    PtrFuturo = nullptr;
}
