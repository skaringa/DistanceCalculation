#ifndef SIMPLEDISTANCECALCULATOR_H_
#define SIMPLEDISTANCECALCULATOR_H_

#include <cmath>

#include "DistanceCalculator.h"

class SimpleDistanceCalculator : public DistanceCalculator
{
public:
	virtual double distance(const Point & from, const Point & to) const {
		double lat1 = (from.lat() + to.lat()) / 2 * DEG_TO_RAD;
		double dx = 111.3 * cos(lat1) * (from.lon() - to.lon());
		double dy = 111.3 * (from.lat() - to.lat());
		return sqrt(dx * dx + dy * dy);
	};
	
	virtual const char* name() const {
		return "Simple";
	};
};

#endif /*SIMPLEDISTANCECALCULATOR_H_*/
