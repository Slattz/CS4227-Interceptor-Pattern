#pragma once
#include "Price.h"

class NewReleasePrice : public Price {
public:
	MovieType GetPriceCode() const override;
	double GetCharge(int daysRented) const override;
	int GetFrequentRenterPoints(int daysRented) const override;
};
