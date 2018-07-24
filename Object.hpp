#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "OrbitalElement.hpp"

class Object {
	public:
		Object(double day);
		void computeAll();

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

		double getRA();
		double getDec();

	protected:

		/***********
		 * METHODS *
		 ***********/

		void computePrimaryOE(); // compute primary orbital elements
		void computeRelatedOE(); // compute related orbital elements
		
		void computeEccentricAnomaly();
		void computeRectangularCoordinates();
		void computeTrueAnomaly();
		void computeDistance();
		void computeLongitude();
		void computeGeocentricCoords();
		void computeEquatorialCoords();
		void computeRADec();


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
		double E;      // eccentric anomaly
		double x;      // x rectangular coordinate
		double y;      // y rectangular coordinate
		double z;      // z rectangular coordinate
		double v;      // true anomaly
		double r;      // distance
		double lon;    // longitude
		double xequat; // x equatorial coordinate
		double yequat; // y equatorial coordinate
		double zequat; // z equatorial coordinate
		double RA;     // Right Ascension
		double Dec;    // Declination
};


#endif
