#include "stdlib.h"
#include "stdio.h"
#include "math.h"

double const betta = 3.5;
double const noise_ampl = 0.05;

double get_radioactivity(double t)
{
    return 1.0 * exp(-t / betta);
}

int experiment(double *radioactivity, double *time, double start_time, double end_time, double step)
{
    int id = 0;
    for (double t = start_time; t < end_time; t += step)
    {
        radioactivity[id] = get_radioactivity(t);
        time[id] = t;
        id++;
    }
    return id;
}

void add_noise(double *radioactivity, int n)
{
    while (n--)
    {
        radioactivity[n + 1] += (rand()/(double)RAND_MAX - 0.5) * 2.0 * noise_ampl;
    }
}
