#ifndef HELPER_HPP
#define HELPER_HPP

#include <math.h>
#define RADEG       (180.0/M_PI)
#define DEGRAD      (M_PI/180.0)
#define sind(x)     sin((x)*DEGRAD)
#define cosd(x)     cos((x)*DEGRAD)
#define tand(x)     tan((x)*DEGRAD)
#define asind(x)    (RADEG*asin(x))
#define acosd(x)    (RADEG*acos(x))
#define atand(x)    (RADEG*atan(x))
#define atan2d(y,x) (RADEG*atan2((y),(x)))

class Helper {
	public:
		static double normalizeAngle(double angle);
		static double degreesToRadians(double degrees);
};

#endif
