/*
 * estadisticas.cc
 *
 *  Created on: 25 nov 2022
 *      Author: belenmaria
 */

#include"estadisticas.h"

Estadisticas::Estadisticas(int participantes, int max_participantes){

	participantes_=participantes;
	max_participantes_=max_participantes;

	float exito=(participantes/max_participantes)*100;

	exito_=exito;
}

