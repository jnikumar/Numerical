#include <stdio.h>
#include <math.h>

// Recursive function to calculate the factorial of a number
int fact(int x){
    if (x == 0){
        return 1;  // Base case: 0! = 1
    } else {
        return x * fact(x - 1);  // Recursive case
    }
}

int main(){
    int n, i;

    float sum = 0, prod_x_y = 0; // Variables to store the sum of frequencies and weighted sum of values
    int x[10], y[10];            // Arrays to store event values (x) and their corresponding frequencies (y)
    float y1[10];                // Array to store expected frequencies based on the Poisson distribution
    float mean1, p0, p1, f1, f0; // Variables for mean, probabilities, and expected frequencies

    // Input: Number of data points
    printf("\nEnter the number of values: ");
    scanf("%d", &n);

    // Input: Event values (x)
    for(i = 0; i < n; i++){
        printf("\nx[%d]: ", i);
        scanf("%d", &x[i]);
    }

    // Input: Observed frequencies (y)
    printf("\nEnter the observed values: ");
    for(i = 0; i < n; i++){
        printf("\ny[%d]: ", i);
        scanf("%d", &y[i]);
    }
    
    // Calculate sum of frequencies and the weighted sum of event values
    for(i = 0; i < n; i++){
        sum += y[i];
        prod_x_y += x[i] * y[i];
    }

    // Output the sum of frequencies and the weighted sum of event values
    printf("\nsum = %f", sum);
    printf("\nproduct = %f", prod_x_y);

    // Calculate the weighted mean (mean1)
    mean1 = prod_x_y / sum;
    printf("\nmean = %f", mean1);

    // Calculate the probability of zero occurrences (p0)
    p0 = exp(-mean1);

    // Calculate the expected frequency of zero occurrences (f0)
    f0 = sum * p0;
    printf("\nExpected frequency for 0 events (f0) = %f", f0);

    // Output the expected frequency of each event value based on the Poisson distribution
    printf("\nExpected frequency y:");
    for(i = 0; i < n; i++){
        // Calculate the probability of observing 'i' events (p1)
        p1 = (p0 * pow(mean1, i)) / fact(i);

        // Calculate the expected frequency for 'i' events (f1)
        f1 = sum * p1;
        y1[i] = f1;

        // Output the expected frequency
        printf("\ny1[%d]: %.4f", i, y1[i]);
    }

    // Optional: Compare observed and expected frequency of zero events
    int observed_zero_freq = y[0]; // Assuming y[0] corresponds to frequency of 0 events
    printf("\nObserved frequency for 0 events: %d", observed_zero_freq);
    printf("\nExpected frequency for 0 events: %.4f", f0);

    return 0;
}
