#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <limits>
#include "../PrimeNumbs/PrimeNumbsKPEq.h"
#include <boost/multiprecision/cpp_int.hpp>


#define TST_TP unsigned short int

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PrimeNumbsUnitTests
{
	TEST_CLASS(PrimeNumbsUnitTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			for (auto i = 1; i < std::numeric_limits<TST_TP>::max(); i++)
			{
				//bool prime_miller = KPEq::is_prime_miller_rabin(i, 100);
				Assert::AreEqual(is_prime(i), 1);
			}
		}
	};
}