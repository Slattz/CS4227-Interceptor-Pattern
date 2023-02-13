#include "RegularPrice.h"

MovieType RegularPrice::GetPriceCode() const {
	return MovieType::NewRelease;
}

double RegularPrice::GetCharge(int daysRented) const {
	return daysRented * 3;
}
