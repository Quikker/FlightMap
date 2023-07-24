#pragma once
#include <iostream>
#include "City.h"
using namespace std;
class FlightMap {
private:
	string cityFile;
	string flightFile;

	City* cities;
	int numberOfCities;

public:
	FlightMap(const string cityFile, const string flightFile);
	~FlightMap();
	void displayAllCities() const;
	void displayAdjacentCities(const string cityName) const;
	void displayFlightMap() const;
	void findFlights(const string deptCity, const string destCity);
	void loadCities(const string cityFile);
	void loadFlights(const string flightFile);
	void createAdjacency(const string baseCityName, const string adjeCityName);

};

/*

The homework description says "You MUST use the nonrecursive solution using a stack 
to implement the search algorithm for finding the paths between the cities as discussed in the class. 
You will get no points if you use any other algorithm for the solution of the search problem." 
You can (and should) modify the algorithm given in the slides and the book, 
but basically it must be a non-recursive exhaustive search using a stack.



*/