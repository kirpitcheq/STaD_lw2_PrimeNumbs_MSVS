// PrimeNumbs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <limits>
#include "PrimeNumbsKPEq.h"
#include "benchmark/benchmark.h"

namespace BenchPrimeRange
{
	bool is_prime_simple_from(unsigned long long from_, unsigned long long to_)
	{
		for (unsigned long long i = from_; i <= to_; i++)
		{
			benchmark::DoNotOptimize(is_prime(i));
			benchmark::ClobberMemory();
		}
		return true;
	}
	bool is_prime_miller_rabin_from(US_TP from_, US_TP to_)
	{
		for (US_TP i = from_; i <= to_; i++)
		{
			benchmark::DoNotOptimize(is_prime_miller_rabin(i, 10));
			benchmark::ClobberMemory();
		}
		return true;
	}
	bool is_prime_miller_rabin_optim_from(US_TP from_, US_TP to_)
	{
		for (US_TP i = from_; i <= to_; i++)
		{
			benchmark::DoNotOptimize(is_prime_miller_rabin_optimize(i, 10));
			benchmark::ClobberMemory();
		}
		return true;
	}
	static void GBM_PrimeSimple_Range(benchmark::State& state) {

		for (auto _ : state) {
			is_prime_simple_from(state.range(0), state.range(1));
		}
	}
	static void GBM_PrimeMilRab_Range(benchmark::State& state) {

		for (auto _ : state) {
			is_prime_miller_rabin_from(state.range(0), state.range(1));
		}
	}
	static void GBM_PrimeMilRabOptimize_Range(benchmark::State& state) {

		for (auto _ : state) {
			is_prime_miller_rabin_optim_from(state.range(0), state.range(1));
		}
	}
}

#ifdef PROBE_A
#define TO_16BIT_PLUS1 std::numeric_limits<unsigned short>::max() + 2

BENCHMARK(GBM_PrimeSimple_Range)->Args({ 1, TO_16BIT_PLUS1 });
BENCHMARK(GBM_PrimeMilRab_Range)->Args({ 1, TO_16BIT_PLUS1 });
BENCHMARK(GBM_PrimeMilRabOptimize_Range)->Args({ 1, TO_16BIT_PLUS1 });
#endif

#ifdef PROBE_B
#define FROM_16BIT_MINUS_1 std::numeric_limits<unsigned short>::max()
#define TO_32BIT_PLUS_1 std::numeric_limits<unsigned int>::max() + 2

BENCHMARK(GBM_PrimeSimple_Range)->Args({ FROM_16BIT_MINUS_1, TO_32BIT_PLUS_1 });
BENCHMARK(GBM_PrimeMilRab_Range)->Args({ FROM_16BIT_MINUS_1, TO_32BIT_PLUS_1 });
BENCHMARK(GBM_PrimeMilRabOptimize_Range)->Args({ FROM_16BIT_MINUS_1, TO_32BIT_PLUS_1 });
#endif

#ifdef PROBE_C
#define FROM_16BIT_MINUS_1 std::numeric_limits<unsigned short>::max()
#define TO_32BIT_PLUS_1 std::numeric_limits<unsigned int>::max() + 2

BENCHMARK(GBM_PrimeSimple)->Args({ FROM_16BIT_MINUS_1, TO_32BIT_PLUS_1 });
BENCHMARK(GBM_PrimeMilRab)->Args({ FROM_16BIT_MINUS_1, TO_32BIT_PLUS_1 });
BENCHMARK(GBM_PrimeMilRabOptim)->Args({ FROM_16BIT_MINUS_1, TO_32BIT_PLUS_1 });
#endif

