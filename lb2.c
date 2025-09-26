#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double eps = 1e-5;

inline bool is_zero(double x) {
    return (abs(x) < eps);
}

double f(double x)  {
    return (x*x-2*x+1);
}

double g(double* radioactivity, double* time, int N, double decay_time) {
    double res = 0;
    double e = exp(1.0);
    for (int i=1; i<=N; i++) {
        res += time[i]*pow(e, -time[i]/decay_time)*(radioactivity[i] - pow(e, -time[i]/decay_time));
    }
    return res;
}
(double (*f)(double*, double*, int, double), double l, double r) {
    // if (f(l)*f(r) > 0) {
    //     printf("NO USAGE OF FUNC: [root_solver]\n");
    //     return EOF;
    // }
    double k = 0;
    while (!is_zero(l-r)) {
        k = (l+r)/2;
        if (is_zero(f(radioactivity, time, N, k))) {
            return k;
        }
        if (f(l)*f(k)>0) l = k;
        else r = k;
    }

    return k;
}
double root_solver(double (*f)(double*, double*, int, double), double l, double r) {
    // if (f(l)*f(r) > 0) {
    //     printf("NO USAGE OF FUNC: [root_solver]\n");
    //     return EOF;
    // }
    double k = 0;
    while (!is_zero(l-r)) {
        k = (l+r)/2;
        if (is_zero(f(radioactivity, time, N, k))) {
            return k;
        }
        if (f(l)*f(k)>0) l = k;
        else r = k;
    }

    return k;
}


double nonlinear_equation(double *radioactivity, double *time, int N, double precision) {
    // return root_solver(g, 0.2, 8.2);

    double interval1 = 0, interval2 = 0;
    printf("Enter interval1: "); scanf("%lf", &interval1);
    printf("Enter interval2: "); scanf("%lf", &interval2);
    

    double k = 0;
    while (!is_zero(interval1-interval2)) {
        k = (interval1+interval2)/2;
        if (is_zero(g(radioactivity, time, N, k))) {
            return k;
        }
        if (g(radioactivity, time, N, interval1)*g(radioactivity, time, N, k)>0) interval1 = k;
        else interval2 = k;
    }

    return k;
}




int main() {
    // const double
    //  precision = 1e-5;
    // double r = root_solver(f, -2, 2);
    // printf("%f\n", r);
    return 0;
}