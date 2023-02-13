#include "NewReleasePrice.h"

MovieType NewReleasePrice::GetPriceCode() const {
	return MovieType::NewRelease;
}

double NewReleasePrice::GetCharge(int daysRented) const {
	return daysRented * 3;
}

int NewReleasePrice::GetFrequentRenterPoints(int daysRented) const {
	if (daysRented > 1)
		return 2;
	return 1;
}
