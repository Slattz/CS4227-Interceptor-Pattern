#pragma once
#include <vector>
#include <mutex>
#include <memory>
#include "IInterceptor.h"

class Dispatcher {
public:
	static Dispatcher& GetInstance();

	inline auto begin() { return m_interceptors.begin(); }
	inline auto end() { return m_interceptors.end(); }
	inline auto cbegin() const { return m_interceptors.begin(); }
	inline auto cend() const { return m_interceptors.end(); }
	inline auto begin() const { return m_interceptors.begin(); }
	inline auto end() const { return m_interceptors.end(); }


	bool Register(std::shared_ptr<IInterceptor>& interceptor);
	bool Remove(std::shared_ptr<IInterceptor>& interceptor);
	void Dispatch();

private:
	Dispatcher();
	~Dispatcher();

	std::mutex m_mutex;
	std::vector<std::shared_ptr<IInterceptor>> m_interceptors;
};
