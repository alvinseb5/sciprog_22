#include <stdio.h>
#include <math.h>

int main(void)
{
    int N = 12, i;
    float a = 0.0, b = 60.0;
    float area, b_radian;
    
    //Coverting degree to radian
    b_radian = (M_PI * b)/180;
    printf("pi/3 in radian is = %f.\n",b_radian);
    
    //Computing area of tan(x) from a to b using trapezoidal rule
    //Sum of tan(a) + tan(b)
    area = tan(a) + tan(b_radian);
    
    //Sum of terms x1, x2, .. multiplied by x2
    for(i = 5; i < 60; i = i + 5){
        area = area + 2*tan((M_PI * i)/180);
    }
    
    //Multiplying it by (b-a)/2N
    area = area * b_radian/(2*N);
     
    //Compairng computed area with actual area
    printf("Computed area = %f, Actual area = %f.", area, log(2.0));
    
    // Here we see actual and computed area is approximately same.
    return 0;
}
