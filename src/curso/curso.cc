#include "curso.h"
#include <list>


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