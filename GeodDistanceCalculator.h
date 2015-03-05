#ifndef GEODDISTANCECALCULATOR_H_
#define GEODDISTANCECALCULATOR_H_

#include "DistanceCalculator.h"

class GeodDistanceCalculator : public DistanceCalculator
{
public:
	virtual double distance(const Point & from, const Point & to) const;
	
	virtual const char* name() const {
		return "Geod";
	};
};

#endif /*GEODDISTANCECALCULATOR_H_*/
