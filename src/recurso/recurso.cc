#include"recurso.h"

Recurso::Recurso(std::string id_recurso, std::string nombre_recurso){
	id_recurso_=id_recurso;
	nombre_recurso_=nombre_recurso;
}

bool Recurso::crearRecurso(std::string id_recurso){
	for (auto it = lista_recursos_.begin(); it != lista_recursos_.end(); it++) {
	        if ( *it == id_recurso ) {
	            return false;
	        }
	        else{
	        	lista_recursos_.push_back(id_recurso);
	        	return true;
	        }

	}
return false;
}
