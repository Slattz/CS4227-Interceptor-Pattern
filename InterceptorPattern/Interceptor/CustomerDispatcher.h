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


	bool Register(std::shared_ptr<ICustomerInterceptor>& interceptor);
	bool Remove(std::shared_ptr<ICustomerInterceptor>& interceptor);
	void DispatchOnCustomerAdded(const CustomerContextObject& contextObject);

private:
	CustomerDispatcher();
	~CustomerDispatcher();

	std::mutex m_mutex;
	std::vector<std::shared_ptr<ICustomerInterceptor>> m_interceptors;
};
