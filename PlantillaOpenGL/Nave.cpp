#include "stdafx.h"
#include "Nave.h"

Nave::Nave() {
	angulo = 0.0f;
	coordenadas = vec3(0.0f,0.0f,0.0f);
	//Establece el valor como matriz identidad
	transformaciones = mat4(1.0f);

}

void Nave::rotar(Direccion direccion) {
	float rotacion = velocidadAngular;
	if (direccion == Direccion::Derecha) {
		rotacion = -rotacion;
	}
	angulo += rotacion;
	actualizarMatrizTransformacion();
}

void Nave::avanzar() {
	vec3 traslacion = vec3(
		cos(angulo * 3.14159 / 180.0f) * velocidad, //X
		sin(angulo * 3.14159 / 180.0f) * velocidad, //Y
		0.0f
	);
	coordenadas += traslacion;
	actualizarMatrizTransformacion();
}

void Nave::actualizarMatrizTransformacion() {
	//Partir siempre de una matriz identidad
	transformaciones = mat4(1.0f);
	//Aplicar transformaciones
	transformaciones = translate(transformaciones, coordenadas);



}