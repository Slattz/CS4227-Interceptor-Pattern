#pragma once
#include <string>
#include <vector>
#include "Rental.h"

class Customer
{
public:
	Customer(std::string name);
	std::string GetName() const;
	void AddRental(Rental& rental);
	std::string Statement() const;
	std::string HtmlStatement() const;


private:
	std::string m_name;
	std::vector<Rental> m_rentals;

	double GetTotalCharge() const;
	int GetTotalFrequentRenterPoints() const;
};
