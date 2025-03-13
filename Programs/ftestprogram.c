#include <stdio.h>
#include <math.h>

int main() {
    int n1, n2;
    
    // Read sizes of the populations
    printf("Enter the size of the first population: ");
    scanf("%d", &n1);
    printf("Enter the size of the second population: ");
    scanf("%d", &n2);
    
    // Arrays to hold the population values
    double population1[n1], population2[n2];
    
    // Read values for the first population
    printf("Enter values for the first population:\n");
    double sum1 = 0.0, mean1, variance1 = 0.0, sd1;
    for (int i = 0; i < n1; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%lf", &population1[i]);
        sum1 += population1[i];
    }
    mean1 = sum1 / n1;
    
    // Calculate variance and standard deviation for the first population
    for (int i = 0; i < n1; i++) {
        variance1 += (population1[i] - mean1) * (population1[i] - mean1);
    }
    variance1 /= (n1 - 1); // Sample variance
    sd1 = sqrt(variance1);
    
    // Read values for the second population
    printf("Enter values for the second population:\n");
    double sum2 = 0.0, mean2, variance2 = 0.0, sd2;
    for (int i = 0; i < n2; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%lf", &population2[i]);
        sum2 += population2[i];
    }
    mean2 = sum2 / n2;
    
    // Calculate variance and standard deviation for the second population
    for (int i = 0; i < n2; i++) {
        variance2 += (population2[i] - mean2) * (population2[i] - mean2);
    }
    variance2 /= (n2 - 1); // Sample variance
    sd2 = sqrt(variance2);
    
    // Calculate F-test statistic
    double fTest;
    if (variance1 > variance2) {
        fTest = variance1 / variance2;
    } else {
        fTest = variance2 / variance1;
    }

    // Display results
    printf("\nPopulation 1:\n");
    printf("Mean: %.2lf\n", mean1);
    printf("Variance: %.2lf\n", variance1);
    printf("Standard Deviation: %.2lf\n", sd1);

    printf("\nPopulation 2:\n");
    printf("Mean: %.2lf\n", mean2);
    printf("Variance: %.2lf\n", variance2);
    printf("Standard Deviation: %.2lf\n", sd2);

    printf("\nF-test statistic: %.2lf\n", fTest);

    // Recommendation based on F-test statistic and critical value
    double criticalValue; // Critical value for F(8,7) at 0.05 significance level
    printf("Enter the table value of f: ");
    scanf("%lf", &criticalValue);
    printf("The calculated value of f: %0.3f\n", fTest);
    
    if (fTest > criticalValue) {
        printf("Reject the null hypothesis: The variances are significantly different at the 0.05 significance level.\n");
    } else {
        printf("Fail to reject the null hypothesis: The variances are not significantly different at the 0.05 significance level.\n");
    }
    
    return 0;
}
