// PrimeNumbs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <random>
#include <cmath>

bool is_prime(unsigned long long int num)
{
	for (size_t i = 2; i < num - 1; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

bool is_prime_miller_rabin(unsigned long long int num, int rounds)
{
	if (num == 2 || num == 3)
		return true;
	if (num % 2 == 0 || num < 2)
		return false;
	unsigned long long int d = num - 1;
	int s = 0;
	while (d % 2 != 0) // n-1 = 2^s * d get
	{
		d /= 2;
		s++;
	}
	srand(time(NULL));
	for (auto i = 0; i < rounds; i++)
	{
		unsigned long long int rand_num = 0;
		while (rand_num < 2 || rand_num > num - 2)
			rand_num = rand() % (num - 2);
		unsigned long long int a_pow_d_mod_n = pow(rand_num, d);
		a_pow_d_mod_n %= num;
		for (auto i = 0; i < s; i++)
		{
			auto x = (a_pow_d_mod_n * a_pow_d_mod_n) % num;
			if (x == 1 && x != 1 && x != num - 1)
				return false;
			if (a_pow_d_mod_n != 1)
				return false;
		}
		return true;
	}

	return true; //Может возвращать вероятность?
}

bool is_prime_sieve_eratosthenes(unsigned int num)
{
	bool* crossed_numbs = new bool[num + 1] {}; //init with false
	for (auto i = 2; i <= num; i++)
	{
		if (crossed_numbs[i])
			continue;
		for (auto j = i + i; j <= num; j += i)
			crossed_numbs[j] = true;
	}
	if (crossed_numbs[num])
		return false;
	return true;
}

int main()
{
	unsigned int numb = 1;
	while (numb)
	{
		std::cin >> numb;
		std::cout << is_prime(numb) << std::endl;
		std::cout << is_prime_miller_rabin(numb, 100) << std::endl;
		std::cout << is_prime_sieve_eratosthenes(numb) << std::endl;
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