bool is_prime_simple_for_bench(unsigned long long numb_)
{
	benchmark::DoNotOptimize(is_prime(numb_));
	benchmark::ClobberMemory();
	return true;
}
bool is_prime_miller_rabin_for_bench(US_TP numb_)
{
	benchmark::DoNotOptimize(is_prime_miller_rabin(numb_, 10));
	benchmark::ClobberMemory();
	return true;
}
bool is_prime_miller_rabin_optim_for_bench(US_TP numb_)
{
	benchmark::DoNotOptimize(is_prime_miller_rabin_optimize(numb_, 10));
	benchmark::ClobberMemory();
	return true;
}
static void GBM_PrimeSimple(benchmark::State& state) {

	for (auto _ : state) {
		is_prime_simple_for_bench(state.range(0));
	}
}
static void GBM_PrimeMilRab(benchmark::State& state) {

	for (auto _ : state) {
		is_prime_miller_rabin_for_bench(state.range(0));
	}
}
static void GBM_PrimeMilRabOptim(benchmark::State& state) {

	for (auto _ : state) {
		is_prime_miller_rabin_optim_for_bench(state.range(0));
	}
}


#define BENCH_B

#ifdef BENCH_A
#define TO_16BIT_PLUS1_OLD std::numeric_limits<unsigned short>::max() + 2
#define TO_16BIT_PLUS1 (1<<16) + 1

BENCHMARK(GBM_PrimeSimple)->DenseRange(1, TO_16BIT_PLUS1, 1);
BENCHMARK(GBM_PrimeMilRab)->DenseRange(1, TO_16BIT_PLUS1, 1);
BENCHMARK(GBM_PrimeMilRabOptim)->DenseRange(1, TO_16BIT_PLUS1, 1);
#endif
#ifdef BENCH_B
#define FROM_16BIT_MINUS_1_OLD std::numeric_limits<unsigned short>::max()
#define TO_32BIT_PLUS_1_OLD std::numeric_limits<unsigned int>::max() + 2
#define FROM_16BIT_MINUS_1 (7<<8)
#define TO_32BIT_MINUS_1 (7<<15)
#define FROM_16BIT_PLUS_1 (1<<16) + 1
#define TO_32BIT_PLUS_1 (1>>32) + 1
//BENCHMARK(GBM_PrimeSimple)->RangeMultiplier(2)->Range(FROM_16BIT_MINUS_1_OLD, TO_32BIT_PLUS_1_OLD);
BENCHMARK(GBM_PrimeSimple)->RangeMultiplier(2)->Range(FROM_16BIT_MINUS_1, TO_32BIT_MINUS_1);
//BENCHMARK(GBM_PrimeSimple)->RangeMultiplier(2)->Range(FROM_16BIT_PLUS_1, TO_32BIT_PLUS_1);
//BENCHMARK(GBM_PrimeMilRab)->Arg( 7 << 16)->Arg(7 << 17)->Arg(7 << 18)->Arg(7 << 19)->Arg(
	//7 << 20)->Arg(7 << 21)->Arg(7 << 22)->Arg(7 << 23)->Arg(7 << 24)->Arg(7 << 25)->Arg(7 << 26)->Arg(7 << 27);
/*
BENCHMARK(GBM_PrimeMilRab)->RangeMultiplier(2)->Range(FROM_16BIT_PLUS_1, TO_32BIT_PLUS_1);

BENCHMARK(GBM_PrimeMilRabOptim)->RangeMultiplier(2)->Range(FROM_16BIT_MINUS_1, TO_32BIT_MINUS_1);
BENCHMARK(GBM_PrimeMilRabOptim)->RangeMultiplier(2)->Range(FROM_16BIT_PLUS_1, TO_32BIT_PLUS_1);
*/

#endif

#ifdef BENCH_C
#endif


static void GBM_PrimeSimple_Random_32_64(benchmark::State& state) {
	for (auto _ : state) {
		is_prime(state.range(0));
	}
}
static void GBM_PrimeMilRab_Random_32_64(benchmark::State& state) {
	for (auto _ : state) {
		is_prime_miller_rabin(state.range(0), 10);
	}
}
static void GBM_PrimeMilRabOptim_Random_32_64(benchmark::State& state) {
	for (auto _ : state) {
		is_prime_miller_rabin_optimize(state.range(0), 10);
	}
}
#ifdef BENCH_D
BENCHMARK(GBM_PrimeSimple_Fr2Pow16Min1_To2Pow32Plus1)->Range(2, to_);
BENCHMARK(GBM_PrimeMilRab_Fr2Pow16Min1_To2Pow32Plus1)->Arg({ from_,to_ });

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
