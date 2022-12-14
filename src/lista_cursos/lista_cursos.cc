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
            this->guardarCursos();
            
            return true;
        }
    }

    return false;
}

bool Lista_Cursos::modificarCurso(std::string id, Curso curso) {
    for ( auto it = lista_cursos_.begin(); it != lista_cursos_.end(); it++ ) {
        if ( it->get_id() == id ) { 
            *it = curso;
            
            this->guardarCursos();
            return true;
        }
    }

    return false;
}

bool Lista_Cursos :: guardarCursos()
{
    std::ofstream input("cursos.txt");

    input << lista_cursos_.size() << "\n";

    for ( Curso c : lista_cursos_ ) 
    {
        input << c.get_id()<< "\n";
        input << c.get_nombre()<< "\n";
        input << c.get_descripcion()<< "\n";
        input << c.get_fecha_inicio()<< "\n";
        input << c.get_fecha_fin()<< "\n";
        input << c.get_correo_admin_curso()<< "\n";
        input << c.get_ponentes()<< "\n";
        input << c.get_requisitos()<< "\n";
        input << c.get_participantes()<< "\n";
        input << c.get_max_participantes()<< "\n";
        input << "\n";
    }

    input.close();

    return true;
}

bool Lista_Cursos :: inscripcion(std::string id, std::string id_usuario){
    for (Curso& c: lista_cursos_){
        if(c.get_id() == id){
            if (c.addInscripcion(id_usuario)) {
                this->guardarCursos();
                return true;
            }
        }
    }

    return false;
}
