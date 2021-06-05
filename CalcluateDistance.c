#include "define.h"
#include <math.h>
#include "fpu.h"
#include <stdint.h>
#include <stdio.h>

double haversine;
double temp;
double distance; 

double CalcGPSDistance(float latitud1, float longitud1, float latitud2, float longitud2){

        latitud1  *= DegreeToRadiant;
        longitud1 *= DegreeToRadiant;
        latitud2  *= DegreeToRadiant;
        longitud2 *= DegreeToRadiant;
 
    haversine = (pow(sin((1.0 / 2) * (latitud2 - latitud1)), 2)) + ((cos(latitud1)) * (cos(latitud2)) * (pow(sin((1.0 / 2) * (longitud2 - longitud1)), 2)));
    temp = 2 * asin(sqrt(haversine));
    distance = EarthRadius * temp;

    return distance;
}
