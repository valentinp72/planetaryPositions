#include "Helper.hpp"

double Helper::normalizeAngle(double angle) {
	while(angle < 0) { 
		angle += 360;
	}
	while(angle > 360) {
		angle -= 360;
	}
	return angle;
}
