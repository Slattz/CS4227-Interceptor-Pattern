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

void Framework::AddCustomer(std::string& customerName) {
	std::shared_ptr<Customer> customer = std::make_shared<Customer>(customerName);
	CustomerContextObject object(customer);
	CustomerDispatcher::GetInstance().DispatchOnCustomerAdded(object);

	m_customers.push_back(std::move(customer));
}
