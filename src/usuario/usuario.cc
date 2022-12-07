/*
 * usuario.cc
 *
 *  Created on: 25 nov 2022
 *      Author: belenmaria
 */
#include"usuario.h"

Usuario::Usuario(std::string id_usuario, std::string nombre, std::string password, std::string correo){
	id_usuario_=id_usuario;
	nombre_=nombre;
	password_=password;
	correo_=correo;
}

bool Usuario::inscribirseCurso(std::string id_curso){
	for (auto it = lista_cursos_.begin(); it != lista_cursos_.end(); it++) {
	        if ( *it == id_curso ) {
	            return false;
	        }
	        else{
	        	lista_cursos_.push_back(id_curso);
	        	return true;
	        }

	}
return false;
}

bool Usuario::cargarCursos() { 
	std::ifstream input("usuario_" + id_usuario_);

    if (!input.is_open()) {
        std::ofstream input("usuario_" + id_usuario_ + ".txt");
		input.close();
		return false;
	}

    if (input.peek() == 0) {
		input.close();
        return false;
    }

	while (!input.eof()) {
		std::string id;
		getline(input, id);
		lista_cursos_.push_back(id);
	}

	input.close();

	return true;
}

