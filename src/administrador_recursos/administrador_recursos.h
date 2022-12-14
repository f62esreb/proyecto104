#ifndef ADMININSTRADOR_RECURSOS_H
#define ADMININSTRADOR_RECURSOS_H

#pragma once
#include "../lista_cursos/lista_cursos.h"
#include "../usuario/usuario.h"
#include "../recurso/recurso.h"

#include <list>
#include <string>

class Administrador_Recursos: public Usuario {
    private:
        Lista_Cursos &cursos_;
        std::list<Recurso> recursos_;
    public:
        Administrador_Recursos(Lista_Cursos &cursos): cursos_(cursos), Usuario("admin_recursos", "admin_recursos", "admin_recursos", "admin_recursos@uco.es") {this->cargarAdministrador(); };
        bool cargarAdministrador();
        bool addRecurso(std::string id, Recurso R );
        bool quitarRecurso(std::string id, std::string id_recurso);
        bool addRecurso_Sistema(Recurso R);
        bool quitarRecurso_Sistema(std::string id);
        bool cargarRecursos();
        bool guardarRecursos();
};

#endif