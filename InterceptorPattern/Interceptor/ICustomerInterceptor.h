#pragma once
#include "CustomerContextObject.h"

class ICustomerInterceptor {
public:
	virtual void OnCustomerAdded(const CustomerContextObject& contextObject) = 0;
	virtual void OnCustomerRemoved(const CustomerContextObject& contextObject) = 0;
};
