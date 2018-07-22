#include "Object.hpp"


Object::Object(double day) {
	this->setDay(day);
}

void Object::setPrimaryOEs(
	OrbitalElement * N, 
	OrbitalElement * i, 
	OrbitalElement * w,
	OrbitalElement * a,
	OrbitalElement * e,
	OrbitalElement * M,
	OrbitalElement * ecl) {
		this->N   = N;
		this->i   = i;
		this->w   = w;
		this->a   = a;
		this->e   = e;
		this->M   = M;
		this->ecl = ecl;
}

void Object::setDay(double day) {
	this->day = day;
}

double Object::getDay() {
	return this->day;
}

void Object::computePrimaryOE() {
	N->compute(day);
	i->compute(day);
	w->compute(day);
	a->compute(day);
	e->compute(day);
	M->compute(day);
	ecl->compute(day);
	
	N->normalizeAngle();
	w->normalizeAngle();
	M->normalizeAngle();
}


void Object::computeEccentricAnomaly() {
	this->E = M->getResult() + (180 / M_PI) * e->getResult() * sind(M->getResult()) * (1 + e->getResult() * cosd(M->getResult()));
}
