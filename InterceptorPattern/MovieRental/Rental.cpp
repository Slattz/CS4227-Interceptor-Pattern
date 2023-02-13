#include "Rental.h"

Rental::Rental(Movie& movie, int daysRented) : m_movie(movie), m_daysRented(daysRented) { }

Movie Rental::GetMovie() const {
	return m_movie;
}

int Rental::GetDaysRented() const {
	return m_daysRented;
}

double Rental::GetCharge() const {
	return m_movie.GetCharge(m_daysRented);
}

int Rental::GetFrequentRenterPoints() const {
	return m_movie.GetFrequentRenterPoints(m_daysRented);
}