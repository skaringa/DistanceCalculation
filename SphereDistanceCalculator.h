#ifndef SPHEREDISTANCECALCULATOR_H_
#define SPHEREDISTANCECALCULATOR_H_

#include <cmath>

#include "DistanceCalculator.h"

class SphereDistanceCalculator : public DistanceCalculator
{
public:
	virtual double distance(const Point & from, const Point & to) const {
		double lat1 = from.lat() * DEG_TO_RAD;
		double lon1 = from.lon() * DEG_TO_RAD;
		double lat2 = to.lat() * DEG_TO_RAD;
		double lon2 = to.lon() * DEG_TO_RAD;
		return 6378.388 * acos(sin(lat1) * sin(lat2) 
			+ cos(lat1) * cos(lat2) * cos(lon2 - lon1));
	};
	
	virtual const char* name() const {
		return "Sphere";
	};
};

#endif /*SPHEREDISTANCECALCULATOR_H_*/
