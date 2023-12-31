﻿// PrimeNumbs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

//BENCH_1st
static void from0_to2pow16_brute_quart1(benchmark::internal::Benchmark* b) {
	for (int i = 0; i < 16384; i++)
		b->Args({ i, 0 });
}
static void from0_to2pow16_brute_quart2(benchmark::internal::Benchmark* b) {
	for (int i = 16384; i < 32769; i++)
		b->Args({ i, 0 });
}
static void from0_to2pow16_brute_quart3(benchmark::internal::Benchmark* b) {
	for (int i = 32769; i <= 49152; i++)
		b->Args({ i, 0 });
}
static void from0_to2pow16_brute_quart4(benchmark::internal::Benchmark* b) {
	for (int i = 49152; i <= 65537; i++)
		b->Args({ i, 0 });
}

static void from0_to2pow16_miller_quart1(benchmark::internal::Benchmark* b) {
	for (int i = 0; i < 16384; i++)
		b->Args({ i, 1 });
}
static void from0_to2pow16_miller_quart2(benchmark::internal::Benchmark* b) {
	for (int i = 16384; i < 32769; i++)
		b->Args({ i, 1 });
}
static void from0_to2pow16_miller_quart3(benchmark::internal::Benchmark* b) {
	for (int i = 32769; i <= 49152; i++)
		b->Args({ i, 1 });
}
static void from0_to2pow16_miller_quart4(benchmark::internal::Benchmark* b) {
	for (int i = 49152; i <= 65537; i++)
		b->Args({ i, 1 });
}

static void from0_to2pow16_miller_opt_quart1(benchmark::internal::Benchmark* b) {
	for (int i = 0; i < 16384; i++)
		b->Args({ i, 2 });
}
static void from0_to2pow16_miller_opt_quart2(benchmark::internal::Benchmark* b) {
	for (int i = 16384; i < 32769; i++)
		b->Args({ i, 2 });
}
static void from0_to2pow16_miller_opt_quart3(benchmark::internal::Benchmark* b) {
	for (int i = 32769; i <= 49152; i++)
		b->Args({ i, 2 });
}
static void from0_to2pow16_miller_opt_quart4(benchmark::internal::Benchmark* b) {
	for (int i = 49152; i <= 65537; i++)
		b->Args({ i, 2 });
}
//BENCHMARK(GBM_ItPrimeBench)->Apply(from0_to2pow16plus1);
BENCHMARK(GBM_ItPrimeBench)->Apply(from0_to2pow16_brute_quart1)->ArgName("brute_2pow_0_16_qua1")->UseRealTime();
BENCHMARK(GBM_ItPrimeBench)->Apply(from0_to2pow16_brute_quart2)->ArgName("brute_2pow_0_16_qua2")->UseRealTime();
BENCHMARK(GBM_ItPrimeBench)->Apply(from0_to2pow16_brute_quart3)->ArgName("brute_2pow_0_16_qua3")->UseRealTime();
BENCHMARK(GBM_ItPrimeBench)->Apply(from0_to2pow16_brute_quart4)->ArgName("brute_2pow_0_16_qua4")->UseRealTime();

BENCHMARK(GBM_ItPrimeBench)->Apply(from0_to2pow16_miller_quart1)->ArgName("miller_2pow_0_16_qua1")->UseRealTime();
BENCHMARK(GBM_ItPrimeBench)->Apply(from0_to2pow16_miller_quart2)->ArgName("miller_2pow_0_16_qua2")->UseRealTime();
BENCHMARK(GBM_ItPrimeBench)->Apply(from0_to2pow16_miller_quart3)->ArgName("miller_2pow_0_16_qua3")->UseRealTime();
BENCHMARK(GBM_ItPrimeBench)->Apply(from0_to2pow16_miller_quart4)->ArgName("miller_2pow_0_16_qua4")->UseRealTime();

BENCHMARK(GBM_ItPrimeBench)->Apply(from0_to2pow16_miller_opt_quart1)->ArgName("miller_optim_2pow_0_16_qua1")->UseRealTime();
BENCHMARK(GBM_ItPrimeBench)->Apply(from0_to2pow16_miller_opt_quart2)->ArgName("miller_optim_2pow_0_16_qua2")->UseRealTime();
BENCHMARK(GBM_ItPrimeBench)->Apply(from0_to2pow16_miller_opt_quart3)->ArgName("miller_optim_2pow_0_16_qua3")->UseRealTime();
BENCHMARK(GBM_ItPrimeBench)->Apply(from0_to2pow16_miller_opt_quart4)->ArgName("miller_optim_2pow_0_16_qua4")->UseRealTime();
//BENCH_2nd
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
BENCHMARK(GBM_ItPrimeBench)->Apply(two_pow16minus1_to_pow32minus1)->ArgName("two_pow16minus1_to_pow32minus1");
BENCHMARK(GBM_ItPrimeBench)->Apply(two_pow16plus1_to_pow32plus1)->ArgName("two_pow16plus1_to_pow32plus1");
//BENCH_3rd
#define MAX_UINT64 std::numeric_limits<unsigned long long>::max() 
static void GenerateRandomFrom2Pow32To2Pow64(benchmark::internal::Benchmark* b)
{
	std::mt19937 mt;
	mt.seed(time(NULL));
	std::uniform_int_distribution<unsigned long long> ui((unsigned long long)std::pow(2, 32), MAX_UINT64);
	global_big_random = ui(mt);
}
BENCHMARK(GBM_ItPrimeBench)->Apply(GenerateRandomFrom2Pow32To2Pow64)
	->Args({ -1, 0 })
	->Args({ -1, 1 })
	->Args({ -1, 2 })
	->ArgName("random_big");

BENCHMARK_MAIN();