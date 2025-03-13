// lagrange Interpolation

#include <stdio.h>

int main() {
    // Write C code here
    printf("Lagrange Interpolation\n");
    printf("Enter the number of values: ");
    int n;
    scanf("%d", &n);
    
    double x_vals[n], y_vals[n];
    printf("\nEnter x values:\n");
    for(int i = 0; i < n; i++){
        printf("x[%d]: ", i);
        scanf("%lf", &x_vals[i]);
    }
     printf("\nEnter y values:\n");
    for(int i = 0; i < n; i++){
        printf("y[%d]: ", i);
        scanf("%lf", &y_vals[i]);
    }
    
    double x_p;
    printf("\nEnter the interpolation point (x_p): ");
    scanf("%lf", &x_p);
    
    double y_p = 0;
    for(int i = 0; i < n; i++){
        double prod = 1;
        for(int j = 0; j < n; j++){
            if(i != j){
                prod = prod * ((x_p - x_vals[j]) / (x_vals[i] - x_vals[j]));
            }
        }
        y_p = y_p + (prod * y_vals[i]);
    }
    printf("Interpolated value at %.5lf is %.5lf\n", x_p, y_p);

    return 0;
}