#pragma once
#include "MovieType.h"

class Price {
public:
	virtual MovieType GetPriceCode() const = 0;
	virtual double GetCharge(int daysRented) const = 0;

	virtual int GetFrequentRenterPoints(int daysRented) const;
};


