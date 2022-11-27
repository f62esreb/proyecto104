/*
 * recurso.cc
 *
 *  Created on: 27 nov 2022
 *      Author: belenmaria
 */

#include"recurso.h"

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


