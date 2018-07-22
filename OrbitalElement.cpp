#include "OrbitalElement.hpp"

OrbitalElement::OrbitalElement(double base, double coefficient, bool positive) {
	this->base        = base;
	this->coefficient = coefficient;
	this->positive    = positive;
}

double OrbitalElement::compute(double date) {
	if(coefficient != 0.0) {
		long double factor = coefficient * date;
		result = (positive) ? base + factor : base - factor;
	}
	else {
		result = base;
	}

	return result;
}

void OrbitalElement::normalizeAngle() {
	if(result < 0 || result > 360) {
		result = result - floor(result / 360.0) * 360.0;	
	}
}

double OrbitalElement::getResult() {
	return result;
}
