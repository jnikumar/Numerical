#include <stdio.h>
#include <math.h>

int main()
{
    int i, n;
    float x[20], sum = 0, sum1=0, xbar, ttab, tcal, mu,se;
    
    printf("Enter the population mean: ");
    scanf("%f", &mu);
    printf("Enter the sample size : ");
    scanf("%d",&n);
    printf("Enter the sample values: ");
    for(i=0; i < n; i++){
        scanf("%f",&x[i]);
        sum=sum+x[i];
    }
    
    printf("%f", sum);
    
    xbar=sum/n;
    printf("Mean of Sample: \n%f", xbar);
    
    //calculate standard deviation
    for(i=0; i < n; i++){
        sum1=sum1+(x[i]-xbar)* (x[i]-xbar);
    }
    se=sqrt(sum1/(n-1));

    //calculate t-value
    tcal =fabs((xbar-mu)/(se/sqrt(n-1)));

    printf("\nEnter the t-table value: ");
    scanf("%f", &ttab);

    printf("Results: \n");
    printf("tcal=%f \n tab=%f \n df=%d \n los = 0.05\n", tcal,ttab,n-1);
    if (tcal < ttab){
        printf("\nAccept Null hypothesis H0, The given samples drawn from the assumed population of mean %f", mu);
    }else{
        printf("\nReject the null hypotheses H0 , the given samples are not drawn from the assumed population of mean value %f", mu);
    }
    
    return 0;
}