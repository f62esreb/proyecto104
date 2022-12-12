#ifndef ADMININSTRADOR_RECURSOS_H
#define ADMININSTRADOR_RECURSOS_H

#pragma once
#include "../lista_cursos/lista_cursos.h"
#include "../usuario/usuario.h"

#include <string>

class Administrador_Recursos: public Usuario {
    private:
        Lista_Cursos &cursos_;
    public:
        Administrador_Recursos(Lista_Cursos &cursos): cursos_(cursos), Usuario("admin_cursos", "admin_cursos", "admin_cursos", "admin_cursos@uco.es") {this->cargarAdministrador(); };
        bool cargarAdministrador();
        
        //inline bool addCurso(Curso c) { return cursos_.addCurso(c); };
        //inline bool quitarCurso(Curso c) { return cursos_.quitarCurso(c); };
        //inline bool modificarCurso(Curso c, std::string id) { cursos_.modificarCurso(id, c); };
};

#endif