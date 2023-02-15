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
