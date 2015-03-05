#include <sstream>
#include <iostream>
#ifndef _WIN32
#include <unistd.h>
#include <stdlib.h>
#endif

#include "GeodDistanceCalculator.h"

using namespace std;

/*
 * Call the geod program to calculate the distance for the WGS84 ellipsoid. 
 * This works only under Unix and requires to install the package proj-bin.
 */ 
double GeodDistanceCalculator::distance(const Point & from, const Point & to) const
{
#ifndef _WIN32
	stringstream pin, pout;
	string s1, s2;
	double dist;
	char outbuf[256];
	int fdin[2], fdout[2];
	
	pipe(fdin);
	pipe(fdout);
	if (0 == fork()) {
		/* child */
		dup2(fdin[0], 0);
		close(fdin[1]);
		dup2(fdout[1], 1);
		close(fdout[0]);
		execlp("/usr/bin/geod", "geod", "+ellps=WGS84", "+units=km", "-I", (char *)NULL);
        cerr << "execlp geod failed" << endl;
        exit(1);
	}
	/* parent */
    close(fdin[0]);
    close(fdout[1]);
    
    pin << from.lat() << " " << from.lon() << " " << to.lat() << " " << to.lon() << endl;
    write(fdin[1], pin.str().c_str(), pin.str().length());
    close(fdin[1]);
    
    read(fdout[0], outbuf, 255);
    close(fdout[0]);

    pout << outbuf;
    pout >> s1 >> s2 >> dist;
    
    return dist;
#else
	return -1;
#endif
}
