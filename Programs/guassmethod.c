#include <stdio.h>
#include <stdlib.h>

// Function to perform Gauss Elimination
void gaussElimination(float a[][20], int n) {
    int i, j, k;
    float ratio;

    // Performing Gauss Elimination
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i][i] == 0) {
                printf("Mathematical Error!\n");
                exit(0);
            }
            ratio = a[j][i] / a[i][i];

            for (k = 0; k < n + 1; k++) {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }
}

// Function to perform Back Substitution
void backSubstitution(float a[][20], float x[], int n) {
    int i, j;
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];

    for (i = n - 2; i >= 0; i--) {
        x[i] = a[i][n];
        for (j = i + 1; j < n; j++) {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }
}

int main() {
    int n, i, j;
    float a[20][20], x[20];

    // Reading number of unknowns
    printf("Enter the number of unknowns: ");
    scanf("%d", &n);

    // Reading augmented matrix
    printf("Enter the augmented matrix (coefficients and constants):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    // Performing Gauss Elimination
    gaussElimination(a, n);

    // Performing Back Substitution
    backSubstitution(a, x, n);

    // Displaying solution
    printf("The solution is:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %0.3f\n", i, x[i]);
    }

    return 0;
}
