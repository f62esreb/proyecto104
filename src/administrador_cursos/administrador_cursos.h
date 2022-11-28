#ifndef ADMININSTRADOR_CURSOS_H
#define ADMININSTRADOR_CURSOS_H


#include "lista_cursos.h"
#include "usuario.h"
#include "curso.h"
#include <string>

class Admininstrador_Cursos: public Usuario {
    private:
        Lista_Cursos &cursos_;
    public:
        Admininstrador_Cursos(Usuario u, Lista_Cursos &cursos): cursos_(cursos), Usuario(u.get_id_usuario(), u.get_name(), u.get_password(), u.get_correo()) {};
        inline bool addCurso(Curso c) { return cursos_.addCurso(c); };
        inline bool quitarCurso(Curso c) { return cursos_.quitarCurso(c); };
        inline bool modificarCurso(Curso c, std::string id) { cursos_.modificarCurso(id, c); };
};

#endif