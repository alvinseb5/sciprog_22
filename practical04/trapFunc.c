#include <stdio.h>
#include <math.h>

//funtion declarations
float deg_to_rad(float theta);
float trapezoid_rule_area(int N);

//global variable
float tan_arr[13];

int main(void)
{
    int N = 12, i;
    float a_deg = 0.0, b_deg = 60.0;
    float step_size = (b_deg - a_deg)/N;
    float area;
    
    //tan array
    for(i = 0; i <= N; i++){
        tan_arr[i] = tan(deg_to_rad(step_size*i));
    }
    
    //printing array
    for(i = 0; i <= N; i++){
        printf("tan array element %d is:%f.\n",i+1,tan_arr[i]);
    }
  
    //Computing area of tan(x) from a to b using trapezoidal rule funtion
    area = trapezoid_rule_area(N);
    
    //Compairng computed area with actual area
    printf("Computed area = %f, Actual area = %f.", area, log(2.0));
    
    // Here we see actual and computed area is approximately same.
    return 0;
}

//funtion to convert degree to radians
float deg_to_rad(float theta){
    return (M_PI*theta)/180;
}

//funtion to compute area using trapezoidal rule
float trapezoid_rule_area(int N){
    float area;
    //Computing area from a to b using trapezoidal rule
    //Sum of first and last term
    area = tan_arr[0] + tan_arr[N];
    
    //Sum of terms x1, x2, .. multiplied by x2
    int i = 0;
    for(i = 1; i < N; i++){
        area = area + 2*tan_arr[i];
    }
    
    //Multiplying it by (b-a)/2N
    area = area * ((deg_to_rad(60.0) - deg_to_rad(0.0))/(2*N));
    
    return area;
}
