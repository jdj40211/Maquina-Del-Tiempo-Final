#ifndef NODO_H
#define NODO_H

#include <string>

class Nodo {
public:
    int datos;
    std::string cientifico;
    Nodo* PtrPasado;
    Nodo* PtrFuturo;

    Nodo(int datos, int cientifico);
};

#endif // NODO_H
