#pragma once
#include <string>
#include <memory>
#include "../MovieRental/Customer.h"

class CustomerContextObject {
public:
	constexpr CustomerContextObject(std::shared_ptr<Customer>& customer) : m_customer(customer) { }

	inline std::string GetName() const {
		return m_customer->GetName();
	}

	inline void SetName(std::string& name) const {
		m_customer->SetName(name);
	}

private:
	std::shared_ptr<Customer>& m_customer;
};