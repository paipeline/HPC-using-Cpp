

# Example output of using Google Benchmark
Running ./bench_test
Run on (14 X 24 MHz CPU s)
CPU Caches:
  L1 Data 64 KiB
  L1 Instruction 128 KiB
  L2 Unified 4096 KiB (x14)
Load Average: 3.94, 5.51, 5.49
-------------------------------------------------------------------
Benchmark                         Time             CPU   Iterations
-------------------------------------------------------------------
BM_FibonacciRecursive/1        3.56 ns         3.56 ns    194865571
BM_FibonacciRecursive/8        68.6 ns         68.5 ns     10031096
BM_FibonacciRecursive/30    2781377 ns      2780761 ns          259
BM_FibonacciDP/1               3.58 ns         3.58 ns    197915665
BM_FibonacciDP/8                166 ns          161 ns      4436164
BM_FibonacciDP/30               403 ns          403 ns      1702426
BM_FibonacciIterative/1        3.40 ns         3.39 ns    206069634
BM_FibonacciIterative/8        10.2 ns         10.2 ns     67365990
BM_FibonacciIterative/30       37.1 ns         37.1 ns     18799113