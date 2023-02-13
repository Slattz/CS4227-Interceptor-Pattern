#pragma once
#include "Movie.h"


class Rental
{
public:
	Rental(Movie& movie, int daysRented);
	Movie GetMovie() const;
	int GetDaysRented() const;
	double GetCharge() const;
	int GetFrequentRenterPoints() const;

private:
	Movie m_movie;
	int m_daysRented;
};
