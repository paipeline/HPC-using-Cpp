#include <iostream>
#include <thread>
#include <mutex>
#include <cmath>
#include <future>
#include <iomanip>
using namespace std;

double calcPi(int terms){
    double pi = 0.0;
    //Leibniz formula for pi
    for (int i = 0; i < terms; i++){
        if (i % 2 == 0)
            pi += 1.0 / (i * 2 + 1);
        else
            pi -= 1.0 / (i * 2 + 1);
    }
    return pi * 4;
}

int main(){
    promise<double> piPromise;
    auto do_claculation = [&](int terms){
        piPromise.set_value(calcPi(terms));
    };
    thread t1(do_claculation, 1E8);
    future<double> piFuture = piPromise.get_future();
    cout << setprecision(15) << "Pi: " << piFuture.get() << endl;
    t1.join();
    return 0;
}