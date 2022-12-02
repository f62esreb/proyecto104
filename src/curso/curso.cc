#include "curso.h"
#include <list>


Curso::Curso(std::string id, std::string nombre, std::string descripcion, time_t fecha_inicio, time_t fecha_fin, std::string correo_admin_curso,
             std::string ponentes, std::string requisitos, int participantes, int max_participantes){
    
    id_=id;
    nombre_=nombre;
    descripcion_=descripcion;
    fecha_inicio_=fecha_inicio;
    fecha_fin_=fecha_fin;
    correo_admin_curso_=correo_admin_curso;
    ponentes_=ponentes;
    requisitos_=requisitos;
    participantes_=participantes;
    max_participantes_=max_participantes;
          
}

bool Curso::addInscripcion(std::string id_usuario) {
    if ( participantes_ < max_participantes_ ) {
        id_participantes_.push_back(id_usuario);
        participantes_++;
        return true;
    } else {
        return false;
    }
}

bool Curso::quitarInscripcion(std::string id_usuario) {
    for (auto it = id_participantes_.begin(); it != id_participantes_.end(); it++) {
        if ( *it == id_usuario ) {
            it = id_participantes_.erase(it);
            return true;
        }
    }

    return false;
}
