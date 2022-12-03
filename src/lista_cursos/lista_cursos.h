#ifndef LISTA_CURSOS_H
#define LISTA_CURSOS_H

#include <list>
#include <string>
#include "../curso/curso.h"

class Lista_Cursos {
    private:
        std::list<Curso> lista_cursos_;
    public:
        inline std::list<Curso> verCursos() { return lista_cursos_; };
        Curso verCurso(std::string id);
        bool addCurso(Curso curso);
        bool quitarCurso(Curso curso);
        bool modificarCurso(std::string id, Curso curso);
};


#endif