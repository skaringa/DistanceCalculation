#include <string>
#include <list>
#include <iostream>
#include <iomanip>

#include "Point.h"
#include "DistanceCalculator.h"
#include "ReallySimpleDistanceCalculator.h"
#include "SimpleDistanceCalculator.h"
#include "SphereDistanceCalculator.h"
#include "GeodDistanceCalculator.h"

using namespace std;

static void compareDistanceCalculators(Point & p1, Point & p2, list<DistanceCalculator*> & calcs) 
{
	cout << "Distance " << p1.name() << " - " << p2.name() << ": " << endl;

	list<DistanceCalculator*>::const_iterator ical;
	for (ical = calcs.begin(); ical != calcs.end(); ++ical) {
		DistanceCalculator::use(*ical);
		cout << setw(12) << (*ical)->name() << ": ";
		cout << setw(8) << setprecision(3) << fixed << p1.distance(p2) << " km" << endl;
	}	
}

int main()
{
	list<DistanceCalculator*> calcs;
	calcs.push_back(new ReallySimpleDistanceCalculator());
	calcs.push_back(new SimpleDistanceCalculator());
	calcs.push_back(new SphereDistanceCalculator());
	calcs.push_back(new GeodDistanceCalculator());

	Point rue1(49.9917, 8.41321, "Ruesselsheim Station");
	Point rue2(50.0049, 8.42182, "Ruesselsheim Opel bridge");
	compareDistanceCalculators(rue1, rue2, calcs);
	
	Point berlin(52.5164, 13.3777, "Berlin Brandenburg Gate");
	Point lissabon(38.692668, -9.177944, "Lisbon Tagus bridge");
	compareDistanceCalculators(berlin, lissabon, calcs);
}
