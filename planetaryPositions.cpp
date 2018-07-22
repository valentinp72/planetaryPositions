#include <stdio.h>

#include "Sun.hpp"

int main() {
	double jd = 2458322.447917;
	double  d = jd - 2451543.5;
	Sun sun = Sun(d);	
}
