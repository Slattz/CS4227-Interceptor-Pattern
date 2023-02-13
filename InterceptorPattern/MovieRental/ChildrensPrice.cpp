#include "ChildrensPrice.h"

MovieType ChildrensPrice::GetPriceCode() const {
	return MovieType::Children;
}

double ChildrensPrice::GetCharge(int daysRented) const {
	double amount = 1.5;
	if (daysRented > 3)
		amount += (daysRented - 3) * 1.5;
	return amount;
}

