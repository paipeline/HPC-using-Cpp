#include <stdio.h>
#include <omp.h>

int main(){
  int x;
  x = 2;
  #pragma omp parallel num_threads(2) shared(x)
  {
    if (omp_get_thread_num() == 0) {
      x = 5;
    } else {
      /* Print A: the following read of x has a race */
      printf("A: Thread# %d: x = %d\n", omp_get_thread_num(),x );
    }

    #pragma omp barrier // wait for all threads to reach this point

    // ------------------------------------------------------------
    // you will see that x is 5 for both threads, because the barrier ensures that all threads have finished executing the if statement before the next section is executed
    // ------------------------------------------------------------
    if (omp_get_thread_num() == 0) {
      /* Print B */
      printf("B: Thread# %d: x = %d\n", omp_get_thread_num(),x );
     } else {
      /* Print C */
      printf("C: Thread# %d: x = %d\n", omp_get_thread_num(),x );
      }
  }
return 0;
}