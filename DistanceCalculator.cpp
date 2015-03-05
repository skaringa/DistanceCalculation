#include "DistanceCalculator.h"

DistanceCalculator * DistanceCalculator::getInstance()
{
	return DistanceCalculator::m_theInstance;
}

void DistanceCalculator::use(DistanceCalculator * calc)
{
	DistanceCalculator::m_theInstance = calc;
}

DistanceCalculator * DistanceCalculator::m_theInstance = 0;
