#include "lista_cursos.h"
#include <iostream>

Curso Lista_Cursos::verCurso(std::string id) { 
    Curso empty("none", "none", "none", 0, 0, "none", "none", "none", 0, 0);
    
    for ( Curso c : lista_cursos_ ) {
        if ( c.get_id() == id ) { 
            return c;
        }
    }

    return empty;
}

bool Lista_Cursos::addCurso(Curso curso) {
    for ( Curso c : lista_cursos_ ) {
        if ( c.get_id() == curso.get_id() ) { 
            return false;
        }
    }

    lista_cursos_.push_back(curso);
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