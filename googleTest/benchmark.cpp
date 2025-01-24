#include <benchmark/benchmark.h>
#include <vector>

int FibonacciRecursive(int n) {
    if (n <= 1) return n;
    return FibonacciRecursive(n - 1) + FibonacciRecursive(n - 2);
}

int FibonacciDP(int n) {
    if (n <= 1) return n;
    std::vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int FibonacciIterative(int n) {
    if (n <= 1) return n;
    int prev = 0, curr = 1;
    for (int i = 2; i <= n; i++) {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

static void BM_FibonacciRecursive(benchmark::State& state) {
    for (auto _ : state) {
        FibonacciRecursive(state.range(0));
    }
}

static void BM_FibonacciDP(benchmark::State& state) {
    for (auto _ : state) {
        FibonacciDP(state.range(0));
    }
}

static void BM_FibonacciIterative(benchmark::State& state) {
    for (auto _ : state) {
        FibonacciIterative(state.range(0));
    }
}


// range number 1-30
BENCHMARK(BM_FibonacciRecursive)->Range(1, 30);
BENCHMARK(BM_FibonacciDP)->Range(1, 30);
BENCHMARK(BM_FibonacciIterative)->Range(1, 30);

BENCHMARK_MAIN();