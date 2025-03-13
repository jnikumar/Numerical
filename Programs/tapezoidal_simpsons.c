#include <stdio.h>
#include <math.h>

double f(double x) {
    return log(x);
}

// Trapezoidal Rule
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }
    return h * sum;
}

// Simpson's 1/3 Rule
double simpsons_one_third(double a, double b, int n) {
    if (n % 2 != 0) {
        n++;  // n must be even for Simpson's 1/3 rule
    }
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            sum += 2 * f(a + i * h);
        } else {
            sum += 4 * f(a + i * h);
        }
    }
    return (h / 3) * sum;
}

// Simpson's 3/8 Rule
double simpsons_three_eighth(double a, double b, int n) {
    if (n % 3 != 0) {
        n += 3 - (n % 3);  // n must be a multiple of 3 for Simpson's 3/8 rule
    }
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        if (i % 3 == 0) {
            sum += 2 * f(a + i * h);
        } else {
            sum += 3 * f(a + i * h);
        }
    }
    return (3 * h / 8) * sum;
}

int main() {
    double a = 4.0;
    double b = 5.2;
    int n = 6;  // Number of subintervals

    double result_trapezoidal = trapezoidal(a, b, n);
    double result_simpsons_one_third = simpsons_one_third(a, b, n);
    double result_simpsons_three_eighth = simpsons_three_eighth(a, b, n);

    printf("Trapezoidal Rule: %.6f\n", result_trapezoidal);
    printf("Simpson's 1/3 Rule: %.6f\n", result_simpsons_one_third);
    printf("Simpson's 3/8 Rule: %.6f\n", result_simpsons_three_eighth);

    return 0;
}
