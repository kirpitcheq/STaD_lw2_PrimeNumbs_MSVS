#pragma once

#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <random>

namespace mp = boost::multiprecision;
#define US_TP mp::int1024_t

bool is_prime(unsigned long long int num);
bool is_prime_miller_rabin(US_TP num, size_t rounds);
bool is_prime_miller_rabin_optimize(US_TP num, size_t rounds);
US_TP power_mod(US_TP value, US_TP power, US_TP mod);
