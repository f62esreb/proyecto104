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
	}

	lista_cursos_.push_back(id_curso);
	this->guardarCursos();

	return true;
}

bool Usuario::cargarCursos() { 
	std::ifstream input("usuario_" + id_usuario_ + ".txt");
	std::string numero;

    if (!input.is_open()) {
        std::ofstream input("usuario_" + id_usuario_ + ".txt");
		input.close();
		this->guardarCursos();
		return false;
	}

    if (input.peek() == 0) {
		input.close();
		this->guardarCursos();
        return false;
    }

	getline(input, numero);

	for (int i = 0; i < std::stoi(numero); i++) {
		std::string id;
		getline(input, id);
		if (id.size() > 0) {
			lista_cursos_.push_back(id);
        }
	}

	input.close();

	return true;
}


bool Usuario::guardarCursos()
{
	std::ofstream input("usuario_" + id_usuario_ + ".txt");

	input << lista_cursos_.size() << std::endl;
	for(std::string id : lista_cursos_)
	{
		input << id << "\n";
	}

	input.close();

    return true;
}
