#ifndef POINT_H_
#define POINT_H_

#include <string>

class Point
{
public:
	Point(double lat, double lon, const std::string & name = "") : m_lat(lat), m_lon(lon), m_name(name)	{};
	virtual ~Point() {};
	virtual double lat() const {return m_lat;};
	virtual double lon() const {return m_lon;};
	
	virtual double distance(const Point & other) const;
	virtual const std::string & name() const;
	
private:
	double m_lat;
	double m_lon;
	std::string m_name;
};

/*
 * Degrees to radians = PI / 180
 */
#define DEG_TO_RAD	0.0174532925199432958

#endif /*POINT_H_*/
