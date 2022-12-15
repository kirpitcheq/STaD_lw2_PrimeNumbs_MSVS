// PrimeNumbs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <limits>
#include <cmath>
#include "PrimeNumbsKPEq.h"
#include "benchmark/benchmark.h"



unsigned long long global_big_random = 0;

static void GBM_ItPrimeBench(benchmark::State& state) {
	unsigned long long check_value = 0;
	bool numb_view = false;
	switch (state.range(0))
	{
	case -1:
		check_value = global_big_random;
		numb_view = true;
		break;
	default:
		check_value = state.range(0);
		break;
	}
	std::string LabelNameOut;
	bool result_out = false;
	switch (state.range(1))
	{
	case 1:
		LabelNameOut = "MillerRabin";
		for (auto _ : state) {
			benchmark::DoNotOptimize(is_prime_miller_rabin(check_value));
			benchmark::ClobberMemory();
		}
		result_out = is_prime_miller_rabin(check_value);
		break;
	case 2:
		LabelNameOut = "MillerRabinOprtimize";
		for (auto _ : state) {
			benchmark::DoNotOptimize(is_prime_miller_rabin_optimize(check_value));
			benchmark::ClobberMemory();
		}
		result_out = is_prime_miller_rabin_optimize(check_value);
		break;
	default:
		LabelNameOut = "BruteForce";
		for (auto _ : state) {
			benchmark::DoNotOptimize(is_prime(check_value));
			benchmark::ClobberMemory();
		}
		result_out = is_prime(check_value);
		break;
	}
	if(numb_view)
		LabelNameOut += " check this " + std::to_string(check_value);
	if (result_out)
		LabelNameOut += ": this is a Prime!!!";
	state.SetLabel(LabelNameOut);
}

#define MAX_UINT64 std::numeric_limits<unsigned long long>::max() 
static void GenerateRandomFrom2Pow32To2Pow64(benchmark::internal::Benchmark* b)
{
	std::mt19937 mt;
	mt.seed(time(NULL));
	std::uniform_int_distribution<unsigned long long> ui((unsigned long long)std::pow(2, 32), MAX_UINT64);
	global_big_random = ui(mt);
}

#define BENCH_A

#ifdef BENCH_A
#define BENCH_A_3
#define TO_16BIT_PLUS1 (1<<16) + 1
static void from0_to2pow16plus1(benchmark::internal::Benchmark* b) {
#ifdef BENCH_A_1;
	int i = 0;
#elif defined  BENCH_A_2
	int i = 1;
#elif defined BENCH_A_3
	int i = 2;
#elif defined BENCH_A_GENERAL
	for (int i = 0; i < 3; i++)
	{
#endif
		for (int j = 30000; j <= TO_16BIT_PLUS1; ++j)
			b->Args({ j, i });
#ifdef BENCH_A_GENERAL;
	}
#endif
}
BENCHMARK(GBM_ItPrimeBench)->Apply(from0_to2pow16plus1)
//->Threads(8)
;
#endif

#ifdef BENCH_B
static void two_pow16minus1_to_pow32minus1(benchmark::internal::Benchmark* b) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 16; j <= 32; ++j)
			b->Args({ (long long)std::pow(2,j) - 1, i });
	}
}
static void two_pow16plus1_to_pow32plus1(benchmark::internal::Benchmark* b) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 16; j <= 32; ++j)
			b->Args({ (long long)std::pow(2,j) + 1, i });
	}
}

BENCHMARK(GBM_ItPrimeBench)->Apply(two_pow16minus1_to_pow32minus1);
BENCHMARK(GBM_ItPrimeBench)->Apply(two_pow16plus1_to_pow32plus1);
#endif

#ifdef BENCH_C
BENCHMARK(GBM_ItPrimeBench)->Apply(GenerateRandomFrom2Pow32To2Pow64)->Args({ -1, 0 })->Args({ -1, 1 })->Args({ -1, 2 });
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
