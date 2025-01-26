#include <chrono>
#include <thread>
#include <iostream>

using namespace std;
class App{
    private: 
        int counter = 0;
        mutex mtx;
    public:
        int getCounter(){
            return counter;
        }
        void operator()(){
            for (int i = 0; i < 100; i++){
                {
                    lock_guard<mutex> lock(mtx);
                    ++counter;
                    cout << "Thread " << this_thread::get_id() << " - Loop " << i << endl;
                }
                this_thread::sleep_for(chrono::milliseconds(10));
            }
        }
};


int main(){
    App app;
    thread t1(ref(app));
    thread t2(ref(app));
    t1.join();
    t2.join();
    cout << "Final counter: " << app.getCounter() << endl;
    return 0;
}