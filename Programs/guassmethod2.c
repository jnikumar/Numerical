#include <stdio.h>
#include <stdlib.h>

void printMatrix(float a[][20], int n) {
    int i, j;
    printf("Current matrix state:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            printf("%0.2f ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void gaussElimination(float a[][20], int n) {
    int i, j, k;
    float ratio;

    for (i = 0; i < n; i++) {
        // Ensure the diagonal element is non-zero
        if (a[i][i] == 0) {
            printf("Mathematical Error! Division by zero.\n");
            exit(0);
        }

        // Make the diagonal contain all 1s and make all elements below the diagonal 0
        for (j = i + 1; j < n; j++) {
            ratio = a[j][i] / a[i][i];
            for (k = i; k < n + 1; k++) {
                a[j][k] -= ratio * a[i][k];
            }
        }

        printMatrix(a, n);
    }
}

void backSubstitution(float a[][20], float x[], int n) {
    int i, j;

    // Start from the last row and work upwards
    for (i = n - 1; i >= 0; i--) {
        x[i] = a[i][n]; // Start with the last column value
        for (j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i]; // Divide by the diagonal element to get the result
        printf("Back substitution for x[%d] = %f\n", i, x[i]);
    }
}

int main() {
    int n, i, j;
    float a[20][20], x[20];

    printf("Enter the number of unknowns: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix (coefficients and constants):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    printMatrix(a, n);
    gaussElimination(a, n);
    backSubstitution(a, x, n);

    printf("The solution is:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %0.3f\n", i, x[i]);
    }

    return 0;
}
