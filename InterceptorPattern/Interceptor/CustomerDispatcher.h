#pragma once
#include <vector>
#include <mutex>
#include <memory>
#include "ICustomerInterceptor.h"
#include "CustomerContextObject.h"

class CustomerDispatcher {
public:
	static CustomerDispatcher& GetInstance();

	inline auto begin() { return m_interceptors.begin(); }
	inline auto end() { return m_interceptors.end(); }
	inline auto cbegin() const { return m_interceptors.begin(); }
	inline auto cend() const { return m_interceptors.end(); }
	inline auto begin() const { return m_interceptors.begin(); }
	inline auto end() const { return m_interceptors.end(); }


	bool Register(ICustomerInterceptor* interceptor);
	bool Remove(ICustomerInterceptor* interceptor);
	void DispatchOnCustomerAdded(const CustomerContextObject& contextObject);

private:
	CustomerDispatcher();
	~CustomerDispatcher();

	std::mutex m_mutex;
	std::vector<ICustomerInterceptor*> m_interceptors;
};
