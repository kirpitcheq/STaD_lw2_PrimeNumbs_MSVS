// PrimeNumbs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <limits>
#include "PrimeNumbsKPEq.h"
#include "benchmark/benchmark.h"

static void GBM_PrimeSimpleTo2Pow16Plus1(benchmark::State& state) {

	for (auto _ : state) {
		for (unsigned long long i = 1; i <= std::numeric_limits<unsigned short>::max() + 2; i++)
			is_prime(i);
	}
}
static void GBM_PrimeMilRabTo2Pow16Plus1(benchmark::State& state) {

	for (auto _ : state) {
		for (US_TP i = 1; i <= std::numeric_limits<unsigned short>::max() + 2; i++)
			is_prime_miller_rabin(i,100);
	}
}
static void GBM_PrimeMilRabTo2Pow16Plus1_Optimize(benchmark::State& state) {

	for (auto _ : state) {
		for (US_TP i = 1; i <= std::numeric_limits<unsigned short>::max() + 2; i++)
			is_prime_miller_rabin_optimize(i, 100);
	}
}
#define BENCH_B

#ifdef BENCH_A
BENCHMARK(GBM_PrimeSimpleTo2Pow16Plus1);
BENCHMARK(GBM_PrimeMilRabTo2Pow16Plus1);
BENCHMARK(GBM_PrimeMilRabTo2Pow16Plus1_Optimize);
#endif

unsigned long long from_ = std::numeric_limits<unsigned short>::max();
unsigned long long to_value = std::numeric_limits<unsigned int>::max() + 2;
static void GBM_PrimeSimple_Fr2Pow16Min1_To2Pow32Plus1(benchmark::State& state) {
	for (auto _ : state) {
			is_prime(state.range(0));
	}
}
static void GBM_PrimeMilRab_Fr2Pow16Min1_To2Pow32Plus1(benchmark::State& state) {
	for (auto _ : state) {
			is_prime_miller_rabin(state.range(0), 10);
	}
}
#ifdef BENCH_B
BENCHMARK(GBM_PrimeSimple_Fr2Pow16Min1_To2Pow32Plus1)->Range(2, to_value);
BENCHMARK(GBM_PrimeMilRab_Fr2Pow16Min1_To2Pow32Plus1)->Arg(5);
#endif

BENCHMARK_MAIN();

#ifdef MAIN_MAIN
int main()
{
	unsigned long long int numb = std::numeric_limits<unsigned long long int>::max();
	std::cout << numb << std::endl;

	while (numb)
	{
		std::cin >> numb;
		std::cout << is_prime(numb) << std::endl;
		std::cout << is_prime_miller_rabin(numb, 100) << std::endl;
		std::cout << is_prime_miller_rabin_optimize(numb, 100) << std::endl << std::endl;
	}
}
#endif
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
