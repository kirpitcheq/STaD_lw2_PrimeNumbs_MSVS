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
	if (num % 2 != 0 || num < 2)
		return false;
	unsigned long long int d = num - 1;
	int s = 0;
	unsigned long long int t = d;
	while (d % 2 != 0)
	{
		t /= 2;
		s++;
	}
	srand(time(NULL));
	for (size_t i = 0; i < rounds; i++)
	{
		unsigned long long int rand_num = rand() % num;
		unsigned long long int x = pow((int)rand_num, (int)t) % num;
		if (x == 1 || x == -1)
			continue;
		for (size_t i = 0; i < s; i++)
		{
			x = (x * x) % num;
			if (x == 1 && x != 1 && x != num-1)
				return false;
			if (x == num - 1)
				break;
		}
	}

	return true; //Может возвращать вероятность?
}

bool is_prime_oprim(unsigned int num)
{
	return true;

}

int main()
{
	unsigned int numb;
	std::cin >> numb;
	std::cout << is_prime(numb) << std::endl;
	std::cout << is_prime_miller_rabin(numb, 100) << std::endl;
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
