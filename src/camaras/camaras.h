#ifndef CAMARAS_H
#define CAMARAS_H

#include"../recurso/recurso.h"

class Camaras : public Recurso{

    private:
        int calidad_imagen_;
    
    public:

        Camaras(std::string id_recurso, int calidad_imagen, std::string nombre_recurso="Camara"):Recurso(id_recurso,nombre_recurso){calidad_imagen_=calidad_imagen;};

        inline int get_calidad(){return calidad_imagen_;};
        inline void set_calidad(int calidad_imagen){calidad_imagen_=calidad_imagen;};
};

#endif