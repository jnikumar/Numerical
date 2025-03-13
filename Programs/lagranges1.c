#include <stdio.h>

// Function to perform Lagrange's interpolation
float lagrangeInterpolation(float x[], float y[], int n, float xp) {
    float yp = 0; // Resulting interpolated value
    for (int i = 0; i < n; i++) {
        float term = y[i]; // Initialize the term to be added
        for (int j = 0; j < n; j++) {
            if (j != i) {
                // Calculate the individual terms of the product
                term = term * (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp += term; // Add the term to the final result
    }
    return yp; // Return the interpolated value
}

int main() {
    int n; // Number of data points

    // Prompt the user to enter the number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n]; // Arrays to hold the x and y values

    // Read the x data points from the user
    printf("Enter the x data points:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
    }

    // Read the y data points from the user
    printf("Enter the y data points:\n");
    for (int i = 0; i < n; i++) {
        printf("y[%d]: ", i);
        scanf("%f", &y[i]);
    }

    float xp; // The point at which interpolation is required
    // Prompt the user to enter the value of xp
    printf("Enter the value of x to find the corresponding y: ");
    scanf("%f", &xp);

    // Call the interpolation function and display the result
    float yp = lagrangeInterpolation(x, y, n, xp);
    printf("Interpolated value at x = %.3f is y = %.3f\n", xp, yp);

    return 0;
}
