/*
 * recurso.h
 *
 *  Created on: 27 nov 2022
 *      Author: belenmaria
 */

#ifndef RECURSO_H_
#define RECURSO_H_

#include<string>
#include<list>

class Recurso{

	private:
		std::string id_recurso_;
		std::list<std::string> lista_recursos_;
	public:

		inline std::string get_id(){return id_recurso_;};
		inline void set_id(std::string id_recurso){id_recurso_=id_recurso;};

		bool crearRecurso(std::string id_recurso);
};




#endif /* RECURSO_H_ */
