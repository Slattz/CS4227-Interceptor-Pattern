#include "Customer.h"

Customer::Customer(std::string name) : m_name(name) { }

std::string Customer::GetName() const {
	return m_name;
}

void Customer::AddRental(Rental& rental) {
	m_rentals.push_back(rental);
}

std::string Customer::Statement() const {
	std::string result = "Rental record for " + this->GetName() + "\n";
	for (const Rental& rental : m_rentals)
		result += "\t" + rental.GetMovie().GetTitle() + "\t" + std::to_string(rental.GetCharge()) + "\n";

	result += "Amount owed is " + std::to_string(this->GetTotalCharge()) + "\n";
	result += "You earned " + std::to_string(this->GetTotalFrequentRenterPoints()) + " frequent renter points";
	return result;
}

std::string Customer::HtmlStatement() const {
	std::string result = "<h1>Rental record for <b>" + this->GetName() + "</b></h1>\n";
	for (const Rental& rental : m_rentals)
		result += "<p>" + rental.GetMovie().GetTitle() + "\t" + std::to_string(rental.GetCharge()) + "</p>\n";

	result += "<p>Amount owed is <b>" + std::to_string(this->GetTotalCharge()) + "</b></p>\n";
	result += "<p>You earned <b>" + std::to_string(this->GetTotalFrequentRenterPoints()) + " frequent renter points</b></p>";
	return result;
}

double Customer::GetTotalCharge() const {
	double total = 0;
	for (const Rental& rental : m_rentals)
		total += rental.GetCharge();
	return total;
}

int Customer::GetTotalFrequentRenterPoints() const {
	int total = 0;
	for (const Rental& rental : m_rentals)
		total += rental.GetFrequentRenterPoints();
	return total;
}


