#pragma once
#include <iostream>
using namespace std;
class City
{
private:
	string cityName = "";
	City* adjacentCities = nullptr;
	int numberOfAdjacents = 0;
public:
	City(const string cityName);
	City();
	string getCityName();
	void setCityName(const string cityName);
	void addAdjacent(City& nextCity);
};

