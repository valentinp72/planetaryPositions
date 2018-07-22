#ifndef ORBITAL_ELEMENTS_HPP
#define ORBITAL_ELEMENTS_HPP

#include <stdio.h>
#include <math.h> 

#include "Helper.hpp"

class OrbitalElement {
	public:
		OrbitalElement(double base, double coefficient, bool positive);
		double compute(double date);
		void   normalizeAngle();
		double getResult();

	private:
		double result;
		double base;
		double coefficient;
		bool positive;
};

#endif
