#include "pch.h"
#include <iostream>
#include <limits>
#include "../PrimeNumbs/PrimeNumbsKPEq.h"
#define TST_TP unsigned short int

TEST(TestCaseName, TestName) {
	for (auto i = 1; i < std::numeric_limits<TST_TP>::max(); i++)
	{
		//bool prime_miller = KPEq::is_prime_miller_rabin(i, 100);
		EXPECT_EQ(is_prime(i), 1);
		EXPECT_EQ(1, 1);
	}
}