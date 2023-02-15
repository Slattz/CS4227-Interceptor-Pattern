#include "CustomerLogInterceptor.h"
#include <iostream>

void CustomerLogInterceptor::OnCustomerAdded(const CustomerContextObject& contextObject) {
	std::cout << "Customer Added! Name: " << contextObject.GetName();
}
