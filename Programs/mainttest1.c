#include <stdio.h>
#include <math.h>

int main()
{
    int i, n;
    float x[20], sum = 0, sum1 = 0, xbar, ttab, tcal, mu, sd, se;

    printf("Enter the population mean: ");
    scanf("%f", &mu);
    printf("Enter the sample size : ");
    scanf("%d", &n);

    // Check if sample size is within valid range
    if (n <= 0 || n > 20) {
        printf("Sample size must be between 1 and 20.\n");
        return 1;
    }

    printf("Enter the sample values: ");
    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
        sum = sum + x[i];
    }

    xbar = sum / n;
    printf("Sample mean (xbar): %f\n", xbar);

    for (i = 0; i < n; i++) {
        sum1 = sum1 + (x[i] - xbar) * (x[i] - xbar);
    }

    sd = sqrt(sum1 / (n - 1));  // Sample standard deviation
    se = sd / sqrt(n);  // Standard error

    tcal = fabs((xbar - mu) / se);  // Correct formula for t-statistic
    printf("Enter the t-table value: ");
    scanf("%f", &ttab);

    printf("Results: \n");
    printf("tcal = %f\n", tcal);
    printf("ttab = %f\n", ttab);
    printf("Degrees of freedom (df) = %d\n", n - 1);
    printf("Level of significance (los) = 0.05\n");

    if (tcal < ttab) {
        printf("\nAccept Null hypothesis H0, The given samples are drawn from the assumed population with mean %f\n", mu);
    } else {
        printf("\nReject the Null hypothesis H0, The given samples are not drawn from the assumed population with mean value %f\n", mu);
    }

    return 0;
}
