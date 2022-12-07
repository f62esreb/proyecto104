#ifndef ESTADISTICAS_H_
#define ESTADISTICAS_H_


class Estadisticas{
	private:
		float exito_;
		int participantes_, max_participantes_;
	public:
		Estadisticas(int participantes, int max_participantes);

		inline int get_participantes(){return participantes_;};
		inline void set_participantes(int participantes){participantes_=participantes;};

		inline int get_max_participantes(){return max_participantes_;};
		inline void set_max_participantes(int max_participantes){max_participantes_=max_participantes;};

		inline float get_exito(){return exito_;};
		inline void set_exito(float exito){exito_=exito;};

		inline float obtenerExito() { return exito_;} ;
};


#endif
