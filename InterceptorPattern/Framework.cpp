#include <iostream>
#include "Framework.h"
#include "Interceptor/CustomerDispatcher.h"

Framework::Framework() {

}

Framework::~Framework() {

}

void Framework::AddCustomer(std::shared_ptr<Customer>& customer) {
	//std::cout << "Addr" << std::hex << &customer << std::endl;
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
