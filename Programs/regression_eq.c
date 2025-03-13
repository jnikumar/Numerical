#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of x values: ");
    scanf("%d", &n);

    double x_values[n];
    double y_values[n];

    printf("Enter values for sample x: \n");
    for(int i = 0; i < n; i++){
        printf("x[%d]: ", i);
        scanf("%lf", &x_values[i]);
    }

    printf("Enter values for sample y: \n");
    for(int i = 0; i < n; i++){
        printf("y[%d]: ", i);
        scanf("%lf", &y_values[i]);
    }

    double sumx2 = 0, sumx = 0, sumy = 0, sumxy = 0;
    for(int i = 0; i < n; i++){
        sumx += x_values[i];
        sumx2 += x_values[i] * x_values[i];

        sumy += y_values[i];
        sumxy += x_values[i] * y_values[i];
    }

    double sq_sumx = sumx * sumx;
    double a = ((n * sumxy) - (sumx * sumy)) / ((n * sumx2) - sq_sumx);
    double b = (sumy - a * sumx) / n;
    double c = 1 / a;
    double d = -b / a;

    printf("\nEquation 1: y = %8.5fx + %8.5f", a, b);
    printf("\nEquation 2: x = %8.5fy + %8.5f", c, d);

    return 0;
}

