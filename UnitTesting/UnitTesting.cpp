#include "CppUnitTest.h"
#include "CustomerLogInterceptor.h"
#include "Interceptor/CustomerDispatcher.h"
#include "CustomerLogInterceptor.cpp"
#include "Interceptor/CustomerDispatcher.cpp"
#include "MovieRental/Customer.cpp"
#include "MovieRental/Rental.cpp"
#include "MovieRental/ChildrensPrice.cpp"
#include "MovieRental/NewReleasePrice.cpp"
#include "MovieRental/RegularPrice.cpp"
#include "MovieRental/Price.cpp"
#include "MovieRental/Movie.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesting
{
	TEST_CLASS(UnitTesting)
	{
	public:
		TEST_METHOD(TestMethod2)
		{
			CustomerLogInterceptor* logInterceptor = new CustomerLogInterceptor();
			bool ret = CustomerDispatcher::GetInstance().Register(logInterceptor); //should return true
			Assert::AreEqual(ret, true);

			ret = CustomerDispatcher::GetInstance().Register(logInterceptor); //should return false
			Assert::AreEqual(ret, false);

		}
	};
}
