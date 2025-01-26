#include <iostream> 
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex mtx;

void work(){
    for (int i = 0; i < 100; i++){
        this_thread::sleep_for(chrono::milliseconds(100));
        mtx.lock();
        cout << "Loop " << i << endl;
        mtx.unlock();
    }
}

int main(){
    int count = 0;
    const int ITERATIONS = 200;

    thread t1([&count](){
        for (int i = 0; i < ITERATIONS; i++){
            lock_guard<mutex> lock(mtx);
            count++;
        }
    });

    thread t2([&count](){
        for (int i = 0; i < ITERATIONS; i++){
            lock_guard<mutex> lock(mtx);
            count++;
        }
    });


    t1.join();
    t2.join();

    cout << "Final count: " << count << endl;
    return 0;
}