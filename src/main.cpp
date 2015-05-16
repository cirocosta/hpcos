#include <iomanip>
#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#include <pthread.h>

using std::cout;
using std::endl;

void* func(void*)
{
    long prec = 1000;
    mpf_set_default_prec(prec);

    mpf_class a(1);
    mpf_class b(mpf_class(1)/sqrt(mpf_class(2)));
    mpf_class t(mpf_class(1)/mpf_class(4));
    mpf_class p(1);
    mpf_class x, y, pi;

    while (a-b > mpf_class(1e-100)) {
        x = (a+b)/2;
        y = sqrt(a*b);
        t = t - p*(a-x)*(a-x);
        a = x;
        b = y;
        p *= 2;
    }

    pi = (a+b)*(a+b)/(mpf_class(4)*t);

    cout << std::setprecision(80) << pi << endl;

    pthread_exit(NULL);
}

int main() {
    pthread_t t1;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    pthread_create(&t1, NULL, &func, NULL);
    pthread_join(t1, NULL);

    cout << "FINISHED" << endl;

    pthread_exit(NULL);
}
