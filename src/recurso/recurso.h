#ifndef RECURSO_H_
#define RECURSO_H_

#include<string>
#include<list>

class Recurso{

	private:
		std::string id_recurso_,nombre_recurso_;
		std::list<std::string> lista_recursos_;
	public:

		Recurso(std::string id_recurso, std::string nombre_recurso);


		inline std::string get_id(){return id_recurso_;};
		inline void set_id(std::string id_recurso){id_recurso_=id_recurso;};

		inline std::string get_nombre(){return nombre_recurso_;};
		inline void set_nombre(std::string nombre_recurso){nombre_recurso_=nombre_recurso;};

		bool crearRecurso(std::string id_recurso);
};




#endif
