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

double Object::getRA() {
	return this->RA;
}

double Object::getDec() {
	return this->Dec;
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

void Object::computeRelatedOE() {

}

void Object::computeEccentricAnomaly() {
	this->E = M->getResult() + (180 / M_PI) * e->getResult() * sind(M->getResult()) * (1 + e->getResult() * cosd(M->getResult()));
}

void Object::computeRectangularCoordinates() {
	this->x = cosd(E) - e->getResult();
	this->y = sind(E) * sqrt(1 - (e->getResult() * e->getResult()));
}

void Object::computeTrueAnomaly() {
	this->v = Helper::normalizeAngle(atan2d(y, x));
}

void Object::computeDistance() {
	this->r = sqrt(x*x + y*y);
}

void Object::computeLongitude() {
	this->lon = Helper::normalizeAngle(v + w->getResult());
}

void Object::computeGeocentricCoords() {
	this->x = r * cosd(lon);
	this->y = r * sind(lon);
	this->z = 0.0;
}

void Object::computeEquatorialCoords() {
	this->xequat = x;
	this->yequat = y * cosd(ecl->getResult()) - 0.0 * sind(ecl->getResult());
	this->zequat = y * sind(ecl->getResult()) + 0.0 * cosd(ecl->getResult());
}

void Object::computeRADec() {
	this->RA  = atan2d(yequat, xequat);
	this->Dec = atan2d(zequat, sqrt(xequat * xequat + yequat * yequat));
}
	

void Object::computeAll() {
	computePrimaryOE();
	computeRelatedOE();
	computeEccentricAnomaly();
	computeRectangularCoordinates();
	computeTrueAnomaly();
	computeDistance();
	computeLongitude();
	computeGeocentricCoords();
	computeEquatorialCoords();
	computeRADec();
}
