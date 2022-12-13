// PrimeNumbs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <random>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <limits>
//using namespace boost::multiprecision;
namespace mp = boost::multiprecision;
#define US_TP mp::int1024_t
US_TP power_mod(US_TP value, US_TP power, US_TP mod);


bool is_prime(unsigned long long int num)
{
	for (size_t i = 2; i < num - 1; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}
//#define DEBUG_PRINT
bool is_prime_miller_rabin(US_TP num, size_t rounds)
{
	if (num <= 3) return true;
	if (num == 0) return false;
	/*
	
	if (num % 2 == 0 || num < 2 || num % 3 == 0)
		return false;
	*/
	US_TP d = num - 1;
	US_TP s = 0;
	while (d % 2 != 0) // n-1 = 2^s * d get
	{
		d /= 2;
		s++;
	}
	if (d == 0)
		d = 1;
#ifdef DEBUG_PRINT
	std::cout << "d = " << d << std::endl;
	std::cout << "s = " << s << std::endl;
#endif
	srand(time(NULL));
	for (auto i = 0; i < rounds; i++)
	{
		US_TP rand_num = 0;
		while (rand_num < 2 || rand_num > num - 2)
			rand_num = rand() % (num);
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
		for (auto i = 0; i < s; i++)
		{
			unsigned long long int two_pow_s = pow(2, i);
			US_TP two_pow_s_mul_d = (US_TP)two_pow_s * d;
			US_TP x = power_mod(rand_num, two_pow_s_mul_d, num);
			if (x != num - 1)
				return false;
			else
				break;
		}
	}
	return true; //Может возвращать вероятность?
}
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

int main()
{
	unsigned long long int numb = 1;
	mp::int128_t mybignum = 18446744073709551615;
	std::cout << mybignum % 13 << std::endl;

	std::cout << std::numeric_limits<unsigned long long int>::max() << std::endl;
	while (numb)
	{
		std::cin >> numb;
		std::cout << is_prime(numb) << std::endl;
		std::cout << is_prime_miller_rabin(numb, 100) << std::endl << std::endl;
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
