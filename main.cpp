#include <iostream>
#include "PrimeNumbs/PrimeNumbsKPEq.h"

int main()
{
	unsigned long long int numb = std::numeric_limits<unsigned long long int>::max();
	std::cout << numb << std::endl;

	while (numb)
	{
		std::cin >> numb;
		bool brute_force = is_prime(numb);
		bool miller_rab = is_prime_miller_rabin(numb);
		bool miller_rab_optim = is_prime_miller_rabin_optimize(numb);

		std::cout << "Brute force method: ";
		if (brute_force)
			std::cout << "it's Prime!" << std::endl;
		else
			std::cout << "it's Not prime!" << std::endl;

		std::cout << "Miller-Rabin method: ";
		if (miller_rab)
			std::cout << "it's Prime!" << std::endl;
		else
			std::cout << "it's Not prime!" << std::endl;
		std::cout << "Optimized Miller-Rabin method: ";

		if (miller_rab_optim)
			std::cout << "it's Prime!" << std::endl;
		else
			std::cout << "it's Not prime!" << std::endl;
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
