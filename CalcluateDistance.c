#include "define.h"
#include <math.h>
#include "fpu.h"
#include <stdint.h>
#include <stdio.h>

double haversine;
double temp;
double calculated_distance; 

double CalcGPSDistance (double latitud1, double longitud1, double latitud2, double longitud2) {

        latitud1  *= DegreeToRadiant;
        longitud1 *= DegreeToRadiant;
        latitud2  *= DegreeToRadiant;
        longitud2 *= DegreeToRadiant;
 
        haversine = (pow(sin((1.0 / 2) * (latitud2 - latitud1)), 2)) + ((cos(latitud1)) * (cos(latitud2)) * (pow(sin((1.0 / 2) * (longitud2 - longitud1)), 2)));
        
        if (sqrt(haversine) > 1) {
                temp = 2 * asin(1.0);
        }
        
        else if (sqrt(haversine) < 1) {
                temp = 2 * asin(sqrt(haversine));
        }
        
        calculated_distance = EarthRadius * temp;

        return calculated_distance;
}
