#pragma once

#include <string>
#include "Price.h"
#include "MovieType.h"

class Movie
{
public:
	Movie(const std::string& title, MovieType movieType);

	std::string GetTitle() const;
	double GetCharge(int daysRented) const;
	int GetFrequentRenterPoints(int daysRented) const;

private:
	std::string m_title;
	Price* m_price;

	void SetPriceCode(MovieType movieType);
	MovieType GetPriceCode() const;
};
