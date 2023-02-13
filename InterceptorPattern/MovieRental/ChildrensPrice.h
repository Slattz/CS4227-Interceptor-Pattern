#pragma once
#include "Price.h"

class ChildrensPrice : public Price {
public:
	MovieType GetPriceCode() const override;
	double GetCharge(int daysRented) const override;
};

