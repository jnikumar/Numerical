#include <stdio.h>
#include <math.h>

int main() {
    // Number of days
    int days = 6;
    
    // Observed frequencies
    int observed[] = {14, 18, 12, 11, 15, 14};
    
    // Total number of accidents
    int total_accidents = 0;
    for (int i = 0; i < days; i++) {
        total_accidents += observed[i];
    }
    
    // Expected frequency for each day (assuming uniform distribution)
    double expected = (double)total_accidents / days;
    
    // Calculate chi-square statistic
    double chi_square = 0.0;
    for (int i = 0; i < days; i++) {
        chi_square += pow((observed[i] - expected), 2) / expected;
    }
    
    // Degrees of freedom
    int degrees_of_freedom = days - 1;
    
    // Chi-square critical value for 5% significance level and 5 degrees of freedom
    double chi_square_critical = 11.07;

    // Print results
    printf("Chi-square statistic: %.2f\n", chi_square);
    printf("Chi-square critical value (5%% level, %d d.f.): %.2f\n", degrees_of_freedom, chi_square_critical);

    // Compare calculated chi-square value with critical value
    if (chi_square > chi_square_critical) {
        printf("Reject the null hypothesis. The accidents are not uniformly distributed over the week.\n");
    } else {
        printf("Fail to reject the null hypothesis. The accidents are uniformly distributed over the week.\n");
    }

    return 0;
}
