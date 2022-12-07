#include"estadisticas.h"

Estadisticas::Estadisticas(int participantes, int max_participantes){

	participantes_=participantes;
	max_participantes_=max_participantes;

	float exito=(participantes/max_participantes)*100;

	exito_=exito;
}
