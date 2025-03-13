#include <stdio.h>
#include <math.h>

int fact(int x){
    if (x == 0){
        return 1;
    }else{
        return x * fact(x-1);
    }
}

int main(){
    int n, i;

    float sum = 0, prod_x_y = 0;
    int x[10], y[10];
    float y1[10];
    float mean1, p0, p1, f1, f0;

    printf("\nEnter the number of values: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("\nx[%d]: ", i);
        scanf("%d", &x[i]);
    }

    printf("\nEnter the observed values: ");
    for(i = 0; i < n; i++){
        printf("\ny[%d]: ", i);
        scanf("%d", &y[i]);
    }
    
    for(i = 0; i < n; i++){
        sum += y[i];
        prod_x_y += x[i] * y[i];
    }

    printf("\nsum = %f", sum);
    printf("\nproduct = %f", prod_x_y);
    mean1 = prod_x_y / sum;
    printf("\nmean = %f", mean1);

    p0 = exp(-mean1);
    f0 = sum * p0;

    printf("\nExpected frequency y");
    for(i = 0; i < n; i++){
        p1 = (p0* pow(mean1, i))/fact(i);
        f1 = sum * p1;
        y1[i] = f1;
        printf("\cy1[%d]: ", i);
        printf("%.4f", y1[i]);
    }
}