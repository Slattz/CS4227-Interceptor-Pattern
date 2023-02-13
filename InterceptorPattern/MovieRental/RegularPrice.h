#pragma once
#include "Price.h"

class RegularPrice : public Price {
public:
	MovieType GetPriceCode() const override;
	double GetCharge(int daysRented) const override;
};
#pragma once
