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
	std::shared_ptr<Customer> AddCustomer(const std::string customer);
	bool RemoveCustomer(std::shared_ptr<Customer>& customer);

private:
	std::vector<std::shared_ptr<Customer>> m_customers;
};

