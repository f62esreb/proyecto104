#ifndef ADMININSTRADOR_CURSOS_H
#define ADMININSTRADOR_CURSOS_H

#pragma once
#include "../lista_cursos/lista_cursos.h"
#include "../usuario/usuario.h"

#include <string>

class Administrador_Cursos: public Usuario {
    private:
        Lista_Cursos &cursos_;
    public:
        Administrador_Cursos(Lista_Cursos &cursos): cursos_(cursos), Usuario("admin_cursos", "admin_cursos", "admin_cursos", "admin_cursos@uco.es") {this->cargarAdministrador(); };
        
        bool cargarAdministrador();
        
        inline bool addCurso(Curso c) { return cursos_.addCurso(c); };

        inline bool modificarCurso(Curso c, std::string id) { return cursos_.modificarCurso(id, c); };

        bool guardarAdministrador();
};

#endif