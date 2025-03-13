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

int main() {
    int n1, n2;
    double ftable;

    // Read the number of items in the sample1
    printf("Enter the number of items in the sample 1: ");
    scanf("%d", &n1);
    
    // Read the number of items in the sample2
    printf("Enter the number of items in the sample 2: ");
    scanf("%d", &n2);

    // Read the items in the sample 1
    double data1[n1];
    printf("Enter the items in the sample 1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%lf", &data1[i]);
    }
    
    // Read the items in the sample 1
    double data2[n2];
    printf("Enter the items in the sample 2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%lf", &data2[i]);
    }
    
    // Calculate the sample means
    double mean1 = calculate_mean(data1, n1);
    double mean2 = calculate_mean(data2, n2);

    // Calculate the sample standard deviations
    double sd1 = calculate_standard_deviation(data1, n1, mean1);
    double sd2 = calculate_standard_deviation(data2, n2, mean2);
    
    // Calculate the f-value
    double f_value = sd1 > sd2 ? (sd1/sd2) : (sd2/sd1);

    // Display the results
    printf("Calculated f-value: %.2f\n", f_value);

    printf("Enter the table value of f: ");
    scanf("%lf", &ftable);
    
    printf("\nDegrees of freedom: %d, %d\n", (n1-1), (n2-1));
    if(f_value > ftable){
        printf("\nNull hypothesis is rejected");
    }else{
        printf("\nNull hypothesis is accepted");
    }

    return 0;
}

