#include <thread>
#include "CustomerDispatcher.h"

CustomerDispatcher::CustomerDispatcher() {

}

CustomerDispatcher::~CustomerDispatcher() {
	const std::lock_guard<std::mutex> lock(m_mutex);
	m_interceptors.clear();
}

CustomerDispatcher& CustomerDispatcher::GetInstance() {
    static CustomerDispatcher instance;
    return instance;
}

bool CustomerDispatcher::Register(ICustomerInterceptor* interceptor) {
	const std::lock_guard<std::mutex> lock(m_mutex);
	for (auto& i : m_interceptors) {
		if (i == interceptor) { //we dont want the same interceptor twice
			return false;
		}
	}
	m_interceptors.push_back(interceptor);
	return true;
}

bool CustomerDispatcher::Remove(ICustomerInterceptor* interceptor) {
	const std::lock_guard<std::mutex> lock(m_mutex);
	for (auto itr = m_interceptors.begin(); itr != m_interceptors.end(); itr++) {
		if (*itr == interceptor) { //we dont want the same interceptor twice
			m_interceptors.erase(itr);
			return true;
		}
	}
	return false;
}

void CustomerDispatcher::DispatchOnCustomerAdded(const CustomerContextObject& contextObject) {
	if (!m_interceptors.empty()) {
		std::vector<std::shared_ptr<ICustomerInterceptor>> cloned;

		{
			const std::lock_guard<std::mutex> lock(m_mutex);
			cloned = m_interceptors;
		}

		for (auto& i : cloned) {
			i->OnCustomerAdded(contextObject);
		}
	}
}
