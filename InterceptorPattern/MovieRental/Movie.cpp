#include "Movie.h"
#include "RegularPrice.h"
#include "NewReleasePrice.h"
#include "ChildrensPrice.h"
#include <exception>

Movie::Movie(const std::string& title, MovieType movieType) : m_title(title) {
	SetPriceCode(movieType);
}

void Movie::SetPriceCode(MovieType movieType) {
	switch (movieType) {
	case MovieType::Regular:
		m_price = new RegularPrice();
		break;

	case MovieType::NewRelease:
		m_price = new NewReleasePrice();
		break;

	case MovieType::Children:
		m_price = new ChildrensPrice();
		break;
	
	default:
		throw std::exception("invalid price code");
		break;
	}
}

MovieType Movie::GetPriceCode() const {
	return m_price->GetPriceCode();
}

std::string Movie::GetTitle() const {
	return m_title;
}

double Movie::GetCharge(int daysRented) const {
	return m_price->GetCharge(daysRented);
}

int Movie::GetFrequentRenterPoints(int daysRented) const {
	return m_price->GetFrequentRenterPoints(daysRented);
}
