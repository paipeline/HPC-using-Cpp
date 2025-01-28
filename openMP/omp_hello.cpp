#include <omp.h>
#include <iostream>


int main() {

    int nthreads, tid;

    #pragma omp parallel private(tid) // each thread has its own tid
    {
        tid = omp_get_thread_num();
        printf("Hello from thread %d\n", tid);
    }

    // master thread
    if (tid == 0) {
        nthreads = omp_get_num_threads();
        printf("Number of threads = %d\n", nthreads);
    }

return 0;
}


