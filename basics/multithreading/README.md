# C++ Multithreading

This tutorial covers the fundamentals of C++ multithreading with practical examples demonstrating various concepts.

## Table of Contents
1. [Basic Thread Operations](#basic-thread-operations)
2. [Mutex and Data Race](#mutex-and-data-race)
3. [Promise and Future](#promise-and-future)
4. [Condition Variables](#condition-variables)

## Basic Thread Operations

### basic.cpp
Demonstrates the most basic thread creation and management:
```cpp
#include <iostream>
#include <thread>
using namespace std;

void hello() {
    cout << "Hello from thread!" << endl;
}

int main() {
    thread t(hello);    // Create thread
    t.join();          // Wait for thread completion
    return 0;
}
```

## Mutex and Data Race

### lock.cpp
Shows how to use mutex to prevent data races:
```cpp
#include <iostream>
#include <thread>
#include <mutex>

mutex mtx;
int counter = 0;

void increment(int thread_id) {
    for (int i = 0; i < 100; i++) {
        lock_guard<mutex> lock(mtx);  // RAII-style locking
        ++counter;
        cout << "Thread " << thread_id << ": " << counter << endl;
    }
}
```

Key points:
- `mutex` protects shared resources
- `lock_guard` provides RAII-style lock management
- Prevents deadlocks and data races

## Promise and Future

### calcPi.cpp
Demonstrates how to use Promise/Future for passing results between threads:
```cpp
#include <future>

double calcPi(int terms) {
    double sum = 0.0;
    for (int i = 0; i < terms; i++) {
        if (i % 2 == 0)
            sum += 1.0 / (i * 2 + 1);
        else
            sum -= 1.0 / (i * 2 + 1);
    }
    return sum * 4;
}

int main() {
    promise<double> piPromise;
    future<double> piFuture = piPromise.get_future();
    
    thread t([&](int terms) {
        piPromise.set_value(calcPi(terms));
    }, 1E8);
    
    cout << "Pi: " << piFuture.get() << endl;
    t.join();
}
```

Key concepts:
- `promise` is used to set values
- `future` is used to get values
- Suitable for asynchronous computations

## Condition Variables

### condition.cpp
Demonstrates the use of condition variables:
```cpp
#include <condition_variable>
#include <queue>

condition_variable cv;
mutex mtx;
queue<int> data_queue;

void producer() {
    for (int i = 0; i < 10; ++i) {
        {
            lock_guard<mutex> lock(mtx);
            data_queue.push(i);
        }
        cv.notify_one();
    }
}

void consumer() {
    while (true) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return !data_queue.empty(); });
        
        int data = data_queue.front();
        data_queue.pop();
        cout << "Consumed: " << data << endl;
    }
}
```

Key points:
- `condition_variable` for thread synchronization
- `notify_one()/notify_all()` to notify waiting threads
- `wait()` to wait for conditions

## Lambda Expressions

In multithreading, Lambda expressions are often used to define short thread functions:

```cpp
// Capture by value [=]
auto lambda1 = [=]() { /* Can access copies of external variables */ };

// Capture by reference [&]
auto lambda2 = [&]() { /* Can modify external variables */ };

// Capture nothing []
auto lambda3 = []() { /* Cannot access external variables */ };

// Specify capture variables
auto lambda4 = [x, &y]() { /* x by value, y by reference */ };
```

## Compilation and Running

All examples can be compiled using:
```bash
g++ -std=c++11 filename.cpp -o output -pthread
```

## Best Practices

1. Always use RAII-style lock management
2. Avoid deadlocks:
   - Maintain consistent lock ordering
   - Minimize lock scope
3. Use condition variables instead of busy waiting
4. Handle exceptions properly
5. Use `async/future` for operations requiring return values

## Advanced Topics

- Atomic operations (`atomic`)
- Read-write locks (`shared_mutex`)
- Thread pools
- Work stealing
- Lock-free programming

## Important Considerations

1. Thread safety
2. Resource management
3. Exception handling
4. Performance considerations
5. Scalability

## References

- C++ Reference Manual
- C++11 Thread Library Documentation
- "C++ Concurrency in Action" by Anthony Williams
