#ifndef AULAS_H
#define AULAS_H

#include "../recurso/recurso.h"

class Aulas : public Recurso{

    private:
        int aforo_;
    
    public:

        Aulas(std::string id_recurso, int aforo, std::string nombre_recurso="Aula"):Recurso(id_recurso, nombre_recurso){aforo_=aforo;};

        inline int get_aforo(){return aforo_;};
        inline void set_aforo(int aforo){aforo_=aforo;};

};

#endif