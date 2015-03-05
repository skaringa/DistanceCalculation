#include "Point.h"
#include "DistanceCalculator.h"

double Point::distance(const Point & other) const
{
	return DistanceCalculator::getInstance()->distance(*this, other);
}

const std::string & Point::name() const
{
	return m_name;
}
