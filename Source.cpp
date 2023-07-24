#include <iostream>
#include "FlightMap.h"

using namespace std;

int main() {
	FlightMap fm("cityFile.txt", "flightFile.txt");

	fm.displayAllCities();
}