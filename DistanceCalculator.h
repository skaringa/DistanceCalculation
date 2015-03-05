#ifndef DISTANCECALCULATOR_H_
#define DISTANCECALCULATOR_H_

#include "Point.h"

class DistanceCalculator
{
public:
	static DistanceCalculator * getInstance();
	static void use(DistanceCalculator * calc);
	
	virtual double distance(const Point & from, const Point & to) const = 0;
	virtual const char* name() const = 0; 
	
private:
	static DistanceCalculator * m_theInstance;
};

#endif /*DISTANCECALCULATOR_H_*/
