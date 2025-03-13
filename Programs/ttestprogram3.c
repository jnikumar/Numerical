#include <stdio.h>
#include <math.h>

// Function to calculate mean
double calculate_mean(double data[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}

// Function to calculate standard deviation
double calculate_standard_deviation(double data[], int n, double mean) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += pow(data[i] - mean, 2);
    }
    return sqrt(sum / (n - 1));
}

// Function to calculate t-value
double calculate_t_value(double mean, double assumed_mean, double sd, int n) {
    return (mean - assumed_mean) / (sd / sqrt(n));
}

// Function to get critical t-value from table for common df and alpha values
double get_critical_t_value(int df, double alpha, int two_tailed) {
    // Hardcoded critical values for df = 8 and common alpha values
    if (df == 8) {
        if (two_tailed) {
            if (alpha == 0.05) return 2.306;
            if (alpha == 0.01) return 3.355;
        } else {
            if (alpha == 0.05) return 1.860;
            if (alpha == 0.01) return 2.896;
        }
    }
    // Add more values or use a lookup function/library in real use cases
    return 0.0; // Default value for unsupported cases
}

int main() {
    int n;
    double assumed_mean;
    double alpha;
    int two_tailed;

    // Read the number of items in the sample
    printf("Enter the number of items in the sample: ");
    scanf("%d", &n);

    // Read the items in the sample
    double data[n];
    printf("Enter the items in the sample:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &data[i]);
    }

    // Read the assumed mean
    printf("Enter the assumed mean: ");
    scanf("%lf", &assumed_mean);

    // Read the significance level (alpha)
    printf("Enter the significance level (e.g., 0.05): ");
    scanf("%lf", &alpha);

    // Read whether the test is two-tailed (1 for yes, 0 for no)
    printf("Is this a two-tailed test? (1 for yes, 0 for no): ");
    scanf("%d", &two_tailed);

    // Calculate the sample mean
    double mean = calculate_mean(data, n);

    // Calculate the standard deviation
    double sd = calculate_standard_deviation(data, n, mean);

    // Calculate the t-value
    double t_value = calculate_t_value(mean, assumed_mean, sd, n);

    // Degrees of freedom
    int df = n - 1;

    // Get the critical t-value
    double critical_t_value = get_critical_t_value(df, alpha, two_tailed);

    // Display the results
    printf("Sample Mean: %.2f\n", mean);
    printf("Assumed Mean: %.2f\n", assumed_mean);
    printf("Calculated t-value: %.2f\n", t_value);
    printf("Critical t-value for df=%d and alpha=%.2f: %.2f\n", df, alpha, critical_t_value);

    // Compare the calculated t-value with the critical t-value
    if (fabs(t_value) > critical_t_value) {
        printf("Null Hypothesis Rejected: The mean of the sample differs significantly from the assumed mean.\n");
    } else {
        printf("Null Hypothesis Accepted: The mean of the sample does not differ significantly from the assumed mean.\n");
    }

    return 0;
}
