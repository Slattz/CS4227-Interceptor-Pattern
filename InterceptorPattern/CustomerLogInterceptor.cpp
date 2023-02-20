#include "CustomerLogInterceptor.h"
#include <iostream>

void CustomerLogInterceptor::OnCustomerAdded(const CustomerContextObject& contextObject) {
	std::cout << "\tHello from CustomerLogInterceptor::OnCustomerAdded!!!!" << std::endl;

	std::string name = contextObject.GetName();
	std::cout << "\tCustomer Added! Name: " << name << std::endl;
	std::cout << "\tChanging Customer Name..." << std::endl;
	name.append(" (Intercepted)");
	contextObject.SetName(name);
	std::cout << "\tCustomer Name Changed using Interceptor!" << std::endl;
}

void CustomerLogInterceptor::OnCustomerRemoved(const CustomerContextObject& contextObject) {
	std::cout << "\tHello from CustomerLogInterceptor::OnCustomerRemoved!!!!" << std::endl;

	std::string name = contextObject.GetName();
	std::cout << "\tCustomer Removed! Name: " << name << std::endl;
	std::cout << "\tCustomer Name Logged using Interceptor!" << std::endl;
}
