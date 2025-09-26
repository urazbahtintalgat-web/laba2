#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// const double eps = 1e-5;

inline bool is_zero(double x, double precision) {
    return (abs(x) < precision);
}

double model(double* radioactivity, double* time, int N, double decay_time) {
    double res = 0;
    double e = exp(1.0);
    for (int i = 1; i <= N; i++) {
        res += time[i]*pow(e, -time[i]/decay_time)*(radioactivity[i] - pow(e, -time[i]/decay_time));
    }
    return res;
}

double nonlinear_equation(double *radioactivity, double *time, int N, double precision) {
    double interval1 = 0, interval2 = 0;
    printf("Enter interval1: "); scanf("%lf", &interval1);
    printf("Enter interval2: "); scanf("%lf", &interval2);
    

    double decay_time = 0;
    while (!is_zero(interval1 - interval2, precision)) {
        decay_time = (interval1 + interval2)/2;
        if (is_zero(model(radioactivity, time, N, decay_time), precision)) {
            return decay_time;
        }
        if (model(radioactivity, time, N, interval1)*model(radioactivity, time, N, decay_time) > 0) interval1 = decay_time;
        else interval2 = decay_time;
    }

    return decay_time;
}

double linear_equation (double *radioactivity, double *time, int N) {
    double numerator = 0, denominator = 0, decay_rate = 0;
    for (int i = 1; i <= N; i++) {
        numerator += (time[i]*time[i]);
        denominator += time[i]*(1 - radioactivity[i]);
    }

    decay_rate = numerator/denominator;

    return decay_rate;
}


int main() {
    // const double
    //  precision = 1e-5;
    // double r = root_solver(f, -2, 2);
    // printf("%f\n", r);
    return 0;
}
