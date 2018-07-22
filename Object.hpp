#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "OrbitalElement.hpp"

class Object {
	public:
		Object(double day);

		void setPrimaryOEs(
				OrbitalElement * N, 
				OrbitalElement * i, 
				OrbitalElement * w,
				OrbitalElement * a,
				OrbitalElement * e,
				OrbitalElement * M,
				OrbitalElement * ecl);
		void setDay(double day);
		double getDay();

	protected:

		/***********
		 * METHODS *
		 ***********/

		void computePrimaryOE(); // compute primary orbital elements
		void computeRelatedOE(); // compute related orbital elements
		
		void computeEccentricAnomaly();

		/*************
		 * ARGUMENTS *
		 *************/

		double day;

		// Primary Orbital elements
		OrbitalElement * N;   // longitude of the ascending node
		OrbitalElement * i;   // inclination to the ecliptic (plane of the Earth's orbit)
		OrbitalElement * w;   // argument of perihelion
		OrbitalElement * a;   // semi-major axis, or mean distance from Sun
		OrbitalElement * e;   // eccentricity (0=circle, 0-1=ellipse, 1=parabola)
		OrbitalElement * M;   // mean anomaly (0 at perihelion; increases uniformly with time)
		OrbitalElement * ecl; // obliquity of the ecliptic

		// Related Orbital elements
		double E; // eccentric anomaly
};


#endif
