#ifndef ACCURACY_ANALYSIS_H
#define ACCURACY_ANALYSIS_H

double nonlinear_equation (double *radioactivity, double *time, int N);

double dev_exp(double *radioactivity, double *time, int M, double decay_time);


double linear_equation (double *radioactivity, double *time, int N);

double dev_linear(double *radioaktivity, double *time, int M, double decay_rate);


double precision_analysis (double *radioactivity, double *time, int N);

#endif //ACCURACY_ANALYSIS_H