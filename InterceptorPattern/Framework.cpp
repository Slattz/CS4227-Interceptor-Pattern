#include <iostream>
#include "Framework.h"
#include "Interceptor/CustomerDispatcher.h"

Framework::Framework() {

}

Framework::~Framework() {

}

void Framework::AddCustomer(std::shared_ptr<Customer>& customer) {
	CustomerContextObject object(customer);
	CustomerDispatcher::GetInstance().DispatchOnCustomerAdded(object);
	m_customers.push_back(customer);
}

std::shared_ptr<Customer> Framework::AddCustomer(const std::string customerName) {
	std::shared_ptr<Customer> customer = std::make_shared<Customer>(customerName);
	CustomerContextObject object(customer);
	CustomerDispatcher::GetInstance().DispatchOnCustomerAdded(object);

	m_customers.push_back(customer);
	return customer;
}

bool Framework::RemoveCustomer(std::shared_ptr<Customer>& customer) {
	for (auto i = m_customers.begin(); i != m_customers.end(); i++) {
		if (i->get() == customer.get()) {
			CustomerContextObject object(customer);
			CustomerDispatcher::GetInstance().DispatchOnCustomerRemoved(object);
			m_customers.erase(i);
			return true;
		}
	}
	return false;
}
