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
    int n = 4; // Number of data points

    float x[] = {5, 6, 9, 11};
    float y[] = {12, 13, 14, 16};

    float xp = 10; // The point at which interpolation is required

    // Call the interpolation function and display the result
    float yp = lagrangeInterpolation(x, y, n, xp);
    printf("Interpolated value at x = %.5f is y = %.5f\n", xp, yp);

    return 0;
}