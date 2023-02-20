#include <iostream>
#include <thread>
#include "Framework.h"
#include "CustomerLogInterceptor.h"
#include "Interceptor/CustomerDispatcher.h"

void frameworkThread() {
    Framework framework;
    std::cout << "Adding Customer To Framework..." << std::endl;
    std::shared_ptr<Customer> customer = framework.AddCustomer("Shane Slattery");
    std::cout << "New Customer Name: " << customer->GetName() << std::endl;
    framework.RemoveCustomer(customer);
    std::cout << "Customer Removed!" << std::endl;
}

int main() {
    std::cout << "Registering CustomerLogInterceptor with CustomerDispatcher..." << std::endl;
    CustomerLogInterceptor* logInterceptor = new CustomerLogInterceptor();
    CustomerDispatcher::GetInstance().Register(logInterceptor);
    std::cout << "Registered! Creating Framework thread..." << std::endl;

    std::thread framework(frameworkThread);
    std::cout << "Created thread!" << std::endl;

    framework.join();
    std::cout << "Finished program!" << std::endl;
}

