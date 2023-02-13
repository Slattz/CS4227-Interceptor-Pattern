#include "Price.h"

MovieType Price::GetPriceCode() const {
	return MovieType::None;
}

double Price::GetCharge(int daysRented) const {
	(void)daysRented;
	return 0;
}

int Price::GetFrequentRenterPoints(int daysRented) const {
	return 1;
}