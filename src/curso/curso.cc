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
		getline(input, id);std::ifstream input("curso_" + id_ + ".txt");
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

bool Curso::addRecurso(Recurso R)
{
    for ( Recurso r : recursos_ ) {
        if ( r.get_id_recurso() == R.get_id_recurso() ) { 
            return false;
        }
    }

    recursos_.push_back(R);
    this -> guardarListaRecursos();
    return true;
}

Recurso Curso::quitarRecurso(std::string id)
{
    Recurso R ("empty",Tipo::CAMARA);
    for ( auto it = recursos_.begin(); it != recursos_.end(); it++ ) {
        if ( it->get_id_recurso() == id ) { 
            Recurso R(it->get_id_recurso(),it-> get_recurso(),
            it->get_calidad_imagen(), it->get_brillo(),it->get_aforo());
            
            it = recursos_.erase(it);
            this -> guardarListaRecursos();
            return R;
        }
    }

    return R;
}

bool Curso::cargarListaRecursos()
{
    std::ifstream input("recursos_" + id_ + ".txt");
    std::string numero;

    if (!input.is_open()) {
        std::ofstream input("recursos_" + id_ + ".txt");
		input.close();
        this->guardarListaRecursos();
		return false;
	}

    if (input.peek() == 0) {
		input.close();
        this->guardarListaRecursos();
        return false;
    }

    getline(input, numero);

	for (int i = 0; i < std::stoi(numero); i++) {

        std::string id;
        std::string tipo;
        std::string aux;
        Tipo t;

        getline(input, id);
        getline(input, tipo);
        getline(input, aux);

        if(stoi(tipo)==1)
        {
            Recurso R(id , Tipo::CAMARA);
            R.set_calidad_imagen(stoi(aux));
            recursos_.push_back(R);
        }
        else if(stoi(tipo)==2)
        {
            Recurso R(id , Tipo::PROYECTOR);
            R.set_brillo(stoi(aux));
            recursos_.push_back(R);
        }
        else if(stoi(tipo)==3)
        {
            Recurso R(id, Tipo::AULA);
            R.set_aforo(stoi(aux));
            recursos_.push_back(R);
        }
        else
        {
            std::cout<<"Error"<<std::endl;
            return false;
        }

	}


	input.close();

	return true;
}


bool Curso::guardarListaRecursos()
{
    std::ofstream input("recursos_"+ id_ +".txt");
    input << recursos_.size() << std::endl;


    for(Recurso R : recursos_)
    {
        
        input << R.get_id_recurso() << "\n";
        Tipo tipo = R.get_recurso();
        switch (tipo)
        {
        case Tipo:: CAMARA:
            input << 1 << std::endl;
            input << R.get_calidad_imagen()<< std::endl;
            break;
        case Tipo:: PROYECTOR:
            input << 2 << std::endl;
            input << R.get_brillo()<< std::endl;
            break;
        case Tipo:: AULA:
            input << 3 << std::endl;
            input << R.get_aforo() << std::endl;
        }
        
    }
    
    input.close();

    return true;
}