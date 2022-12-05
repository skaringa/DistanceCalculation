#ifndef SPHEREDISTANCEHAVERSINECALCULATOR_H_
#define SPHEREDISTANCEHAVERSINECALCULATOR_H_

#include <cmath>

#include "DistanceCalculator.h"

class SphereDistanceHaversineCalculator : public DistanceCalculator
{
public:
    virtual double distance(const Point & from, const Point & to) const {

		double lat1 = from.lat() * DEG_TO_RAD;
		double lon1 = from.lon() * DEG_TO_RAD;
		double lat2 = to.lat() * DEG_TO_RAD;
		double lon2 = to.lon() * DEG_TO_RAD;
        double dLat = lat2-lat1;
        double dLon = lon2-lon1;
        double a = pow(sin(dLat/2.0), 2) +
            pow(sin(dLon/2.0), 2) * cos(lat1) * cos(lat2); 
        double c = 2.0 * atan2(sqrt(a),sqrt(1.0-a));
        
		return 6378.388 * c;
	};
	
	virtual const char* name() const {
		return "Haversine";
	};
};

#endif /*SPHEREDISTANCEHAVERSINECALCULATOR_H_*/
