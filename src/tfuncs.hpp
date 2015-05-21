#include <pthread.h>
#include <semaphore.h>

// TODO convert this to the c++ threads API. Also
// check what might be the disadvantages of using
// it compared to the C api.
//    There are any changes that sould be done
//    regarding the Cmake compilation?

int num_threads = 4;
int count = 0;

sem_t count_mutex;
sem_t turnstile1;
sem_t turnstile2;

/**
 * Two-phase reusable barrier
 *
 * TODO: measure when and how much this solution
 *       is worse than butterfly.
 */
void* tfunc(void*)
{

  // INITIALIZATION

  while (1) {
    sem_wait(&count_mutex);
    count += 1;
    if (count == num_threads) {
      sem_wait(&turnstile2);
      sem_post(&turnstile1);
    }
    sem_post(&count_mutex);

    sem_wait(&turnstile1);
    sem_post(&turnstile1);

    // CRITICAL POINT

    sem_wait(&count_mutex);
    count -= 1;
    if (!count) {
      sem_wait(&turnstile1);
      sem_post(&turnstile2);
    }
    sem_post(&count_mutex);

    sem_wait(&turnstile2);
    sem_post(&turnstile2);
  }

  // END

  pthread_exit(NULL);
}

