#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 10

int main()
{
    printf("Hello, World!\n");

    float a[SIZE][SIZE], x[SIZE], ratio;
    int i, j, k, n;
    
    /*reading the number of unknowns*/
    printf("Enter the number of unknowns: ");
    scanf("%d", &n);
    
    /*read the augmented matrix*/
    printf("Enter the elements of the augmented matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j <= n; j++){
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    
    /*apply the Gauss elimination method*/
    for(i = 0; i < n-1; i++){
        if(a[i][i] == 0){
            printf("Mathematical Error");
            exit(0);
        }
        for(j = i+1; j < n; j++){
            ratio = a[j][i] / a[i][i];
            for(k = 0; k <= n; k++){
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }
    
    /*obtain the solution by back substitution*/
    x[n-1] = a[n-1][n] / a[n-1][n-1];
    for(i = n-2; i >= 0; i--){
        x[i] = a[i][n];
        for(j = i+1; j < n; j++){
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }
    
    /*print the solution*/
    printf("The solution is:\n");
    for(i = 0; i < n; i++){
        printf("x[%d] = %0.3f\n", i, x[i]);
    }
    
    return 0;
}
