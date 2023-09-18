#ifndef MAQUINA_DEL_TIEMPO_H
#define MAQUINA_DEL_TIEMPO_H

#include "Nodo.h"

class MaquinaDelTiempo {
public:
    MaquinaDelTiempo();
    ~MaquinaDelTiempo();
    void crearEventos();
    void mostrarEventos();
    void mostrarEventosTipoA();
    void mostrarEventosTipoB();
    void mostrarSingularidad();
    int obtenerTotalEventos();
    

private:
    Nodo* primerEvento;
    Nodo* ultimoEvento;
    int cantidadEventosTipoA;
    int cantidadEventosTipoB;
    Nodo* ultimoEventoTipoA;
    Nodo* ultimoEventoTipoB;
    Nodo* nodoSingularidad;
};

#endif // MAQUINA_DEL_TIEMPO_H
