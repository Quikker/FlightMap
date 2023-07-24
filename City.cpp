#include "City.h"

City::City(const string cityName) :cityName(cityName)
{
}

City::City()
{
}

void City::setCityName(const string cityName)
{
	this->cityName = cityName;
}

string City::getCityName()
{
	return cityName;
}

void City::addAdjacent(City& nextCity)
{
	if (numberOfAdjacents == 0)
	{
		adjacentCities = new City[++numberOfAdjacents];
		adjacentCities[0] = nextCity;
	}
}

