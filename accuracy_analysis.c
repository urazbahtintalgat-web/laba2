#include "accuracy_analysis.h"

#include <math.h>

double dev_exp(double *radioactivity, double *time, int M, double decay_time) {
    double sum_result = 0.0;

    for (int i = 0; i < M; i++) {
        double model_value = exp(-time[i]/decay_time);

        double delta = radioactivity[i] - model_value;
        sum_result += delta * delta;
    }

    return sqrt(sum_result/M);
}

double dev_linear(double *radioaktivity, double *time, int M, double decay_rate) {
    double sum_result = 0.0;

    for (int i = 0; i < M; i++) {
        double model_value = 1 - time[i] / decay_rate;

        double delta = radioaktivity[i] - model_value;
        sum_result += delta * delta;
    }

    return sqrt(sum_result/M);
}

double precision_analysis (double *radioactivity, double *time, int N) {
    int M = 10;
    double ans = time[N-1];
    while (M <= N) {
        double decay_time = nonlinear_equation(radioactivity, time, M);
        double expans = dev_exp(radioactivity, time, M, decay_time);

        double decay_rate = linear_equation(radioactivity, time, M);
        double linans = dev_linear(radioactivity, time, M, decay_rate);

        if (linans > expans * 2) {
            ans = time[M-1];
            break;
        }
        M++;
    }

    return ans;
}