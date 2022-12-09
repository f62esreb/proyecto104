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

bool Lista_Cursos :: guardarCursos()
{
    std::ofstream input("cursos.txt");

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
    for (Curso c: lista_cursos_){
        if(c.get_id()==id){
            c.addInscripcion(id_usuario);
            std::cout<<"La inscripcion se ha realizado con exito.";
            return true;
        }
        else{
            std::cout<<"Error al realizar la inscripcion.";
            return false;
        }
    }
    return false;
}
