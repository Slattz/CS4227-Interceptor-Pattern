#pragma once
#include "Interceptor/ICustomerInterceptor.h"

class CustomerLogInterceptor : public ICustomerInterceptor {
public:
	void OnCustomerAdded(const CustomerContextObject& contextObject) override;
};
