#include <stdio.h>
#include <stdlib.h>

void printMatrix(float a[20][20], int n){

    printf("Current Matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%0.5f\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

void gaussMethod(float a[20][20], int n){
    for(int i = 0; i < n; i++){
        if(a[i][i] == 0){
            printf("Mathematical error...\n");
            exit(0);
        }
        for(int j = i+1; j < n; j++){
            float x = a[j][i];
            for(int k  = 0; k < n+1; k++){
                a[j][k] = a[j][k] * a[i][i] - a[i][k] * x;
            }
        }
    }
    printMatrix(a, n);
}

void backSub(float a[20][20], float x[20], int n){
    x[n-1] = a[n-1][n] / a[n-1][n-1];
    for(int i = n-2; i>=0; i--){
        x[i] = a[i][n];
        for(int j = i+1; j < n; j++){
            x[i] -= x[j] * a[i][j];
        }
        x[i] = x[i]/a[i][i];
    }
}

int  main(){

    int n;
    float a[20][20], x[20];

    printf("Enter the number of unknowns: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix (coefficients and constants):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    printMatrix(a, n);
    gaussMethod(a, n);
    backSub(a, x, n);
    printf("Final Solution is\n");
    for(int i = 0; i < n; i++){
        printf("%0.5f\t", x[i]);
    }

    return(0);
}