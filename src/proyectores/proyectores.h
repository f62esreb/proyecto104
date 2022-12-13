#ifndef PROYECTORES_H
#define PROYECTORES_H

#include "../recurso/recurso.h"

class Proyectores : public Recurso{

    private:
        int resolucion_, brillo_;

    public:
        Proyectores(std::string id_recurso, int resolucion, int brillo, std::string nombre_recurso="Proyector"):Recurso(id_recurso,nombre_recurso){resolucion_=resolucion; brillo_=brillo;};

        inline int get_resolucion(){return resolucion_;};
        inline void set_resolucion(int resolucion){resolucion_=resolucion;};

        inline int get_brillo(){return brillo_;};
        inline void set_brillo(int brillo){brillo_=brillo;};

};
#endif