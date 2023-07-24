#include "FlightMap.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

FlightMap::FlightMap(const string cityFile, const string flightFile): cityFile(cityFile), flightFile(flightFile)
{
	loadCities(cityFile);
	loadFlights(flightFile);
	cout << "9 cities and 11 flights have been loaded. \n";
}

FlightMap::~FlightMap()
{
}

void FlightMap::displayAllCities() const
{
	cout << "The list of the cities that HPAir serves is given below: \n";
	for (int i = 0; i < numberOfCities; i++)
	{
		City elementCity = cities[i];
		cout << elementCity.getCityName() <<" ";
	}
}

void FlightMap::displayAdjacentCities(const string cityName) const
{
}

void FlightMap::displayFlightMap() const
{
}

void FlightMap::findFlights(const string deptCity, const string destCity)
{
}

void FlightMap::loadCities(const string cityFile)
{
	ifstream inputFile;
	string sa;

	inputFile.open(cityFile, ios_base::in);

	while (getline(inputFile, sa)) {
		if (numberOfCities == 0)
		{
			cities = new City[++numberOfCities];
			cities[0].setCityName(sa);
		}
		else
		{
			City* newCities = new City[numberOfCities + 1];

			for (int i = 0; i < numberOfCities; i++)
			{
				newCities[i] = cities[i];
			}
			newCities[numberOfCities++].setCityName(sa);
			delete[] cities;
			cities = newCities;
			newCities = nullptr;
		}

	}
}


void FlightMap::loadFlights(const string flightFile)
{
	ifstream inputFile;
	string sa;
	string delimiter = ";";

	int flightID;
	int flightCost;

	inputFile.open(flightFile, ios_base::in);

	while (getline(inputFile, sa)) {

		string base = sa.substr(0, sa.find(delimiter));
		sa.erase(0, sa.find(delimiter) + delimiter.length());
		string adje = sa.substr(0, sa.find(delimiter));

		createAdjacency(base, adje);

		cout << "Base: " << base << "\t" << "Adjacent: " << adje << endl;
		/*
		if (numberOfCities == 0)
		{
			cities = new City[numberOfCities + 1];
			cities[0].setCityName(sa);
			numberOfCities++;
		}
		else
		{
			City* newCities = new City[numberOfCities + 1];

			for (int i = 0; i < numberOfCities; i++)
			{
				newCities[i] = cities[i];
			}
			newCities[numberOfCities++].setCityName(sa);
			delete[] cities;
			cities = newCities;
			newCities = nullptr;
		}
		*/
	}
}

void FlightMap::createAdjacency(const string baseCityName, const string adjeCityName)
{
	int positionOfBase = -1; 
	int positionOfAdje = -1; 
	for(int i = 0; i<<numberOfCities; i++)
	{
		City item = cities[i];

		if (item.getCityName() == baseCityName && positionOfBase == -1)
		{
			positionOfBase = i;
		}

		if (item.getCityName() == adjeCityName && positionOfAdje == -1)
		{
			positionOfAdje = i;
		}

		if (positionOfBase != -1 && positionOfAdje != -1) {
			break; // Both items found
		}
	}

}