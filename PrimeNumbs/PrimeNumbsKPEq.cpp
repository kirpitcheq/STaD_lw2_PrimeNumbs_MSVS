#include "PrimeNumbsKPEq.h"

bool is_prime(unsigned long long int num)
{
	bool print_percent = false;
	//unsigned short div_numbs = (unsigned short)((double)num / (double) std::numeric_limits<unsigned long long int>::max()) * 100;
	unsigned short div_numbs = 0;
	unsigned long long int temp = num;
	while (temp / 10 != 0)
	{
		temp /= 10;
		div_numbs++;
	}
	div_numbs *= div_numbs;
	div_numbs *= div_numbs;

	if (!div_numbs)
		print_percent = false;
	unsigned long long int* percents_left = new unsigned long long int[div_numbs] {};
	if (print_percent)
		for (size_t i = 1; i < div_numbs - 1; i++)
			percents_left[i] = (num) * (double)((double)i / (double)(div_numbs - 1));
		percents_left[div_numbs - 1] = num;
	size_t perc_arr_counter = 0;
	for (size_t i = 2; i < num - 1; i++)
	{
		if (print_percent && i > percents_left[perc_arr_counter] && perc_arr_counter < div_numbs)
		{
			std::cout << ((double)perc_arr_counter / (double)div_numbs) * 100 << "%-";
			if (perc_arr_counter != div_numbs - 1)
				perc_arr_counter++;
		}
		if (num % i == 0)
		{
			if (print_percent)
				std::cout << "100%" << std::endl;
			return false;
		}
	}
	if (print_percent)
		std::cout << "100%" << std::endl;
	return true;
}
//#define DEBUG_PRINT
bool is_prime_miller_rabin(US_TP num, size_t rounds)
{
	if (num <= 3) return true;
	if (num == 0) return false;
	US_TP d = num - 1;
	US_TP s = 0;
	while (d % 2 == 0) // n-1 = 2^s * d get
	{
		d /= 2;
		s++;
	}
	if (d == 0) // в случае разложения числа на степень двойки будет 2^s * d(1)
		d = 1;


#ifdef DEBUG_PRINT
	std::cout << "d = " << d << std::endl;
	std::cout << "s = " << s << std::endl;
#endif
	rd::mt19937 mt;
	mt.seed(time(NULL));
	rd::uniform_int_distribution<US_TP> ui(2, num - 2);
	for (auto i = 0; i < rounds; i++)
	{
		US_TP rand_num = ui(mt);
		US_TP a_pow_d_mod_n = power_mod(rand_num, d, num);
#ifdef DEBUG_PRINT
		std::cout << "rand_num = " << rand_num << std::endl;
		std::cout << "a_pow_d_mod_n = " << a_pow_d_mod_n << std::endl;
#endif
		if (a_pow_d_mod_n == 1)
			continue;
		//a_pow_d_mod_n %= num;
		if (s == 0)
			return false;
		bool second_condition = false;
		for (auto i = 0; i < s; i++)
		{
			unsigned long long int two_pow_s = (unsigned long long int)pow(2, i);
			US_TP two_pow_s_mul_d = (US_TP)two_pow_s * d;
			US_TP x = power_mod(rand_num, two_pow_s_mul_d, num);
#ifdef DEBUG_PRINT
			std::cout << "x = " << x << std::endl;
			std::cout << "two_pow_s = " << two_pow_s << std::endl;
			std::cout << "two_pow_s_mul_d = " << two_pow_s_mul_d << std::endl;
#endif
			if (x == num - 1)
			{
				second_condition = true;
				break;
			}
		}
		if (second_condition)
			continue;
		else return false;
	}
	return true;
}

#define OPTIMIZE_RABIN
#ifdef OPTIMIZE_RABIN
bool is_prime_miller_rabin_optimize(US_TP num, size_t rounds)
{
	if (num <= 3) return true;
	if (num == 0) return false;
	if (num % 2 == 0 || num % 3 == 0)
		return false;
	US_TP d = num - 1;
	US_TP s = 0;
	while (d % 2 == 0) // n-1 = 2^s * d get
	{
		d /= 2;
		s++;
	}
	if (d == 0) // в случае разложения числа на степень двойки будет 2^s * d(1)
		d = 1;
	rd::mt19937 mt;
	mt.seed(time(NULL));
	rd::uniform_int_distribution<US_TP> ui(2, num - 2);
	for (auto i = 0; i < rounds; i++)
	{
		US_TP rand_num = ui(mt);
		US_TP a_pow_d_mod_n = power_mod(rand_num, d, num);
		if (a_pow_d_mod_n == 1)
			continue;
		//a_pow_d_mod_n %= num;
		if (s == 0)
			return false;
		bool second_condition = false;
		for (auto i = 0; i < s; i++)
		{
			unsigned long long int two_pow_s = pow(2, i);
			US_TP two_pow_s_mul_d = (US_TP)two_pow_s * d;
			US_TP x = power_mod(rand_num, two_pow_s_mul_d, num);
			if (x == num - 1)
			{
				second_condition = true;
				break;
			}
		}
		if (second_condition)
			continue;
		else return false;
	}
	return true; //Может возвращать вероятность?
}
#endif

US_TP power_mod(US_TP value, US_TP power, US_TP mod)
{
	US_TP res = 1;
	US_TP pow_res = 0;
	while (pow_res < power)
	{
		US_TP pow_res_1 = 2;
		US_TP res1 = value;
		while (pow_res + pow_res_1 <= power)
		{
			res1 *= res1;
			res1 %= mod;
			pow_res_1 *= 2;
		}
		pow_res_1 /= 2;
		res = (res * res1) % mod;
		pow_res += pow_res_1;
	}
	return res % mod;
}
