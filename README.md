# SADT_LW2_PRIMENUMBS

[Report](/Report%20files/MainReports/AllMethodsFr0To2Pow16Plus1.pdf)

Only for linux need set "CPU scale" non auto. For that example use "cpupower" for this need
sudo apt install linux-tools-generic
For graphical interface use next
sudo apt install cpupower-gui

Need boost lib for long ariphmetic
- on ubuntu
```bash
    sudo apt install libboost-all-dev 
```
- on Windows (this auto for visual studio 2022 .config have)
>NuGet Packs 
>    -Boost
>    -BoostRandom (а вроде и не нужно хз)
>    -GoogleBenchmark

Next commands need use for check benchmarks
```powershell
# here prog
# cd \PrimeNumbs\x64\Release

PrimeNumbs_.exe --benchmark_filter=GBM_ItPrimeBench/brute_2pow_0_16_qua1 --benchmark_out_format=csv --benchmark_out=brute_2pow_0_16_qua1.csv
PrimeNumbs_.exe --benchmark_filter=GBM_ItPrimeBench/brute_2pow_0_16_qua2 --benchmark_out_format=csv --benchmark_out=brute_2pow_0_16_qua2.csv
PrimeNumbs_.exe --benchmark_filter=GBM_ItPrimeBench/brute_2pow_0_16_qua3 --benchmark_out_format=csv --benchmark_out=brute_2pow_0_16_qua3.csv
PrimeNumbs_.exe --benchmark_filter=GBM_ItPrimeBench/brute_2pow_0_16_qua4 --benchmark_out_format=csv --benchmark_out=brute_2pow_0_16_qua4.csv

PrimeNumbs_.exe --benchmark_filter=GBM_ItPrimeBench/miller_2pow_0_16_qua1 --benchmark_out_format=csv --benchmark_out=miller_2pow_0_16_qua1.csv
PrimeNumbs_.exe --benchmark_filter=GBM_ItPrimeBench/miller_2pow_0_16_qua2 --benchmark_out_format=csv --benchmark_out=miller_2pow_0_16_qua2.csv
PrimeNumbs_.exe --benchmark_filter=GBM_ItPrimeBench/miller_2pow_0_16_qua3 --benchmark_out_format=csv --benchmark_out=miller_2pow_0_16_qua3.csv
PrimeNumbs_.exe --benchmark_filter=GBM_ItPrimeBench/miller_2pow_0_16_qua4 --benchmark_out_format=csv --benchmark_out=miller_2pow_0_16_qua4.csv

PrimeNumbs_.exe --benchmark_filter=GBM_ItPrimeBench/miller_optim_2pow_0_16_qua1 --benchmark_out_format=csv --benchmark_out=miller_optim_2pow_0_16_qua1.csv
PrimeNumbs_.exe --benchmark_filter=GBM_ItPrimeBench/miller_optim_2pow_0_16_qua2 --benchmark_out_format=csv --benchmark_out=miller_optim_2pow_0_16_qua2.csv
PrimeNumbs_.exe --benchmark_filter=GBM_ItPrimeBench/miller_optim_2pow_0_16_qua3 --benchmark_out_format=csv --benchmark_out=miller_optim_2pow_0_16_qua3.csv
PrimeNumbs_.exe --benchmark_filter=GBM_ItPrimeBench/miller_optim_2pow_0_16_qua4 --benchmark_out_format=csv --benchmark_out=miller_optim_2pow_0_16_qua4.csv

PrimeNumbs_.exe --benchmark_filter=GBM_ItPrimeBench/two_pow16minus1_to_pow32minus1 --benchmark_out_format=csv --benchmark_out=two_pow16minus1_to_pow32minus1.csv
PrimeNumbs_.exe --benchmark_filter=GBM_ItPrimeBench/two_pow16plus1_to_pow32plus1 --benchmark_out_format=csv --benchmark_out=two_pow16plus1_to_pow32plus1.csv

PrimeNumbs_.exe --benchmark_filter=GBM_ItPrimeBench/random_big
PrimeNumbs_.exe --benchmark_filter=GBM_ItPrimeBench/random_big --benchmark_out_format=csv --benchmark_out=random_big.csv
```