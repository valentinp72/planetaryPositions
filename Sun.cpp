#include "Sun.hpp"

Sun::Sun(
		double day
) : Object(day) {
	OrbitalElement N = OrbitalElement(0.0, 0.0, true);
	OrbitalElement i = OrbitalElement(0.0, 0.0, true);
	OrbitalElement w = OrbitalElement(282.9404, 4.70935E-5, true);
	OrbitalElement a = OrbitalElement(1.0, 0.0, true);
	OrbitalElement e = OrbitalElement(0.016709, 1.151E-9, false);
	OrbitalElement M = OrbitalElement(356.0470, 0.9856002585, true);
	OrbitalElement ecl = OrbitalElement(23.4393, 3.563E-7, false);
	this->setPrimaryOEs(&N, &i, &w, &a, &e, &M, &ecl);

	computeAll();

	printf("RA  = %f\n", getRA());
	printf("Dec = %f\n", getDec());

}
