#ifndef REALLYSIMPLEDISTANCECALCULATOR_H_
#define REALLYSIMPLEDISTANCECALCULATOR_H_

#include <cmath>

#include "DistanceCalculator.h"

class ReallySimpleDistanceCalculator : public DistanceCalculator
{
public:
	virtual double distance(const Point & from, const Point & to) const {
		double dx = 71.5 * (from.lon() - to.lon());
		double dy = 111.3 * (from.lat() - to.lat());
		return sqrt(dx * dx + dy * dy);
	};
	
	virtual const char* name() const {
		return "ReallySimple";
	}
};

#endif /*REALLYSIMPLEDISTANCECALCULATOR_H_*/
