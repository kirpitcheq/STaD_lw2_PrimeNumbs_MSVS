#pragma once

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/random.hpp>
#include <iostream>
#include <random>
#include <limits>
#include <cmath>

namespace mp = boost::multiprecision;
namespace rd = boost::random;
#define US_TP mp::cpp_int

bool is_prime(US_TP num);
bool is_prime_miller_rabin(US_TP num, size_t rounds);
bool is_prime_miller_rabin(US_TP num);
bool is_prime_miller_rabin_optimize(US_TP num, size_t rounds);
bool is_prime_miller_rabin_optimize(US_TP num);
US_TP power_mod(US_TP value, US_TP power, US_TP mod);
