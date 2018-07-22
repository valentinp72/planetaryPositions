#include "OrbitalElement.hpp"

OrbitalElement::OrbitalElement(double base, double coefficient, bool positive) {
	this->base        = base;
	this->coefficient = coefficient;
	this->positive    = positive;
}

double OrbitalElement::compute(double date) {
	if(coefficient != 0.0) {
		double factor = coefficient * date;
		result = (positive) ? base + factor : base - factor;
	}
	else {
		result = base;
	}

	return result;
}

void OrbitalElement::normalizeAngle() {
	result = Helper::normalizeAngle(result);
}

double OrbitalElement::getResult() {
	return result;
}
