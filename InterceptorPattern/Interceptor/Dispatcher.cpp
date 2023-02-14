#include <thread>
#include "Dispatcher.h"

Dispatcher::Dispatcher() {

}

Dispatcher::~Dispatcher() {
	const std::lock_guard<std::mutex> lock(m_mutex);
	m_interceptors.clear();
}

Dispatcher& Dispatcher::GetInstance() {
    static Dispatcher instance;
    return instance;
}

bool Dispatcher::Register(std::shared_ptr<IInterceptor>& interceptor) {
	const std::lock_guard<std::mutex> lock(m_mutex);
	for (auto& i : m_interceptors) {
		if (i == interceptor) { //we dont want the same interceptor twice
			return false;
		}
	}
	m_interceptors.push_back(interceptor);
	return true;
}

bool Dispatcher::Remove(std::shared_ptr<IInterceptor>& interceptor) {
	const std::lock_guard<std::mutex> lock(m_mutex);
	for (auto itr = m_interceptors.begin(); itr != m_interceptors.end(); itr++) {
		if (*itr == interceptor) { //we dont want the same interceptor twice
			m_interceptors.erase(itr);
			return true;
		}
	}
	return false;
}

void Dispatcher::Dispatch() {
	if (!m_interceptors.empty()) {
		std::vector<std::shared_ptr<IInterceptor>> cloned;
	
		{
			const std::lock_guard<std::mutex> lock(m_mutex);
			cloned = m_interceptors;
		}

		for (auto& i : cloned) {
			i->EventCallback();
		}
	}
}
