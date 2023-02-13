#pragma once
#include "MovieType.h"

class Price {
public:
	virtual MovieType GetPriceCode() const;
	virtual double GetCharge(int daysRented) const;

	virtual int GetFrequentRenterPoints(int daysRented) const;
};


