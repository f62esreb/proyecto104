#ifndef LISTA_CURSOS_H
#define LISTA_CURSOS_H

#include <list>
#include <string>
#include "../curso/curso.h"
#include <fstream>

class Lista_Cursos {
    private:
        std::list<Curso> lista_cursos_;
    public:
        inline std::list<Curso> verCursos() { return lista_cursos_; };
        Curso verCurso(std::string id);
        bool addCurso(Curso curso);
        bool quitarCurso(Curso curso);
        bool modificarCurso(std::string id, Curso curso);
        bool guardarCursos();
        bool inscripcion(std::string id, std::string id_usuario);
};


#endif