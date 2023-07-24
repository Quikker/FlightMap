#pragma once
#include "City.h"
class Flight
{
private:
	City baseCity;
	City nextCity;

	int flightID;
	int flightCost;
public:
	Flight(const City baseCity, const City nextCity, const int flightID, const int flightCost);
};

