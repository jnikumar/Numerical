#include <stdio.h>

// Define the differential equation y' = y - 2xy
double f(double x, double y) {
    return y - 2 * x * y;
}

// Runge-Kutta 4th order method
void rungeKutta4(double x0, double y0, double h, double xn) {
    int n = (int)((xn - x0) / h);
    double k1, k2, k3, k4, k;
    double x = x0;
    double y = y0;

    printf("x\t\ty\n");
    printf("%.2f\t%.6f\n", x, y);

    for (int i = 0; i < n; i++) {
        k1 = h * f(x, y);
        k2 = h * f(x + h / 2.0, y + k1 / 2.0);
        k3 = h * f(x + h / 2.0, y + k2 / 2.0);
        k4 = h * f(x + h, y + k3);

        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;

        x = x + h;
        y = y + k;

        printf("%.2f\t%.6f\n", x, y);
    }
}

int main() {
    double x0 = 0.0;   // Initial x value
    double y0 = 1.0;   // Initial y value (y(0) = 1)
    double h = 0.2;    // Step size
    double xn = 2.0;   // Final x value

    rungeKutta4(x0, y0, h, xn);

    return 0;
}
