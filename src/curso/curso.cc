#include "curso.h"
#include <list>
#include <iostream>
#include <fstream>

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

        this->guardarListaParticipantes();

        return true;
    } else {
        return false;
    }
}

bool Curso::quitarInscripcion(std::string id_usuario) {
    for (auto it = id_participantes_.begin(); it != id_participantes_.end(); it++) {
        if ( *it == id_usuario ) {
            it = id_participantes_.erase(it);
            this->guardarListaParticipantes();
            return true;
        }
    }

    return false;
}

bool Curso::cargarListaParticipantes() { 
	std::ifstream input("curso_" + id_ + ".txt");
    std::string numero;

    if (!input.is_open()) {
        std::ofstream input("curso_" + id_ + ".txt");
		input.close();
        this->guardarListaParticipantes();
		return false;
	}

    if (input.peek() == 0) {
		input.close();
        this->guardarListaParticipantes();
        return false;
    }

    getline(input, numero);

	for (int i = 0; i < std::stoi(numero); i++) {
		std::string id;
		getline(input, id);
        if (id.size() > 0) {
            id_participantes_.push_back(id);
        }
	}

	input.close();

	return true;
}

bool Curso::guardarListaParticipantes()
{
    std::ofstream input("curso_"+ id_ +".txt");
    input << id_participantes_.size() << std::endl;

    for(std::string id : id_participantes_)
    {
        input << id << "\n";
    }
    
    input.close();

    return true;
}