#pragma once
#include <vector>
#include <memory>
#include "MovieRental/Customer.h"
#include "Interceptor/CustomerContextObject.h"

class Framework {
public:
	Framework();
	~Framework();

	void AddCustomer(std::shared_ptr<Customer>& customer);
	void AddCustomer(std::string& customer);

private:
	std::vector<std::shared_ptr<Customer>> m_customers;
};

