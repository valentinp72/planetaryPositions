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
	this->computePrimaryOE();
	this->computeEccentricAnomaly();

	printf("N = %f\n", N.getResult());
	printf("i = %f\n", i.getResult());
	printf("w = %f\n", w.getResult());
	printf("a = %f\n", a.getResult());
	printf("e = %f\n", e.getResult());
	printf("M = %f\n", M.getResult());
	printf("ecl = %f\n", ecl.getResult());
	printf("E = %f\n", E);

	double x = cosd(E) - e.getResult();
	double y = sind(E) * sqrt(1 - (e.getResult()*e.getResult()));

	printf("x = %f\n", x);
	printf("y = %f\n", y);

	double r = sqrt(x*x + y*y);
	double v = Helper::normalizeAngle(atan2d(y, x));
	printf("v = %f\n", v);
	double longitude = Helper::normalizeAngle(v + w.getResult());

	printf("lon = %f\n", longitude);
	printf("r   = %f\n", r);

	x = r * cosd(longitude);
	y = r * sind(longitude);
	double z = 0.0;


	double xequat = x;
	double yequat = y * cosd(ecl.getResult()) - 0.0 * sind(ecl.getResult());
	double zequat = y * sind(ecl.getResult()) + 0.0 * cosd(ecl.getResult());

	double RA  = atan2d(yequat, xequat);
	double Dec = atan2d(zequat, sqrt(xequat * xequat + yequat * yequat));

	printf("RA  = %f\n", RA);
	printf("Dec = %f\n", Dec);

}
