#include <stdio.h>
#include <math.h>

int main() {
    // Given data
    int accidents[6] = {14, 18, 12, 11, 15, 14};
    int days = 6;
    double chi_square = 0.0;
    double expected_frequency;
    double table_value = 11.07; // Given table value for 5% significance level, 5 d.f.
    
    // Calculate total number of accidents
    int total_accidents = 0;
    for(int i = 0; i < days; i++) {
        total_accidents += accidents[i];
    }

    // Calculate expected frequency for uniform distribution
    expected_frequency = (double)total_accidents / days;

    // Calculate chi-square statistic
    for(int i = 0; i < days; i++) {
        chi_square += pow(accidents[i] - expected_frequency, 2) / expected_frequency;
    }

    // Output the result
    printf("Calculated Chi-Square value: %.2f\n", chi_square);
    printf("Table value for Chi-Square at 5%% level with 5 d.f.: %.2f\n", table_value);

    // Check if the calculated value is less than the table value
    if(chi_square < table_value) {
        printf("The accidents are uniformly distributed over the week.\n");
    } else {
        printf("The accidents are not uniformly distributed over the week.\n");
    }

    return 0;
}
