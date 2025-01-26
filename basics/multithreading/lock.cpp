#include <iostream> 
#include <thread>
#include <chrono>
#include <mutex>
#include <atomic>
using namespace std;


mutex mtx;
int counter = 0;

void work(int thread_id){
    for (int i = 0; i < 100; i++){
        {
            lock_guard<mutex> lock(mtx);
            ++counter;
            cout << "Thread " << thread_id << " - Loop " << i << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

int main(){
    const int ITERATIONS = 200;

    thread t1(work, 1);  // 传入线程ID
    thread t2(work, 2);

    t1.join();
    t2.join();

    cout << "Final count: " << counter << endl;  // 使用新名称
    return 0;
}