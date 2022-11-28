#include "lista_cursos.h"


Curso Lista_Cursos::verCurso(std::string id) { 
    Curso c;
    for ( Curso c : lista_cursos_ ) {
        if ( c.get_id() == id ) { 
            return c;
        }
    }

    return c;
}

bool Lista_Cursos::addCurso(Curso curso) {
    for ( Curso c : lista_cursos_ ) {
        if ( c.get_id() == curso.get_id() ) { 
            return false;
        }
    }

    return true;
}

bool Lista_Cursos::quitarCurso(Curso curso) {
    for ( auto it = lista_cursos_.begin(); it != lista_cursos_.end(); it++ ) {
        if ( it->get_id() == curso.get_id() ) { 
            it = lista_cursos_.erase(it);
            return true;
        }
    }

    return false;
}

bool Lista_Cursos::modificarCurso(std::string id, Curso curso) {
    for ( auto it = lista_cursos_.begin(); it != lista_cursos_.end(); it++ ) {
        if ( it->get_id() == id ) { 
            *it = curso;
            return true;
        }
    }

    return false;
}